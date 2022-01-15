#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

char map[101][101];
int visit[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;

int check(int x, int y) {
	if (x > 0 && x <= n && y > 0 && y <= m) return 1;
	else return 0;
}

int BFS(int x, int y) {
	int cnt = 0;
	queue< pair<int, int> > q;
	q.push({ x,y });
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (!visit[nx][ny] && (map[nx][ny] == map[p.first][p.second]) && check(nx, ny)) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}

	return cnt;
}


int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	int cnt_B = 0;
	int cnt_W = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j]) {
				visit[i][j] = 1;
				int x = BFS(i, j);
				if (map[i][j] == 'B') {
					cnt_B += x * x;
				}
				else {
					cnt_W += x * x;
				}
			}
		}
	}
	printf("%d %d\n", cnt_W, cnt_B);
}



/*
1303. 전쟁 - 전투
https://www.acmicpc.net/problem/1303

문제
전쟁은 어느덧 전면전이 시작되었다. 결국 전투는 난전이 되었고, 우리 병사와 적국 병사가 섞여 싸우게 되었다.

그러나 당신의 병사들은 하얀 옷을 입고, 적국의 병사들은 파란옷을 입었기 때문에 서로가 적인지 아군인지는 구분할 수 있다.

문제는, 같은 팀의 병사들은 모이면 모일수록 강해진다는 사실이다.

N명이 뭉쳐있을 때는 N^2의 위력을 낼 수 있다. 과연 지금 난전의 상황에서는 누가 승리할 것인가? 단, 같은 팀의 병사들이 대각선으로만 인접한 경우는 뭉쳐 있다고 보지 않는다.

입력
첫째 줄에는 전쟁터의 가로 크기 N, 세로 크기 M(1 ≤ N, M ≤ 100)이 주어진다. 그 다음 두 번째 줄에서 M+1번째 줄에는 각각 (X, Y)에 있는 병사들의 옷색이 띄어쓰기 없이 주어진다. 모든 자리에는 병사가 한 명 있다. (B는 파랑, W는 흰색이다.)

출력
첫 번째 줄에 당신의 병사의 위력의 합과 적국의 병사의 위력의 합을 출력한다.

*/
