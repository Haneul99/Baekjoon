#include<stdio.h>


int main() {
	int n1, n2;
	scanf("%d", &n1);
	scanf("%d", &n2);
	int max=1;

	if (n1 > n2) {
		for (int i = 1; i <= n2; i++) {
			if (n1%i == 0 && n2%i == 0) max = i;
		}//�ִ�����
		int k = n2;
		while (1) {
			if (k%n1 == 0 && k%n2 == 0) break;
			k++;
		}
		printf("%d\n", max);
		printf("%d\n", k);
	}
	else if (n2 > n1) {
		for (int i = 1; i <= n1; i++) {
			if (n1%i == 0 && n2%i == 0) max = i;
		}//�ִ�����
		int k = n1;
		while (1) {
			if (k%n1 == 0 && k%n2 == 0) break;
			k++;
		}
		printf("%d\n", max);
		printf("%d\n", k);
	}
	else {
		printf("%d\n",n1);
		printf("%d\n",n1);
	}
}


/*
2609. 최대공약수와 최소공배수 
https://www.acmicpc.net/problem/2609

문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
*/