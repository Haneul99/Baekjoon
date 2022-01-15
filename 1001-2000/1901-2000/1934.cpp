#include<stdio.h>

void get(int n1, int n2) {
	int max = 0;
	int big;
	int small;
	if (n1 >= n2) {
		big = n1;
		small = n2;
	}
	else {
		big = n2;
		small = n1;
	}
	for (int i = 1; i <= small; i++) {
		if (n1%i == 0 && n2%i == 0) max = i;
	}//�ִ�����
	int k = n1 * n2 / max;
	
	printf("%d\n", k);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		get(n1, n2);
	}
}


/*
1934. 최소공배수
https://www.acmicpc.net/problem/1934

최소공배수 = 두 수 곱하기 / 최대공약수
*/