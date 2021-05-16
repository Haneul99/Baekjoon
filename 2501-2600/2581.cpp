#include<stdio.h>

int isPrime(int num) {
	if (num == 1) return 0;
	int div = 2;
	while (div <= num / 2) {
		if (num % div == 0) return 0;
		div++;
	}
	return 1;
}

int getMin(int a, int b) {
	return a >= b ? b : a;
}


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	int min = 999999;
	for (int i = n; i <= m; i++) {
		if (isPrime(i)) {
			ans += i;
			min = getMin(min, i);
		}
	}
	if (ans == 0) printf("-1\n");
	else printf("%d\n%d\n", ans, min);
}


/*
2581. 소수
https://www.acmicpc.net/problem/2581

문제
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.

입력
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.

M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

출력
M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다. 

단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.

*/