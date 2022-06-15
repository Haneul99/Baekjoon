#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int L, n, ans = 0;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}

	cin >> n;
	sort(arr.begin(), arr.end());

	int start = 1, end = 0;
	int echeck = 0;
	for (int i = 0; i < L; i++) {
		if (!echeck && n < arr[i]) {
			end = arr[i] - 1;
			echeck = 1;
		}
		if (n > arr[i]) {
			start = arr[i] + 1;
		}
		if (n == arr[i]) {
			cout << "0";
			return 0;
		}
	}
	cout << (n - start) * (end - n + 1) + (end - n) << '\n';
}


/*
1059. 좋은 구간
https://www.acmicpc.net/problem/1059

문제
정수 집합 S가 주어졌을때, 다음 조건을 만족하는 구간 [A, B]를 좋은 구간이라고 한다.

A와 B는 양의 정수이고, A < B를 만족한다.
A ≤ x ≤ B를 만족하는 모든 정수 x가 집합 S에 속하지 않는다.
집합 S와 n이 주어졌을 때, n을 포함하는 좋은 구간의 개수를 구해보자.

입력
첫째 줄에 집합 S의 크기 L이 주어진다. 둘째 줄에는 집합에 포함된 정수가 주어진다. 셋째 줄에는 n이 주어진다.

출력
첫째 줄에 n을 포함하는 좋은 구간의 개수를 출력한다.
*/