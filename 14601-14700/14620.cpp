#include<stdio.h>
#include<limits.h>

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int flower[11][11] = { 0, };
int visit[11][11] = { 0, };
int n;
int min = INT_MAX;

typedef struct xy {
	int x, y;
}xy;

int check(int x, int y) {
	if (visit[x][y]) {
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || visit[nx][ny]) {
			return 0;
		}
	}
	return 1;
}


void dfs(int depth, int sum, int idx) {
	if (depth == 3) {
		if (min > sum) {
			min = sum;
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check(i, j)) continue;

			int cost = flower[i][j];

			visit[i][j] = 1;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				visit[nx][ny] = 1;
				cost += flower[nx][ny];
			}

			dfs(depth + 1, sum + cost, i);

			visit[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				visit[nx][ny] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &flower[i][j]);
		}
	}
	dfs(0, 0, 1);
	printf("%d\n", min);
}



                                                 
/*
14620. 꽃길
https://www.acmicpc.net/problem/14620

문제
2017년 4월 5일 식목일을 맞이한 진아는 나무를 심는 대신 하이테크관 앞 화단에 꽃을 심어 등교할 때 마다 꽃길을 걷고 싶었다.

진아가 가진 꽃의 씨앗은 꽃을 심고나면 정확히 1년후에 꽃이 피므로 진아는 다음해 식목일 부터 꽃길을 걸을 수 있다.

하지만 진아에게는 꽃의 씨앗이 세개밖에 없었으므로 세 개의 꽃이 하나도 죽지 않고 1년후에 꽃잎이 만개하길 원한다.

꽃밭은 N*N의 격자 모양이고 진아는 씨앗을 (1,1)~(N,N)의 지점 중 한곳에 심을 수 있다. 꽃의 씨앗은 그림 (a)처럼 심어지며 1년 후 꽃이 피면 그림 (b)모양이 된다.



꽃을 심을 때는 주의할 점이있다. 어떤 씨앗이 꽃이 핀 뒤 다른 꽃잎(혹은 꽃술)과 닿게 될 경우 두 꽃 모두 죽어버린다. 또 화단 밖으로 꽃잎이 나가게 된다면 그 꽃은 죽어버리고 만다.



그림(c)는 세 꽃이 정상적으로 핀 모양이고 그림(d)는 두 꽃이 죽어버린 모양이다.

하이테크 앞 화단의 대여 가격은 격자의 한 점마다 다르기 때문에 진아는 서로 다른 세 씨앗을 모두 꽃이 피게하면서 가장 싼 가격에 화단을 대여하고 싶다.

단 화단을 대여할 때는 꽃잎이 핀 모양을 기준으로 대여를 해야하므로 꽃 하나당 5평의 땅을 대여해야만 한다.

돈이 많지 않은 진아를 위하여 진아가 꽃을 심기 위해 필요한 최소비용을 구해주자!

입력
입력의 첫째 줄에 화단의 한 변의 길이 N(6≤N≤10)이 들어온다.

이후 N개의 줄에 N개씩 화단의 지점당 가격(0≤G≤200)이 주어진다.

출력
꽃을 심기 위한 최소 비용을 출력한다.



조건을 만족하는 경우에만 dfs를 해당 위치에 꽃 심기. 3개를 심었을 때 cost를 확인하고 최솟값 갱신
*/                      