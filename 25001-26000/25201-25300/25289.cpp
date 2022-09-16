#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 100001

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, ans = 0; cin >> N;
	int nums[MAX] = { 0, };

	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	for (int k = -99; k < 100; k++) {
		int DP[MAX] = { 0, };
		for (int i = 1; i <= N; i++) {
			if (nums[i] - k < 1 || nums[i] - k > 100) {
				DP[nums[i]] = 1;
			}
			else {
				DP[nums[i]] = DP[nums[i] - k] + 1;
			}
			ans = max(ans, DP[nums[i]]);
		}
	}

	cout << ans << '\n';
}


/*
25289. 가장 긴 등차 부분 수열
https://www.acmicpc.net/problem/25289

문제
길이가 $N$인 수열 $A$가 주어진다. $A$의 부분 수열 중, 등차 수열인 가장 긴 부분 수열의 길이를 출력하는 프로그램을 작성하자.

부분 수열과 등차 수열이 무엇인지 잘 모르는 친구들은 친절한 준서가 준비한 아래 정의를 읽어보도록 하자.

부분 수열이란 주어진 수열에서 1개 이상의 원소를 골라 원래 순서대로 나열하여 얻은 수열을 말한다.
등차 수열이란 연속한 두 항의 차이가 모두 일정한 수열을 말한다.
예를 들어 $\lbrace1, 3, 5, 7\rbrace$은 연속한 두 항의 차이가 $3-1=5-3=7-5=2$로 일정하므로 등차 수열이다.
입력
첫째 줄에 수열의 길이 $N$이 주어진다. ($1 \leq N \leq 100\,000$)

둘째 줄에 $N$개의 정수 $A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다. ($1 \leq A_i \leq 100$)

출력
첫째 줄에 가장 긴 등차 부분 수열의 길이를 출력한다.
*/ 