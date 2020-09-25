#include<stdio.h>
#include<malloc.h>

int main() {
	int n;
	scanf("%d", &n);
	int *num;
	int **count;
	num = (int*)malloc(sizeof(int)*n);
	count = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		count[i] = (int*)malloc(sizeof(int) * 2);
	}//n*2 array

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}//init

	int M;
	scanf("%d", &M);
	int *result;
	int m;
	result = (int *)malloc(sizeof(int)*M);
	for (int i = 0; i < M; i++) {
		result[i] = 0;
		scanf("%d", &m);
		for (int j = 0; j < n; j++) {
			if (m == num[j]) {
				result[i]++;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		printf("%d ", result[i]);
	}
}

/*
2163. 
https://www.acmicpc.net/problem/2164


*/