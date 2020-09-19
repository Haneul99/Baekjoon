#include<stdio.h>
#include<string.h>

int main() {
	char num[11] = { 0, };
	scanf("%s", num);
	for (int i = 0; i < strlen(num); i++) {
		int max = num[i];
		int max_index = i;
		for (int j = i + 1; j < strlen(num); j++) {
			if (num[j] > max) {
				max = num[j];
				max_index = j;
			}
		}
		char temp;
		temp = num[i];
		num[i] = num[max_index];
		num[max_index] = temp;
	}
	printf("%s", num);
}

/*
1427. 소트인사이드
https://www.acmicpc.net/problem/1427

문제
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

입력
첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

insertion sort
store N as string

*/