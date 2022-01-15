#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 2*i-1; j++) {
			printf("*");
		}
		printf("\n");
	}
}

/*
2442. 별 찍기 - 5
https://www.acmicpc.net/problem/2442

문제
첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2×N-1개를 찍는 문제

별은 가운데를 기준으로 대칭이어야 한다.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

*/