#include<stdio.h>
#include<malloc.h>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int partition(int arr[],int left, int right) {
	int low = left;
	int high = right + 1;
	int pivot = (left + right) / 2;
	int temp;
	SWAP(arr[pivot], arr[left], temp);
	pivot = left;
	do {
		do {
			low++;
		} while (low <= right && arr[low] < arr[pivot]);
		do {
			high--;
		} while (high >= left && arr[high] > arr[pivot]);
		if (low < high) {
			SWAP(arr[low], arr[high], temp);
		}
	} while (low < high);
	SWAP(arr[left], arr[high], temp);
	return high;
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int q = partition(arr, low, high);
		quicksort(arr, low, q - 1);
		quicksort(arr, q + 1, high);
	}
}


int main() {
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	int* arr;
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quicksort(arr, 0, n - 1);
	printf("%d\n", arr[k-1]);
}


/*
11004. K번째 수
https://www.acmicpc.net/problem/11004

문제
수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.

둘째에는 A1, A2, ..., AN이 주어진다. (-109 ≤ Ai ≤ 109)

출력
A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.

*/