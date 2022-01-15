#include<stdio.h>
#include<string.h>

int arr[21];

void add(int x) {
	arr[x] = 1;
}

void remove(int x) {
	arr[x] = 0;
}

void check(int x) {
	if (arr[x] == 1) printf("1\n");
	else printf("0\n");
}

void toggle(int x) {
	if (arr[x] == 1) arr[x] = 0;
	else arr[x] = 1;
}

void all() {
	for (int i = 1; i <= 20; i++)
		arr[i] = 1;
}

void empty() {
	for (int i = 1; i <= 20; i++)
		arr[i] = 0;
}


int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char cmd[20];
		scanf(" %s", cmd);
		if (!strcmp(cmd, "add")) {
			int x;
			scanf("%d", &x);
			add(x);
		}
		else if (!strcmp(cmd, "remove")) {
			int x;
			scanf("%d", &x);
			remove(x);
		}
		else if (!strcmp(cmd, "check")) {
			int x;
			scanf("%d", &x);
			check(x);
		}
		else if (!strcmp(cmd, "toggle")) {
			int x;
			scanf("%d", &x);
			toggle(x);
		}
		else if (!strcmp(cmd, "all")) {
			all();
		}
		else if (!strcmp(cmd, "empty")) {
			empty();
		}
	}
}


/*
11723. 집합
https://www.acmicpc.net/problem/11723

문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. 
입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.

*/