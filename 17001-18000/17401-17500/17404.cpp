#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 1010

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, ans = 1234567890; cin >> N;

	
	int cost[MAX][3] = { 0, };
	for (int i = 1; i <= N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int start = 0; start < 3; start++) {
		int DP[MAX][3] = { 0, };

		//시작점이 R, G, B일 때 다른 색 집을 무한값으로 변경(선택되지 않도록)
		for (int i = 0; i < 3; i++) {
			if (i == start) DP[1][start] = cost[1][start];
			else DP[1][i] = 1234567890;
		}
		for (int i = 2; i <= N; i++) {
			DP[i][0] = cost[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
			DP[i][1] = cost[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
			DP[i][2] = cost[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
		}
		for (int i = 0; i < 3; i++) {
			if (i == start) continue;
			ans = min(ans, DP[N][i]);
		}
	}
	cout << ans << '\n';
}


/*
17404. RGB거리 2
https://www.acmicpc.net/problem/17404

문제
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.
입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

첫집과 마지막집의 색이 달라야 한다는 것을 제외하면 RGB거리 문제와 동일함.
첫 집을 무슨 색으로 할 건지 정해놓은 후 각각 최소 비용을 구하면 되는 문제.
*/ 