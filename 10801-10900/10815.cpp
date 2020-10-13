#include<stdio.h>

int arr[500000];


int partition(int left, int right) {
	int tmp;
	int pivotIndex = (left + right) / 2;

	int temp = arr[left];
	arr[left] = arr[pivotIndex];
	arr[pivotIndex] = temp;
	pivotIndex = left;

	int low = left;
	int high = right + 1;

	do {
		do {
			low++;
		} while (arr[low] < arr[pivotIndex] && low <= right);
		do {
			high--;
		} while (arr[high] > arr[pivotIndex] && left <= high);
		if (low < high) {
			tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
	} while (low < high);
	tmp = arr[left];
	arr[left] = arr[high];
	arr[high] = tmp;
	return high;

}

void quicksort(int low, int high) {
	if (low < high) {
		int pivot = partition(low, high);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}

int binarySearch(int x, int low, int high) {
	int flag = 0;
	if (arr[0] == x) {
		flag = 1;
		return flag;
	}
	while (low <= high) {
		int mid = (low + high) / 2;
		if (x == arr[mid]) {
			flag = 1;
			break;
		}
		else if (x < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	
	return flag;

}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	quicksort(0, n-1);

	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		printf("%d ", binarySearch(x,1,n-1));
	}
}


/*
10815. 숫자 카드
https://www.acmicpc.net/problem/10815

문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.

Sorting and binary search

*/