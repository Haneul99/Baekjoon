#include<stdio.h>

int main() {
	int n;
	int arr[2002] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr[x + 1000]++;
	}
	int first;
	for (int i = 0; i < 2001; i++) {
		if (arr[i] > 0) {
			printf("%d", i - 1000);
			first = i;
			break;
		}
	}
	for (int i = first + 1; i < 2001; i++) {
		if (arr[i] > 0) {
			printf(" %d", i - 1000);
		}
	}
}


/*
10867. 중복 빼고 정렬하기
https://www.acmicpc.net/problem/10867

문제
N개의 정수가 주어진다. 이때, N개의 정수를 오름차순으로 정렬하는 프로그램을 작성하시오. 같은 정수는 한 번만 출력한다.

입력
첫째 줄에 수의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 수를 오름차순으로 정렬한 결과를 출력한다. 이때, 같은 수는 한 번만 출력한다.

*/