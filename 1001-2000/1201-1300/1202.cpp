#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>

#define MAX 11

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, K;
	long long ans = 0;

	vector<int> bags;
	vector<pair<int, int>> jewels;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, p; cin >> w >> p;
		jewels.push_back({ w, p });
	}
	for (int i = 0; i < K; i++) {
		int w; cin >> w;
		bags.push_back(w);
	}

	sort(jewels.begin(), jewels.end());
	sort(bags.begin(), bags.end());

	int jewelIdx = 0;
	priority_queue <int> pq;
	for (int i = 0; i < K; i++) {
		while (jewelIdx < N && bags[i] >= jewels[jewelIdx].first) {
			pq.push(jewels[jewelIdx].second);
			jewelIdx++;
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}//가방인덱스

	cout << ans << '\n';
}


/*
1202. 보석 도둑
https://www.acmicpc.net/problem/1202

문제
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.

출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.
*/ 