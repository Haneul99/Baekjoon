#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	while (n > 1) {
		for (int i = 2; i <= n; i++) {
			int flag = 1;
			while (flag == 1) {
				flag = 0;
				if (n%i == 0) {
					printf("%d\n", i);
					n /= i;
					flag = 1;
				}
			}
		}
	}
}


/*
11653. 소인수분해
https://www.acmicpc.net/problem/11653

문제
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다.

*/