#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	//bbb*
	//bb*b*
	//b*bbb*
	//*******
	for (int i = 1; i <= n; i++) {
		if (i != n) {
			for (int j = n - i; j > 0; j--) {
				printf(" ");
			}//blank
			printf("*");//star
			for (int j = i; j <= 2*(i-1); j++) {
				if (j == i) printf(" ");
				else printf("  ");
			}//blank
			if (i != 1) printf("*");//star
		}
		if (i == n) {
			for (int j = 0; j < n; j++) {
				if (j == n - 1) printf("*");
				else printf("**");
			}//last line
		}
		printf("\n");
	}
}

/*
10992. 별 찍기 - 17
https://www.acmicpc.net/problem/10992

문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

*/