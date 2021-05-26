#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int getMin(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);

	if (n == 2) {
		int num1, num2;
		scanf("%d%d", &num1, &num2);
		int min = getMin(num1, num2);
		for (int i = 1; i <= min; i++) {
			if (num1%i == 0 && num2%i == 0) printf("%d\n", i);
		}
	}
	else {
		int num1, num2, num3;
		scanf("%d%d%d", &num1, &num2, &num3);
		int min = getMin(num1, getMin(num2, num3));
		for (int i = 1; i <= min; i++) {
			if (num1%i == 0 && num2%i == 0 && num3%i == 0) printf("%d\n", i);
		}
	}
}


/*
5618. 공약수
https://www.acmicpc.net/problem/5618

문제
자연수 n개가 주어진다. 이 자연수의 공약수를 모두 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 2 또는 3이다. 둘째 줄에는 공약수를 구해야 하는 자연수 n개가 주어진다. 모든 자연수는 108 이하이다.

출력
입력으로 주어진 n개 수의 공약수를 한 줄에 하나씩 증가하는 순서대로 출력한다.
*/