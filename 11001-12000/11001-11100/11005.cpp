#include <stdio.h>


int main(void) {
	int n;
	scanf("%d", &n);
	int base;
	scanf("%d", &base);
	char num[37] = { 
		'0','1','2','3','4','5','6','7','8','9',
		'A','B','C','D','E','F','G','H','I',
		'J','K','L','M','N','O','P','Q','R','S',
		'T','U','V','W','X','Y','Z','\0'
	};

	char str[101];
	int i = 0;
	while (n >= base) {
		str[i] = num[n%base];
		i++;
		n /= base;
	}
	str[i] = num[n];
	int j = i+1;
	for (; j < 101; j++) {
		str[j] = '\0';
	}
	for(;i>=0;i--)
		printf("%c",str[i]);
}


/*
11005. 진법 변환 2
https://www.acmicpc.net/problem/11005

문제
10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.

10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.

A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

입력
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

출력
첫째 줄에 10진법 수 N을 B진법으로 출력한다.

*/