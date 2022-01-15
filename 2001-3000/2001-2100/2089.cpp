#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	scanf("%d", &n);
	char result[1000001];
	int i = 0;
	if (n == 0)
	{
		printf("0\n");
	}
	else {
		while (n != 0)
		{
			if (n%-2 == 0)
			{
				result[i] = '0';
				result[i + 1] = '\0';
				n /= -2;
				i++;
			}
			else
			{
				result[i]= '1';
				result[i + 1] = '\0';
				n = (n - 1) / -2;
				i++;
			}
		}
		int len = strlen(result) - 1;
		for (int i = len; i >= 0; i--) {
			printf("%c", result[i]);
		}
	}
}

/*
2089. -2진수
https://www.acmicpc.net/problem/2089

문제
-2진법은 부호 없는 2진수로 표현이 된다. 2진법에서는 20, 21, 22, 23이 표현 되지만 -2진법에서는 (-2)0 = 1, (-2)1 = -2, (-2)2 = 4, (-2)3 = -8을 표현한다. 10진수로 1부터 표현하자면 1, 110, 111, 100, 101, 11010, 11011, 11000, 11001 등이다.

10진법의 수를 입력 받아서 -2진수를 출력하는 프로그램을 작성하시오.

입력
첫 줄에 10진법으로 표현된 수 N(-2,000,000,000≤N≤2,000,000,000)이 주어진다.

출력
-2진법 수를 출력한다.

*/