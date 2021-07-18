#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdio.h>

using namespace std;

int n, m;

int calc(int x) {
	int cnt = 0;
	string num = to_string(x);
	int len = num.length();
	for (int j = 0; j < len; j++) {
		if (num[j] == '0') cnt++;
	}
	return cnt;
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int zero = 0;
		scanf("%d%d", &n, &m);
		for (int i = n; i <= m; i++) {
			zero += calc(i);
		}
		printf("%d\n", zero);
	}
}

/*
11170. 0의 개수
https://www.acmicpc.net/problem/11170

문제
N부터 M까지의 수들을 종이에 적었을 때 종이에 적힌 0들을 세는 프로그램을 작성하라.

예를 들어, N, M이 각각 0, 10일 때 0을 세면 0에 하나, 10에 하나가 있으므로 답은 2이다.

입력
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 줄에는 N과 M이 주어진다.

1 ≤ T ≤ 20
0 ≤ N ≤ M ≤ 1,000,000
출력
각각의 테스트 케이스마다 N부터 M까지의 0의 개수를 출력한다.


3
0 10
33 1005
1 4

2
199
0
*/