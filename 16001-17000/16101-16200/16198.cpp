#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <limits.h>
#include <memory.h>

#define MAX 100010

using namespace std;

int N, ans;
vector<int> v;

void backtracking(int sum) {
	if (v.size() == 2) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {
		int add = v[i - 1] * v[i + 1];
		int tmp = v[i];

		v.erase(v.begin() + i);
		backtracking(sum + add);
		v.insert(v.begin() + i, tmp);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int w; cin >> w;
		v.push_back(w);
	}

	backtracking(0);
	cout << ans << '\n';
}


/*
16198. 에너지 모으기
https://www.acmicpc.net/problem/16198

문제
N개의 에너지 구슬이 일렬로 놓여져 있고, 에너지 구슬을 이용해서 에너지를 모으려고 한다.

i번째 에너지 구슬의 무게는 Wi이고, 에너지를 모으는 방법은 다음과 같으며, 반복해서 사용할 수 있다.

에너지 구슬 하나를 고른다. 고른 에너지 구슬의 번호를 x라고 한다. 단, 첫 번째와 마지막 에너지 구슬은 고를 수 없다.
x번째 에너지 구슬을 제거한다.
Wx-1 × Wx+1의 에너지를 모을 수 있다.
N을 1 감소시키고, 에너지 구슬을 1번부터 N번까지로 다시 번호를 매긴다. 번호는 첫 구슬이 1번, 다음 구슬이 2번, ... 과 같이 매겨야 한다.
N과 에너지 구슬의 무게가 주어졌을 때, 모을 수 있는 에너지 양의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 에너지 구슬의 개수 N(3 ≤ N ≤ 10)이 주어진다.

둘째 줄에는 에너지 구슬의 무게 W1, W2, ..., WN을 공백으로 구분해 주어진다. (1 ≤ Wi ≤ 1,000)

출력
첫째 줄에 모을 수 있는 에너지의 최댓값을 출력한다.
*/ 