#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>

#define MAX 102

using namespace std;

int N, M, K;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int path[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { 0, };

int BFS(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visit[r][c] = true;

	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (visit[nx][ny]) continue;
			if (path[nx][ny] == 0) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	 cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int x, y; cin >> x >> y;
		path[x][y] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (path[i][j] == 1 && visit[i][j] == false) {
				ans = max(ans, BFS(i, j));
			}
		}
	}
	cout << ans << '\n';
}


/*
1743. 음식물 피하기
https://www.acmicpc.net/problem/1743

문제
코레스코 콘도미니엄 8층은 학생들이 3끼의 식사를 해결하는 공간이다. 그러나 몇몇 비양심적인 학생들의 만행으로 음식물이 통로 중간 중간에 떨어져 있다. 이러한 음식물들은 근처에 있는 것끼리 뭉치게 돼서 큰 음식물 쓰레기가 된다.

이 문제를 출제한 선생님은 개인적으로 이러한 음식물을 실내화에 묻히는 것을 정말 진정으로 싫어한다. 참고로 우리가 구해야 할 답은 이 문제를 낸 조교를 맞추는 것이 아니다.

통로에 떨어진 음식물을 피해가기란 쉬운 일이 아니다. 따라서 선생님은 떨어진 음식물 중에 제일 큰 음식물만은 피해 가려고 한다.

선생님을 도와 제일 큰 음식물의 크기를 구해서 “10ra"를 외치지 않게 도와주자.

입력
첫째 줄에 통로의 세로 길이 N(1 ≤ N ≤ 100)과 가로 길이 M(1 ≤ M ≤ 100) 그리고 음식물 쓰레기의 개수 K(1 ≤ K ≤ N×M)이 주어진다.  그리고 다음 K개의 줄에 음식물이 떨어진 좌표 (r, c)가 주어진다.

좌표 (r, c)의 r은 위에서부터, c는 왼쪽에서부터가 기준이다. 입력으로 주어지는 좌표는 중복되지 않는다.

출력
첫째 줄에 음식물 중 가장 큰 음식물의 크기를 출력하라.
*/ 