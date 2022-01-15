#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int count_2 = 0;
	int count_5 = 0;
	for (int i = 1; i <= n; i++) {
		int a = i;
		int flag = 1;
		while (flag == 1) {
			flag = 0;
			if (a % 2 == 0) {
				count_2++;
				a /= 2;
				flag = 1;
			}
		}
		flag = 1;
		while (flag == 1) {
			flag = 0;
			if (a % 5 == 0) {
				count_5++;
				a /= 5;
				flag = 1;
			}
		}
	}
	if (count_2 >= count_5) printf("%d\n", count_5);
	else printf("%d\n", count_2);
}


/*
1676. 팩토리얼 0의 개수
https://www.acmicpc.net/problem/1676

문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.

2x5 쌍이 몇개 나왔는가. 를 구하는 문제임.
i=1 : n 까지, 2와 5를 각각 count하고 둘 중 최소를 출력
*/