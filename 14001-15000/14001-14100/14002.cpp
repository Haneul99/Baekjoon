#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 1010

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, ans = 0, ansIdx = 0; cin >> N;
	int nums[MAX] = { 0, };
	vector<int> incSubsequence;
	pair<int, int> DP[MAX];//first: 길이, second: 이전 index
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	for (int i = 1; i <= N; i++) {
		DP[i].first = 1;
		DP[i].second = -1;
	}
	for (int i = 1; i <= N; i++) {
		int maxLen = 0, preIdx = -1;
		for (int j = 1; j < i; j++) {
			if (nums[i] > nums[j] && maxLen < DP[j].first) {
				maxLen = DP[j].first;
				preIdx = j;
			}
		}
		DP[i].first = maxLen + 1;
		DP[i].second = preIdx;
		if (DP[i].first > ans) {
			ans = DP[i].first;
			ansIdx = i;
		}
	}

	int idx = ansIdx;
	incSubsequence.push_back(nums[ansIdx]);
	while (idx != -1) {
		int preNum = nums[DP[idx].second];
		incSubsequence.push_back(preNum);
		idx = DP[idx].second;
	}

	cout << ans << '\n';
	for (int i = ans-1; i >= 0; i--) {
		cout << incSubsequence[i] << ' ';
	}
}


/*
14002. 가장 긴 증가하는 부분 수열 4
https://www.acmicpc.net/problem/14002

문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.
*/ 