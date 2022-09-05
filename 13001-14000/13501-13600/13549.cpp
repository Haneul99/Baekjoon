#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#define MAX_SIZE 100001

using namespace std;

int n, k;
int visit[MAX_SIZE] = { 0, };

int BFS() {
	int pos, cnt;
	
	deque<int> dq;//위치
	dq.push_back(n);
	visit[n] = 1;

	while (!dq.empty()) {
		pos = dq.front();
		dq.pop_front();
		if (pos == k) {
			return visit[pos] - 1;
		}

		if (pos * 2 < MAX_SIZE && visit[2 * pos] == 0) {
			dq.push_front(2 * pos);
			visit[2 * pos] = visit[pos];
		}
		if (pos + 1 < MAX_SIZE && visit[pos + 1] == 0) {
			dq.push_back(pos + 1);
			visit[pos + 1] = visit[pos] + 1;
		}
		if (pos - 1 >= 0 && visit[pos - 1] == 0) {
			dq.push_back(pos - 1);
			visit[pos - 1] = visit[pos] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	cout << BFS() << '\n';
}


/*
13549. 숨바꼭질 3
https://www.acmicpc.net/problem/13549

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.


이 문제는 일반적인 BFS로는 풀 수 없음. BFS는 모든 노드의 가중치가 같다는 전제하에 하는 것이기 때문.
그러나 순간이동은 0초가 소요되어 가중치가 더 높기 때문에 덱을 사용하여 앞쪽에 넣어주면 BFS와 동일하게 풀 수 있음.
--> 소요시간이 더 짧은것이 앞에 올 수 있으므로 가장 먼저 k에 도달하는 것이 가장 소요 시간이 적음을 보장할 수 있음.
2*x 해주는 부분이 가장 위에 와야 틀리지 않음. 우선순위가 더 높기 때문.
*/