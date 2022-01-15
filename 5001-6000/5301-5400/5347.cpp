#include<stdio.h>

long long gcd(long long a, long long b) {
	int r;
	if (a < b) {
		int temp = b;
		b = a;
		a = temp;
	}
	while (b != 0) {
		r = a % b;
		if (r == 0) return b;
		a = b;
		b = r;
	}
	return a;
}


int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", (a*b) / gcd(a, b));
	}
}


/*
5347. LCM 
https://www.acmicpc.net/problem/5347

문제
두 수 a와 b가 주어졌을 때, a와 b의 최소 공배수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 n이 주어진다. 다음 n개 줄에는 a와 b가 주어진다. a와 b사이에는 공백이 하나 이상 있다. 두 수는 백만보다 작거나 같은 자연수이다.

출력
각 테스트 케이스에 대해서 입력으로 주어진 두 수의 최소공배수를 출력한다.

*/