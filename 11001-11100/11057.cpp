#include<stdio.h>
#include<malloc.h>

int main() {
	int n;
	scanf("%d", &n);
	int sum=0;
	long dp[1001][10];
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <=n; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int t = j; t < 10; t++) {
				dp[i][j] = dp[i][j] + dp[i - 1][t];
				dp[i][j] %= 10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % 10007;
	}
	printf("%d\n", sum);
}

/*
11057. 오르막 수
https://www.acmicpc.net/problem/11057

**init**
dp[N][L]=dp[N-1][L]+...+dp[N-1][9]
printf dp[N] sum
*/