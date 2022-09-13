#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 52

using namespace std;

int N, M, virusCnt, ans = 1234567890;

int MAP[MAX][MAX] = { 0, };
vector<pair<int,int>> virus;
vector<pair<int, int>> selected;
int visit[MAX][MAX] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == 1) continue;
			if (!visit[i][j]) return false;
		}
	}
	return true;
}

void BFS() {
	queue<pair<int, int>>q;
	for (int i = 0; i < M; i++) {
		q.push({ selected[i] });
		visit[selected[i].first][selected[i].second] = 1;
	}

	int cnt = 0;
	while (!q.empty()) {
		int qsize = q.size();	
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				if (visit[nx][ny] == 1 || MAP[nx][ny] == 1) continue;
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
		if (q.size() != 0) cnt++;
	}
	if (check()) {
		ans = min(ans, cnt);
	}
}

void getComb(int idx, int depth) {
	if (depth == M) {
		memset(visit, false, sizeof(visit));
		BFS();
		return;
	}

	for (int i = idx + 1; i < virusCnt; i++) {
		selected.push_back({ virus[i] });
		getComb(i, depth + 1);
		selected.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}

	virusCnt = virus.size();
	getComb(-1, 0);
	if (ans == 1234567890) cout << "-1\n";
	else cout << ans << '\n';
}


/*
17141. 연구소 2
https://www.acmicpc.net/problem/17141

문제
인체에 치명적인 바이러스를 연구하던 연구소에 승원이가 침입했고, 바이러스를 유출하려고 한다. 승원이는 연구소의 특정 위치에 바이러스 M개를 놓을 것이고, 승원이의 신호와 동시에 바이러스는 퍼지게 된다.

연구소는 크기가 N×N인 정사각형으로 나타낼 수 있으며, 정사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.

일부 빈 칸은 바이러스를 놓을 수 있는 칸이다. 바이러스는 상하좌우로 인접한 모든 빈 칸으로 동시에 복제되며, 1초가 걸린다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸이다.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 0 0 2
M = 3이고, 바이러스를 아래와 같이 놓은 경우 6초면 모든 칸에 바이러스를 퍼뜨릴 수 있다. 벽은 -, 바이러스를 놓은 위치는 0, 빈 칸은 바이러스가 퍼지는 시간으로 표시했다.

6 6 5 4 - - 2
5 6 - 3 - 0 1
4 - - 2 - 1 2
3 - 2 1 2 2 3
2 2 1 0 1 - -
1 - 2 1 2 3 4
0 - 3 2 3 4 5
시간이 최소가 되는 방법은 아래와 같고, 5초만에 모든 칸에 바이러스를 퍼뜨릴 수 있다.

0 1 2 3 - - 2
1 2 - 3 - 0 1
2 - - 2 - 1 2
3 - 2 1 2 2 3
3 2 1 0 1 - -
4 - 2 1 2 3 4
5 - 3 2 3 4 5
연구소의 상태가 주어졌을 때, 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간을 구해보자.

입력
첫째 줄에 연구소의 크기 N(5 ≤ N ≤ 50), 놓을 수 있는 바이러스의 개수 M(1 ≤ M ≤ 10)이 주어진다.

둘째 줄부터 N개의 줄에 연구소의 상태가 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸이다. 2의 개수는 M보다 크거나 같고, 10보다 작거나 같은 자연수이다.

출력
연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다. 바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 -1을 출력한다.
*/