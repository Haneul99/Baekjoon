#include <stdio.h>
#include<math.h>

int main(void) {
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	if (n1 == 1 && n2 == 1);
	if (n1 <= 2 && n2 >= 2) {
		printf("2\n");
	}
	if (n1 <= 3 && n2 >= 3) {
		printf("3\n");
	}
	if(n2>4) {
		int i;
		if (n1 < 5) i = 5;
		else if (n1 % 2 == 0) i = n1 + 1;
		else i = n1;
		for (; i <= n2; i += 2) {
			int check = 0;
			for (int j = 3; j <= sqrt(i); j += 2) {
				if (i % 2 == 0) {
					check = 1;
					break;
				}
				if (i%j == 0) {
					check = 1;
					break;
				}
			}
			if (check == 0) printf("%d\n", i);
		}
	}
}


/*
1929. 소수 구하기
https://www.acmicpc.net/problem/1929

문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

*/