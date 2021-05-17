#include<stdio.h>
#include<algorithm>

using namespace std;

int n;
int arr[100001];

int binary(int target, int low, int high) {
	int flag = 0;
	if (arr[0] == target) {
		return 1;
	}
	while (low <= high) {
		int mid = (low + high) / 2;
		if (target == arr[mid]) {
			return 1;
		}
		else if (target < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int target;
		scanf("%d", &target);
		printf("%d\n", binary(target, 0, n));
	}
}


/*
1920. 수 찾기
https://www.acmicpc.net/problem/1920

문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

*/