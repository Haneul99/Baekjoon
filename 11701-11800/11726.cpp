#include<stdio.h>
#include<malloc.h>

int *arr;

int main() {
	int n;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int *)*(n + 1));
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	printf("%d\n",arr[n]);
}

/*
11726. 2×n 타일링
https://www.acmicpc.net/problem/11726

문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.


fibonacci
*/