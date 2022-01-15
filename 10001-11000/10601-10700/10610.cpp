#include<stdio.h>
#include<string.h>

char n[100001];
int len;
int arr[100005];
int num[10] = { 0, };

int check() {
	int chk1 = 0;
	int chk2 = 0;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
		if (arr[i] == 0) chk1 = 1;
	}
	if (sum % 3 == 0) chk2 = 1;
	return chk1 & chk2;
}

int main() {
	scanf("%s", n);
	len = strlen(n);
	for (int i = 0; i < len; i++) {
		arr[i] = n[i] - 48;
		num[n[i] - 48]++;
	}

	if (check()) {
		for (int i = 9; i >= 0; i--)
			for (int j = 0; j < num[i]; j++)
				printf("%d", i);
	}
	else printf("-1");
}

/*
10610. 30
https://www.acmicpc.net/problem/10610

문제
어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

입력
N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

출력
미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.


10^5자리수이기 때문에 문자열로 받아와야 함.
각 자리수를 따로 보며 0~9의 배열에 각 수가 등장하는 횟수를 기록.
가장 큰 수를 출력하는 것이므로 9~0의 순서로 출력
*/