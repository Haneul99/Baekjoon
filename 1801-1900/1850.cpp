#include<stdio.h>

void get(unsigned long long n1, unsigned long long n2) {
	unsigned long long max = 1;
	unsigned long long big;
	unsigned long long small;
	if (n1 >= n2) {
		big = n1;
		small = n2;
	}
	else {
		big = n2;
		small = n1;
	}
	int flag;
	for (unsigned long long i = 2; i <= small; i++) {
		flag = 1;
		while(flag==1) {
			flag = 0;
			if (big%i == 0 && small%i == 0) {
				printf("i: %d\n", i);
				big /= i;
				small /= i;
				max = (max * i) % 10000000;
				flag = 1;
			}
		}
	}//�ִ�����
	long long k = n1 * n2 / max;
	
	printf("%lld\n", max);
}

int main() {
	int n1, n2;
	scanf("%d", &n1);
	scanf("%d", &n2);
	unsigned long long num1 = 1, num2 = 1;
	long long j = 10;
	for (int i = 1; i < n1; i++) {
		num1 = num1 + 1 * j;
		j *= 10;
	}
	j = 10;
	for (int i = 1; i < n2; i++) {
		num2 = num2+ 1 * j;
		j *= 10;
	}
	get(num1, num2);
}


/*
1850. 최대공약수
https://www.acmicpc.net/problem/1850

문제
모든 자리가 1로만 이루어져있는 두 자연수 A와 B가 주어진다. 이때, A와 B의 최대 공약수를 구하는 프로그램을 작성하시오.

예를 들어, A가 111이고, B가 1111인 경우에 A와 B의 최대공약수는 1이고, A가 111이고, B가 111111인 경우에는 최대공약수가 111이다.

입력
첫째 줄에 두 자연수 A와 B를 이루는 1의 개수가 주어진다. 입력되는 수는 263보다 작은 자연수이다.

출력
첫째 줄에 A와 B의 최대공약수를 출력한다. 정답은 천만 자리를 넘지 않는다.


유클리드 호제법

최대공약수 GCD(a, b) = GCD(b, a%b)

*/