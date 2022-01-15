#include<stdio.h>
#include<string.h>

int main() {
	long n1, n2, n3, n4;
	long sum1=0, sum2=0, sum3=0;
	scanf(" %ld", &n1);
	scanf(" %ld", &n2);
	scanf(" %ld", &n3);
	scanf(" %ld", &n4);
	int c1 = 1, c2 = 1;
	for (int i = 1;; i *= 10) {
		c1*=10;
		if (n2/i < 10) break;
	}
	for (int i = 1;; i *= 10) {
		c2 *= 10;
		if (n4 / i < 10) break;
	}
	sum1 = n1 * c1 + n2;
	sum2 = n3 * c2 + n4;
	printf("%lld\n", sum1 + sum2);
}

/*
10824. 네 수
https://www.acmicpc.net/problem/10824

문제
네 자연수 A, B, C, D가 주어진다. 이때, A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오.

두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다. 즉, 20과 30을 붙이면 2030이 된다.

입력
첫째 줄에 네 자연수 A, B, C, D가 주어진다. (1 ≤ A, B, C, D ≤ 1,000,000)

출력
A와 B를 붙인 수와 C와 D를 붙인 수의 합을 출력한다.

take care of overflow
*/