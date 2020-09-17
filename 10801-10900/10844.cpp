#include<stdio.h>
#include<malloc.h>

int main() {
	int n;
	scanf("%d", &n);
	long long sum=0;
	long dp[101][10];
	dp[1][0] = 0;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = (dp[i - 1][1]) % 1000000000;
			}
			else if (j == 9) {
				dp[i][9] = (dp[i - 1][8]) % 1000000000;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		sum = (sum + dp[n][i]) % 1000000000;
	}
	printf("%lld\n", sum);
}

/*
10844. 쉬운 계단 수
https://www.acmicpc.net/problem/10844

문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.


L = 0 : dp[N][L] = dp[N-1][L+1]
L = 1~8 :dp[N][L] = dp[N - 1][L - 1] + dp[N - 1][L + 1]
L = 9 : dp[N][L] = dp[N-1][L-1]
printf dp[N] sum
*/