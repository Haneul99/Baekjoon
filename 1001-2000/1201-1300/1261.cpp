#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>

using namespace std;

int n, m;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int MAZE[110][110] = { 0, };
int CHECK[110][110];

void BFS() {
	//x : m, y : n
	deque<pair<int,int>> dq;
	dq.push_front({ 1,1 });
	CHECK[1][1] = 0;
	while (!dq.empty()) {
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//0은 빈방 1은 벽
			if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
			if (CHECK[nx][ny] != -1) continue;
			if (MAZE[nx][ny] == 0) {
				dq.push_front({ nx, ny });
				CHECK[nx][ny] = CHECK[x][y];
			}
			else {
				dq.push_back({ nx, ny });
				CHECK[nx][ny] = CHECK[x][y] + 1;
			}
			if (nx == m && ny == n) return;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			MAZE[i][j+1] = s[j] - '0';
		}
	}
	
	memset(CHECK, -1, sizeof(CHECK));

	BFS();
	cout << CHECK[m][n] << '\n';
}


/*
1261. 알고스팟
https://www.acmicpc.net/problem/1261

문제
알고스팟 운영진이 모두 미로에 갇혔다. 미로는 N*M 크기이며, 총 1*1크기의 방으로 이루어져 있다. 미로는 빈 방 또는 벽으로 이루어져 있고, 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.

알고스팟 운영진은 여러명이지만, 항상 모두 같은 방에 있어야 한다. 즉, 여러 명이 다른 방에 있을 수는 없다. 어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다. 즉, 현재 운영진이 (x, y)에 있을 때, 이동할 수 있는 방은 (x+1, y), (x, y+1), (x-1, y), (x, y-1) 이다. 단, 미로의 밖으로 이동 할 수는 없다.

벽은 평소에는 이동할 수 없지만, 알고스팟의 무기 AOJ를 이용해 벽을 부수어 버릴 수 있다. 벽을 부수면, 빈 방과 동일한 방으로 변한다.

만약 이 문제가 알고스팟에 있다면, 운영진들은 궁극의 무기 sudo를 이용해 벽을 한 번에 다 없애버릴 수 있지만, 안타깝게도 이 문제는 Baekjoon Online Judge에 수록되어 있기 때문에, sudo를 사용할 수 없다.

현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다. 0은 빈 방을 의미하고, 1은 벽을 의미한다.

(1, 1)과 (N, M)은 항상 뚫려있다.

출력
첫째 줄에 알고스팟 운영진이 (N, M)으로 이동하기 위해 벽을 최소 몇 개 부수어야 하는지 출력한다.


MAP 바깥 아니면 그냥 무조건 이동하는데, 벽을 부수는 경우라면 +1을 함.
이것도 가중치가 있는 BFS라고 생각하고, 벽을 부수지 않는 경우라면 deque의 맨 앞에 삽입 & 방문 체크
해당 맵에 벽을 최대한 적게 부술 수 있는 수를 기록
*/