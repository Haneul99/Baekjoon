#include<stdio.h>
#include<math.h>

int target, m;
int broken[11];
int count = 0;

int getMin(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	else if (b <= a && b <= c) return b;
	else return c;
}

int upperNumber() {
	int num = target;
	int flag = 1;
	while (flag==1) {
		flag = 0;
		int digit = num;
		while (digit>= 1) {
			if (broken[digit%10] == 1) {
				flag = 1;
				break;
			}
			digit /= 10;
		}
		if (flag == 1) num++;
	}
	int t = 1;
	int c = 0;
	while (num / t >= 1) {
		t *= 10;
		c++;
	}
	return abs(target - num) + c;
}

int lowerNumber() {
	int num = target;
	int flag = 1;
	while (flag == 1) {
		flag = 0;
		int digit = num;
		while (digit>= 1) {
			if (broken[digit % 10] == 1) {
				flag = 1;
				break;
			}
			digit /= 10;
		}
		if (flag == 1) num--;
	}
	int t = 1;
	int c = 0;
	while (num / t >= 1) {
		t *= 10;
		c++;
	}
	return abs(target - num) + c;
}

int main() {
	scanf("%d%d", &target,&m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		broken[x] = 1;
	}
	int t = 1;
	while (target / t >= 1) {
		t *= 10;
		count++;
	}
	int up = upperNumber();
	int down = lowerNumber();
	int pm = abs(target - 100);
	printf("up: %d\tdown:%d\tpm: %d\n", up, down, pm);
	printf("%d\n", getMin(up, down, pm));
}

/*
1107. 리모컨
https://www.acmicpc.net/problem/1107



*/