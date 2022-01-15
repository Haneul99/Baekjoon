#include<stdio.h>


int main() {
	int A, B, C;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	printf("%d\n", (A + B) % C);
	printf("%d\n", ((A%C) + (B%C)) % C);
	printf("%d\n", (A*B) % C);
	printf("%d\n", ((A%C) *(B%C)) % C);
}


/*
10430. 나머지
https://www.acmicpc.net/problem/10430



*/