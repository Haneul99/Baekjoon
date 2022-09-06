#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	
	int ans[1000010] = { 0, };
	stack<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (s.empty()) s.push({ x, i });
		else if (s.top().first < x) {
			while (!s.empty() && s.top().first < x) {
				int num = s.top().first;
				int idx = s.top().second;

				ans[idx] = x;
				s.pop();
			}
		}
		s.push({ x,i });
	}
	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}


/*
17298. 오큰수
https://www.acmicpc.net/problem/17298

문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.
*/