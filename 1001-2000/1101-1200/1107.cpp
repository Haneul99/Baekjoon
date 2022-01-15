#include<stdio.h>
#include<math.h>

int target, m;
int broken[11];
int unbroken[11];
int digit = 0;
int curs = 0;
int combi[10];
int min = 9999999;


void get_digit(int idx, int depth) {
	combi[depth] = unbroken[idx];
	if (depth == digit) {
		int num = 0;
		int mux = 1;
		for (int i = digit; i > 0; i--) {
			num += combi[i] * mux;
			mux *= 10;
		}
		if (abs(target - num) + digit < min) min = abs(target - num) + digit;
	}
	else {
		for (int i = 0; i < curs; i++) {
			get_digit(i, depth + 1);
		}
	}
}

void get_minus(int idx, int depth) {
	combi[depth] = unbroken[idx];
	if (depth == digit - 1) {
		int num = 0;
		int mux = 1;
		for (int i = digit - 1; i > 0; i--) {
			num += combi[i] * mux;
			mux *= 10;
		}
		if (abs(target - num) + digit - 1 < min) min = abs(target - num) + digit - 1;
	}
	else {
		for (int i = 0; i < curs; i++) {
			get_minus(i, depth + 1);
		}
	}
}

void get_plus(int idx, int depth) {
	combi[depth] = unbroken[idx];
	if (depth == digit + 1) {
		int num = 0;
		int mux = 1;
		for (int i = digit + 1; i > 0; i--) {
			num += combi[i] * mux;
			mux *= 10;
		}
		if (abs(target - num) + digit + 1 < min) min = abs(target - num) + digit + 1;
	}
	else {
		for (int i = 0; i < curs; i++) {
			get_plus(i, depth + 1);
		}
	}
}

int main() {
	scanf("%d%d", &target, &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		broken[x] = 1;
	}
	for (int i = 0; i < 10; i++) {
		if (broken[i] == 0) {
			unbroken[curs] = i;
			curs++;
		}
	}
	if (target == 0) {
		digit = 1;
	}
	else {
		int t = 1;
		while (target / t >= 1) {
			t *= 10;
			digit++;
		}
	}//자릿수 구하기

	int p_m_bt = abs(target - 100);
	get_digit(0, 0);
	if (digit > 1) get_minus(0, 0);//digit이 2인 경우에만 한자리 작은 것 구함
	get_plus(0, 0);
	if (min > p_m_bt) min = p_m_bt;//+-버튼만 누른 경우
	
	printf("%d\n", min);
}

/*
1107. 리모컨
https://www.acmicpc.net/problem/1107

문제
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 

수빈이가 지금 보고 있는 채널은 100번이다.

입력
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.

출력
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.

네가지 경우의 수 중 가장 작은 것이 정답
1. n-1 자릿수
2. n 자릿수
3. n+1 자릿수
4. Plus Minus button만을 이용해 움직이는 경우

*/