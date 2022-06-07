#include<iostream>
#define MAX 100000

using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;

	int ans = 0;
	for (long long i = 1; i < MAX; i++) {
		if (i*(i + 1)/2 > n) break;
		ans = i;
	}
	cout << ans << '\n';
}


/*
1789. 수들의 합
https://www.acmicpc.net/problem/1789

문제
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?

입력
첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.

출력
첫째 줄에 자연수 N의 최댓값을 출력한다.

200 이면 답이 19

그러니까 1+2+3...+k <= N 인 최댓값 k를 구하는 문제
(1+k)*k/2 <= N
k(k+1) <= 2*N
*/