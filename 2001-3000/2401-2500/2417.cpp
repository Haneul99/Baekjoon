#include<stdio.h>
#include<math.h>


int main() {
	long long n;
	scanf("%lld", &n);

	long long ans = sqrt(n);
	if (ans*ans < n) printf("%lld\n", ans + 1);
	else printf("%lld\n", ans);
}


/*
2417. 정수 제곱근
https://www.acmicpc.net/problem/2417

문제
정수가 주어지면, 그 수의 정수 제곱근을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n이 주어진다. (0 ≤ n < 263)

출력
첫째 줄에 q2 ≥ n인 가장 작은 음이 아닌 정수 q를 출력한다.

*/