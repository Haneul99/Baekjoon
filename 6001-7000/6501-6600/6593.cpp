#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 32

using namespace std;

int dx[6] = { 0, 0, 1,-1, 0, 0 };
int dy[6] = { 0, 0, 0, 0, 1, -1 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

char building[MAX][MAX][MAX];
pair<int, pair<int, int>> src;

int L, R, C;

int BFS() {
	int CHECK[MAX][MAX][MAX] = { 0, };
	queue < pair<int, pair<int, int>>> q;
	q.push({ src.first, {src.second.first, src.second.second} });
	CHECK[src.first][src.second.first][src.second.second] = 1;
	while (!q.empty()) {
		int x, y, z;
		x = q.front().first;
		y = q.front().second.first;
		z = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx > L - 1 || ny < 0 || ny > R - 1 || nz < 0 || nz > C - 1) continue;
			if (CHECK[nx][ny][nz] != 0 || building[nx][ny][nz] == '#') continue;

			if (building[nx][ny][nz] == 'E') {
				return CHECK[x][y][z];
			}
			CHECK[nx][ny][nz] = CHECK[x][y][z] + 1;
			q.push({ nx, {ny,nz} });
		}
	}
	return -1;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) {
			break;
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') src = { i,{j,k} };
				}
			}
		}

		int ans = BFS();
		if (ans == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << ans << " minute(s).\n";
		}
	}
}


/*
6593. 상범 빌딩
https://www.acmicpc.net/problem/6593

문제
당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.

당신은 상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까?

입력
입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 케이스는 세 개의 정수 L, R, C로 시작한다. L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수이다. R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.

그 다음 각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다. 각 문자는 상범 빌딩의 한 칸을 나타낸다. 금으로 막혀있어 지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 표현된다. 당신의 시작 지점은 'S'로 표현되고, 탈출할 수 있는 출구는 'E'로 표현된다. 각 층 사이에는 빈 줄이 있으며, 입력의 끝은 L, R, C가 모두 0으로 표현된다. 시작 지점과 출구는 항상 하나만 있다.

출력
각 빌딩에 대해 한 줄씩 답을 출력한다. 만약 당신이 탈출할 수 있다면 다음과 같이 출력한다.

Escaped in x minute(s).
여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.

만일 탈출이 불가능하다면, 다음과 같이 출력한다.

Trapped!
*/