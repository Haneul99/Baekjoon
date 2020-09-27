#include<stdio.h>
#include<string.h>
#include<malloc.h>

int *arr;

int partition(int arr[], int left, int right) {
	int low, high, pivot;
	int tmp;
	low = left;
	high = right + 1;

	pivot = (left + right) / 2;
	tmp = arr[left];
	arr[left] = arr[pivot];
	arr[pivot] = tmp;
	pivot = left;

	do {
		do {
			low++;
		} while (low <= right && arr[low] < arr[pivot]);
		do {
			high--;
		} while (high >= left && arr[high] > arr[pivot]);
		if (low < high) {
			tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
	} while (high > low);
	tmp = arr[left];
	arr[left] = arr[high];
	arr[high] = tmp;
	return high;
}

void quickSort(int arr[], int low, int high) {
	if (high > low) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	quickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%d\n",arr[i]);
	}
}

// partition & quickSort
// pivot을 middle index로 set

/*
2751. 수 정렬하기 2
https://www.acmicpc.net/problem/2751

문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

*/