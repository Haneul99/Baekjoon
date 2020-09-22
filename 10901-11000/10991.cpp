#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	//bb*
	//b*b*
	//*b*b*
	for (int i = 1; i <= n; i++) {
		for (int j = n-i; j>0; j--) {
			printf(" ");
		}//blank
		for (int j = 0; j < i; j++) {
			if (j == n - 1) printf("*");
			else printf("* ");
		}//star
		printf("\n");
	}
}

/*
10991. 별 찍기 - 16
https://www.acmicpc.net/problem/10991

문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

*/