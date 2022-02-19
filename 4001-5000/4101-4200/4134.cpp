#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;

bool isPrime(long long num) {
	long long range = sqrt(num);
	if (num % 2 == 0) return false;
	for (long long i = 3; i <= range; i += 2) {
		if (num%i == 0) return false;
	}
	return true;
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);

	while (t--) {
		long long n;
		scanf("%lld", &n);
		if (n == 0 || n == 1 || n == 2) {
			printf("2\n");
			continue;
		}
		long long num = n;
		while (true) {
			if (isPrime(num)) {
				printf("%lld\n", num);
				break;
			}
			num++;
		}
	}
}


/*
4134. 다음 소수
https://www.acmicpc.net/problem/4134

문제
정수 n(0 ≤ n ≤ 4*109)가 주어졌을 때, n보다 크거나 같은 소수 중 가장 작은 소수 찾는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.

출력
각각의 테스트 케이스에 대해서 n보다 크거나 같은 소수 중 가장 작은 소수를 한 줄에 하나씩 출력한다.
*/