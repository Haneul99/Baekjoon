#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int arr[101];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 2 || arr[i] == 3) count++;
		else if (arr[i] == 1);
		else if (arr[i] % 2 == 0);
		else {
			int check = 0;
			for (int j = 3; j < arr[i]; j+=2) {
				if (arr[i] % j == 0) check = 1;
			}
			if (check == 0) count++;
		}
	}
	printf("%d\n", count);
}


/*
1978. 소수 찾기
https://www.acmicpc.net/problem/1978

문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.

*/