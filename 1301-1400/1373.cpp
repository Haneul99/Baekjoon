#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000001];
	scanf("%s", str);
	int lenR = strlen(str) % 3;
	int mult;
	int n = 0;
	int i;
	if (lenR == 1) mult = 1;
	else if (lenR == 2) mult = 2;

	for (i=1; i <= lenR ; i++) {
		n = n + (str[i - 1] - 48) * mult;
		mult /= 2;
	}
	if (lenR != 0) printf("%d", n);

	mult = 4;
	n = 0;
	int len = strlen(str);
	for (;i<= len; i++) {
		n = n + (str[i - 1] - 48) * mult;
		mult /= 2;
		if (i % 3 - lenR == 0) {
			mult = 4;
			printf("%d", n);
			n = 0;
		}
	}
}

//0 : 48

/*
1373. 2진수 8진수
https://www.acmicpc.net/problem/1373


문제
2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

입력
첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.

세개씩 끊어서 출력하기
strlen 시간 오래 걸리기 때문에 for문 안에는 가급적 쓰지 않기. 변수에 저장하는게 좋음.
*/