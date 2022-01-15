#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];
	scanf("%s", str);
	int len = strlen(str)-1;
	int base;
	scanf("%d", &base);

	long long mult = 1;
	long long n = 0;
	for (int i = 0;i< strlen(str); i++) {
		mult = 1;
		for (int j = i; j < len; j++) {
			mult *= base;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			n = n + mult * (str[i] - 48);
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			n = n + mult * (str[i] - 55);
		}
	}
	printf("%lld", n);
}

//A : 65 ~ Z : 90
//0 : 48

/*
2745. 진법 변환
https://www.acmicpc.net/problem/2745

문제
B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 출력하는 프로그램을 작성하시오.

10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.

A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

입력
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36)

B진법 수 N을 10진법으로 바꾸면, 항상 10억보다 작거나 같다.

출력
첫째 줄에 B진법 수 N을 10진법으로 출력한다.


ex) ZZZZZ 36
: 35(Z)*36^4 + 35*36^3 + 35*36^2 + 35*36^1 + 35*36^0
*/