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


int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int ddx[4] = { -1, -1, 1, 1 };
int ddy[4] = { -1, 1, 1, -1 };

int N, M;
int MAP[MAX][MAX];
int CLOUDHISTORY[MAX][MAX];

vector<pair<int, int>>clouds = { {N,1}, {N,2}, {N - 1, 1}, {N - 1, 2} };

void rainy() {
	for (int i = 0; i < clouds.size(); i++) {
		int x = clouds[i].first;
		int y = clouds[i].second;
		MAP[x][y]++;
	}
	for (int i = 0; i < clouds.size(); i++) {
		int x = clouds[i].first;
		int y = clouds[i].second;
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + ddx[j];
			int ny = y + ddy[j];
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (MAP[nx][ny] > 0) cnt++;
		}
		MAP[x][y] += cnt;
	}
}

void moveCloud(int dir, int s) {
	for (int i = 0; i < clouds.size(); i++) {
		int x = clouds[i].first;
		int y = clouds[i].second;

		int nx = x + dx[dir] * s;
		int ny = y + dy[dir] * s;

		clouds[i].first = nx;
		clouds[i].second = ny;
	}
}

void makeClouds() {
	for (int i = 0; i < clouds.size(); i++) {
		int x = clouds[i].first;
		int y = clouds[i].second;
		CLOUDHISTORY[x][y] = 1;
	}
	clouds.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] >= 2 && CLOUDHISTORY[i][j] == 0) {
				clouds.push_back({ i,j });
				MAP[i][j] -= 2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int dir, s; cin >> dir >> s;
		moveCloud(dir, s);
		rainy();
		memset(CLOUDHISTORY, 0, sizeof(CLOUDHISTORY));
		makeClouds();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += MAP[i][j];
		}
	}
	cout << ans << '\n';
}


/*
21610. 마법사 상어와 비바라기
https://www.acmicpc.net/problem/21610

문제
마법사 상어는 파이어볼, 토네이도, 파이어스톰, 물복사버그 마법을 할 수 있다. 오늘 새로 배운 마법은 비바라기이다. 비바라기를 시전하면 하늘에 비구름을 만들 수 있다. 오늘은 비바라기를 크기가 N×N인 격자에서 연습하려고 한다. 격자의 각 칸에는 바구니가 하나 있고, 바구니는 칸 전체를 차지한다. 바구니에 저장할 수 있는 물의 양에는 제한이 없다. (r, c)는 격자의 r행 c열에 있는 바구니를 의미하고, A[r][c]는 (r, c)에 있는 바구니에 저장되어 있는 물의 양을 의미한다.

격자의 가장 왼쪽 윗 칸은 (1, 1)이고, 가장 오른쪽 아랫 칸은 (N, N)이다. 마법사 상어는 연습을 위해 1번 행과 N번 행을 연결했고, 1번 열과 N번 열도 연결했다. 즉, N번 행의 아래에는 1번 행이, 1번 행의 위에는 N번 행이 있고, 1번 열의 왼쪽에는 N번 열이, N번 열의 오른쪽에는 1번 열이 있다.

비바라기를 시전하면 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다. 구름은 칸 전체를 차지한다. 이제 구름에 이동을 M번 명령하려고 한다. i번째 이동 명령은 방향 di과 거리 si로 이루어져 있다. 방향은 총 8개의 방향이 있으며, 8개의 정수로 표현한다. 1부터 순서대로 ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 이다. 이동을 명령하면 다음이 순서대로 진행된다.

모든 구름이 di 방향으로 si칸 이동한다.
각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
구름이 모두 사라진다.
2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
예를 들어, (N, 2)에서 인접한 대각선 칸은 (N-1, 1), (N-1, 3)이고, (N, N)에서 인접한 대각선 칸은 (N-1, N-1)뿐이다.
바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
M번의 이동이 모두 끝난 후 바구니에 들어있는 물의 양의 합을 구해보자.

입력
첫째 줄에 N, M이 주어진다.

둘째 줄부터 N개의 줄에는 N개의 정수가 주어진다. r번째 행의 c번째 정수는 A[r][c]를 의미한다.

다음 M개의 줄에는 이동의 정보 di, si가 순서대로 한 줄에 하나씩 주어진다.

출력
첫째 줄에 M번의 이동이 모두 끝난 후 바구니에 들어있는 물의 양의 합을 출력한다.

구름을 이동하는 것에 주의할 점이 많았음.
그리고 비 왔을 때 비 먼저 내리고 대각선 바구니 봐야 함.

(1,1) . . . . . . (N,1) .
.
.
.
.
.
(N-1, 1) (N-2,2)           (N,N-1)  
(N  , 1) (N,  2) . . . . . . . (N,N)
*/