#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j < n - 1; j++) {
			printf(" ");
		}
		for (int j = n-i; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i; j > 0; j--) {
			printf(" ");
		}//2 4 6 8
		for (int j = i; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

/*
2552. 별 찍기 - 12
https://www.acmicpc.net/problem/2522

문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

*/