#include<stdio.h>

int main() {
	char a;
	while (1) {
		a=getchar();
		if (a == EOF) {
			break;
		}
		putchar(a);
	}
}

/*
11719. 그대로 출력하기 2
https://www.acmicpc.net/problem/11719

문제
입력 받은 대로 출력하는 프로그램을 작성하시오.

입력
입력이 주어진다. 입력은 최대 100줄로 이루어져 있고, 알파벳 소문자, 대문자, 공백, 숫자로만 이루어져 있다. 각 줄은 100글자를 넘지 않으며, 빈 줄이 주어질 수도 있고, 각 줄의 앞 뒤에 공백이 있을 수도 있다.

출력
입력받은 그대로 출력한다.

same as 11718. 그대로 출력하기
*/