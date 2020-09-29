#include<stdio.h>
#include<malloc.h>

typedef struct member {
	int index;
	int age;
	char name[101];
}member;

member *arr;

int partition(member arr[], int left, int right) {
	int low, high, pivot;
	member tmp;
	low = left;
	high = left;

	pivot = (left + right) / 2;
	tmp = arr[left];
	arr[left] = arr[pivot];
	arr[pivot] = tmp;
	pivot = left;
	if (left < right) {
		for (int i = left + 1; i <= right; i++) {
			if (arr[i].age < arr[pivot].age) {
				high++;
				tmp = arr[i];
				arr[i] = arr[high];
				arr[high] = tmp;
			}
			else if (arr[i].age == arr[pivot].age) {
				if (arr[i].index < arr[pivot].index) {
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

void quickSort(member arr[], int low, int high) {
	if (high > low) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	arr = (member*)malloc(sizeof(member)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].age);
		scanf("%s", &arr[i].name);
		arr[i].index = i;
	}

	quickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n",arr[i].age,arr[i].name);
	}
}


/*
10814. 나이순 정렬
https://www.acmicpc.net/problem/10814

문제
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

출력
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

*/