#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>

using namespace std;


int BFS(int n, int k, vector<int> coins) {
	int visit[100010] = { 0, };
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		q.push({ coins[i], 1 });
		visit[coins[i]] = 1;
	}
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < n; i++) {
			if (num + coins[i] == k) {
				return cnt + 1;
			}
			if (num + coins[i] > k || visit[num + coins[i]]) continue;
			q.push({ num + coins[i], cnt + 1 });
			visit[num + coins[i]] = 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	
	vector<int> coins;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		coins.push_back(x);
	}
	sort(coins.begin(), coins.end());
	coins.erase(unique(coins.begin(), coins.end()), coins.end());

	cout << BFS(coins.size(), k, coins) << '\n';
}


/*
2294. 동전 2
https://www.acmicpc.net/problem/2294

문제
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

메모리 초과 발생 -> 중복으로 들어오는 coin을 유니크하게 해주고, 방문 체크 해줌
*/