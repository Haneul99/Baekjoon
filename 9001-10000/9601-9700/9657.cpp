#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	int dp[1001] = { 0, };
	//1 승리, 0 패배
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= n; i++) {
		if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1) {
			dp[i] = 0;
		}
		else dp[i] = 1;
	}
	
	if (dp[n] == 1) {
		printf("SK\n");
	}
	else printf("CY\n");
}

/*
9657. 돌 게임 3
https://www.acmicpc.net/problem/9657

문제
돌 게임은 두 명이서 즐기는 재밌는 게임이다.

탁자 위에 돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 돌은 1개, 3개 또는 4개 가져갈 수 있다. 마지막 돌을 가져가는 사람이 게임을 이기게 된다.

두 사람이 완벽하게 게임을 했을 때, 이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 먼저 시작한다.

입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 1000)

출력
상근이가 게임을 이기면 SK를, 창영이가 게임을 이기면 CY을 출력한다.
*/