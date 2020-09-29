#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct member {
	int korean;
	int english;
	int math;
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
			if (arr[i].korean > arr[pivot].korean) {
				high++;
				tmp = arr[i];
				arr[i] = arr[high];
				arr[high] = tmp;
			}//decrease korean
			else if (arr[i].korean == arr[pivot].korean) {
				if (arr[i].english < arr[pivot].english) {
					high++;
					tmp = arr[i];
					arr[i] = arr[high];
					arr[high] = tmp;
				}//increase english
				else if (arr[i].english == arr[pivot].english) {
					if (arr[i].math > arr[pivot].math) {
						high++;
						tmp = arr[i];
						arr[i] = arr[high];
						arr[high] = tmp;
					}//decrease math
					else if (arr[i].math == arr[pivot].math) {
						if (strcmp(arr[i].name, arr[pivot].name) < 0) {
							high++;
							tmp = arr[i];
							arr[i] = arr[high];
							arr[high] = tmp;
						}//increase name
					}
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
		scanf("%s", &arr[i].name);
		scanf("%d", &arr[i].korean);
		scanf("%d", &arr[i].english);
		scanf("%d", &arr[i].math);
	}

	quickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%s\n",arr[i].name);
	}
}


/*
10825. 국영수
https://www.acmicpc.net/problem/10825

문제
도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
입력
첫째 줄에 도현이네 반의 학생의 수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 한 줄에 하나씩 각 학생의 이름, 국어, 영어, 수학 점수가 공백으로 구분해 주어진다. 점수는 1보다 크거나 같고, 100보다 작거나 같은 자연수이다. 이름은 알파벳 대소문자로 이루어진 문자열이고, 길이는 10자리를 넘지 않는다.

출력
문제에 나와있는 정렬 기준으로 정렬한 후 첫째 줄부터 N개의 줄에 걸쳐 각 학생의 이름을 출력한다.

*/