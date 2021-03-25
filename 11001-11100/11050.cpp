#include<stdio.h>


int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = 1;
	for (int i = 0; i < k; i++) {
		ans *= (n - i);
		ans /= (i + 1);
	}
	printf("%d\n", ans);
}

/*
11050. 이항 계수 1
https://www.acmicpc.net/problem/11050

문제
자연수 과 정수 가 주어졌을 때 이항 계수 
를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 과 가 주어진다. (1 ≤  ≤ 10, 0 ≤  ≤ )
*/                      