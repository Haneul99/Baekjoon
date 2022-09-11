#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>

using namespace std;

vector<long long> nums;
long long A, B, ans = -1;
int length;
int comb[10] = { 0, };
bool visit[10] = { 0, };

long long makeNum() {
	long long num = 0;
	for (int i = 0; i < length; i++) {
		num = num * 10 + comb[i];
	}
	return num;
}

void backtracking(int depth) {
	if (depth == length) {
		if (comb[0] == 0) return;
		long long num = makeNum();
		if (B > num) {
			ans = max(ans, num);
		}
	}
	else {
		for (int i = 0; i < length; i++) {
			if (!visit[i]) {
				comb[depth] = nums[i];
				visit[i] = true;
				backtracking(depth + 1);
				visit[i] = false;
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> A >> B;

	
	long long mod = A;
	while (mod > 0) {
		nums.push_back(mod %10);
		mod /= 10;
	}

	length = nums.size();
	backtracking(0);

	cout << ans << '\n';
}


/*
16943. 숫자 재배치
https://www.acmicpc.net/problem/16943

문제
두 정수 A와 B가 있을 때, A에 포함된 숫자의 순서를 섞어서 새로운 수 C를 만들려고 한다. 즉, C는 A의 순열 중 하나가 되어야 한다.

가능한 C 중에서 B보다 작으면서, 가장 큰 값을 구해보자. C는 0으로 시작하면 안 된다.

입력
첫째 줄에 두 정수 A와 B가 주어진다.

출력
B보다 작은 C중에서 가장 큰 값을 출력한다. 그러한 C가 없는 경우에는 -1을 출력한다.
*/