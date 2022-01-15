#include<stdio.h>

int n1, n2;
int arr1[1000001];
int arr2[1000001];


int main() {
	scanf("%d%d", &n1, &n2);
	for (int i = 0; i < n1; i++)
		scanf("%d", &arr1[i]);
	for (int i = 0; i < n2; i++)
		scanf("%d", &arr2[i]);
	int a1 = 0, a2 = 0;
	while (a1 < n1 && a2 < n2) {
		if (arr1[a1] >= arr2[a2]) {
			printf("%d ", arr2[a2]);
			a2++;
		}
		else {
			printf("%d ", arr1[a1]);
			a1++;
		}
	}
	if (a1 < n1) {
		for (int i = a1; i < n1; i++)
			printf("%d ", arr1[i]);
	}
	else if (a2 < n2) {
		for (int i = a2; i < n2; i++)
			printf("%d ", arr2[i]);
	}
}

/*
11728. 배열 합치기
https://www.acmicpc.net/problem/11728

문제
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

출력
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.

*/