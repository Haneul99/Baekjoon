#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	printf("%lld\n", result);
}


/*
10872. 팩토리얼
https://www.acmicpc.net/problem/10872

문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

출력
첫째 줄에 N!을 출력한다.

*/