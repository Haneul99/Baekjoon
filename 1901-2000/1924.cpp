#include<stdio.h>

int main() {
	int x, y;
	scanf("%d%d", &x,&y);
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = 0;
	for (int i = 0; i < x-1; i++) {
		day += month[i];
	}
	day += y;
	char DAY[7][4] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	printf("%s\n", DAY[day%7]);
}

/*
1924. 2007년
https://www.acmicpc.net/problem/1924

문제
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

출력
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

*/