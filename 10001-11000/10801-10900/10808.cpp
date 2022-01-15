#include<stdio.h>
#include<string.h>

int main() {
	char str[100];
	scanf("%s", str);
	int nums[26] = { 0 ,};
	for (int i = 0; i < strlen(str); i++) {
		int c = (int)(str[i] - 'a');
		if (str[i] == 'a') nums[0]++;
		else nums[c]++;
	}
	for (int i = 0; i <sizeof(nums)/sizeof(int); i++) {
		printf("%d ", nums[i]);
	}
}

/*
10808. 알파벳 찾기
https://www.acmicpc.net/problem/10808



*/