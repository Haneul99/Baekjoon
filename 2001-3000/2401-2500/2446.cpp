#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = n-i; j < n-1; j++) {
			printf(" ");
		}
		for (int j = 2 * i - 1; j < 2 * n; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i; j < n - 1; j++) {
			printf(" ");
		}//blank 3
		for (int j = 0; j < 2 * i+1; j++) {
			printf("*");
		}//3 5 7 9
		printf("\n");
	}
}

/*
2446. 별 찍기 - 9
https://www.acmicpc.net/problem/2446

문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

*/