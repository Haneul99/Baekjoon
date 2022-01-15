#include<stdio.h>

int main() {
	int origin;
	int n;
	scanf("%d", &origin);
	int cycle = 0;
	int q=origin/10;
	int r=origin%10;
	n = (q + r) % 10 + r * 10;
	cycle++;
	while (origin!=n) {
		q = n / 10;
		r = n % 10;
		n = (q + r) % 10 + r * 10;
		cycle++;
	}
	printf("%d\n", cycle);
}

/*
1110. 더하기 사이클
https://www.acmicpc.net/problem/1110

*/