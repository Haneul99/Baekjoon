#include<stdio.h>
#include<malloc.h>

int main() {
	int n;
	scanf("%d", &n);
	int *data = (int *)malloc(sizeof(int)*n);
	int *dp = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		dp[i] = data[i];
	}
	//init
	int max = data[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (data[i] > data[j] && dp[i] < dp[j] + data[i])
				dp[i] = dp[j] + data[i];
		}//j~i, if increment subarray, add and compare max sum
		if (max < dp[i]) max = dp[i];
	}
	printf("%d\n", max);
}

/*
11055. 가장 큰 증가 부분 수열
https://www.acmicpc.net/problem/11055

문제
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

*/