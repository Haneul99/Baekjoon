#include<stdio.h>
#include<malloc.h>

typedef struct XY {
	int x;
	int y;
}XY;

XY *arr;

int partition(XY arr[], int left, int right) {
	int low, high, pivot;
	XY tmp;
	low = left;
	high = left;

	pivot = (left + right) / 2;
	tmp = arr[left];
	arr[left] = arr[pivot];
	arr[pivot] = tmp;
	pivot = left;
	if (left < right) {
		for (int i = left + 1; i <= right; i++) {
			if (arr[i].y < arr[pivot].y) {
				high++;
				tmp = arr[i];
				arr[i] = arr[high];
				arr[high] = tmp;
			}
			else if (arr[i].y == arr[pivot].y) {
				if (arr[i].x < arr[pivot].x) {
					high++;
					tmp = arr[i];
					arr[i] = arr[high];
					arr[high] = tmp;
				}
			}
		}
	}
	tmp = arr[left];
	arr[left] = arr[high];
	arr[high] = tmp;
	return high;
}

void quickSort(XY arr[], int low, int high) {
	if (high > low) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	arr = (XY*)malloc(sizeof(XY)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].x);
		scanf("%d", &arr[i].y);
	}

	quickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n",arr[i].x,arr[i].y);
	}
}

// partition & quickSort


/*
11651. 좌표 정렬하기 2 
https://www.acmicpc.net/problem/11651

문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

*/