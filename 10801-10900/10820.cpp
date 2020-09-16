#include<stdio.h>
#include<string.h>

int main() {
	char str[100];
	char c;
	int end = 0;
	while (1) {
		int nums[4] = { 0, };
		//upper, lower, number, blank
		while (1) {
			c = getchar();
			if (c == EOF) {
				end = 1;
				break;
			}
			if (c == '\n') break;
			else if (c > 96 && c < 123) nums[0]++;
			else if (c > 64 && c < 91) nums[1]++;
			else if (c > 47 && c < 58) nums[2]++;
			else if (c == ' ') nums[3]++;
		}
		if (nums[0] + nums[1] + nums[2] + nums[3] != 0) {
			for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
				printf("%d ", nums[i]);
			}
			printf("\n");
		}
		if (end) break;
	}
	return 0;
}

/*
10820. 문자열 분석
https://www.acmicpc.net/problem/10820


문제
문자열 N개가 주어진다. 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.

각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

입력
첫째 줄부터 N번째 줄까지 문자열이 주어진다. (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

출력
첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력한다.


공백 포함 문자열 입력받기. 
입력의 끝 체크
*/