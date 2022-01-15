#include<stdio.h>
#include<malloc.h>

int main() {
	int n;
	scanf("%d", &n);
	int *data = (int *)malloc(sizeof(int)*n);
	int *dp = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		dp[i] = 1;
	}
	int length = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (data[i] < data[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
		}//decresing && dp[j]+1(본인 더한 것) 중 최댓값을 골라야 함.
		//ex) 30 20 10 20 5 일때, dp[0]=1, dp[1]=2, dp[2]=3 dp[3]=2 dp[4]=4 (=dp[2]+1)
		//두번째 조건이 없었다면 dp[4]=dp[3]+1로, 3이 되었을 것
		if (length < dp[i]) length = dp[i];
	}
	printf("%d\n", length);
}

/*
11722. 가장 긴 감소하는 부분 수열
https://www.acmicpc.net/problem/11722

문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.

*/