#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 110

using namespace std;

vector<pair<int, int>>edge[MAX];
long long dist[MAX];
int pre[MAX];

int N, M; 


bool BFS(int start) {
	queue<int> q;
	q.push(start);
	
	bool visit[MAX] = { 0, };
	visit[start] = true;
	
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < edge[node].size(); i++) {
			int next = edge[node][i].first;

			if (visit[next] == false) {
				q.push(next);
				visit[next] = true;
			}
		}
	}
	if (visit[N] == true) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	memset(pre, -1, sizeof(pre));

	for (int i = 0; i <= N; i++) {
		dist[i] = LONG_MAX;
	}
	for (int i = 0; i < M; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		edge[from].push_back({to, -cost});
	}
	
	dist[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < edge[j].size(); k++) {
				int from = j;
				int to = edge[j][k].first;
				int cost = edge[j][k].second;

				if (dist[from] == LONG_MAX) continue;
				if (dist[to] > dist[from] + cost) {
					pre[to] = from;
					dist[to] = dist[from] + cost;
				}
			}
		}
	}

	vector<int> updated;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			int from = i;
			int to = edge[i][j].first;
			int cost = edge[i][j].second;

			if (dist[from] == LONG_MAX) continue;
			if (dist[to] > dist[from] + cost) {
				updated.push_back(to);
			}
		}
	}

	bool cycle = false;
	if(updated.size() != 0) {
		for (int i = 0; i < updated.size(); i++) {
			if (BFS(updated[i])) {
				cout << "-1\n";
				cycle = true;
				break;
			}
		}
	}//사이클 발생	
	if (!cycle) {
		if (dist[N] == LONG_MAX) cout << "-1\n";
		else {
			vector<int> ans;
			int idx = N;
			while (idx != -1) {
				ans.push_back(idx);
				idx = pre[idx];
			}
			for (int i = ans.size() - 1; i >= 0; i--) {
				cout << ans[i] << ' ';
			}
		}
	}//사이클이 발생하지 않음.
}


/*
1738. 골목길
https://www.acmicpc.net/problem/1738

문제
민승이는 놀러가기 위해 집을 나섰다. 민승이네 집에서 코레스코 콘도까지 가기 위해서는 복잡하게 얽혀있는 골목길들을 통과해야 한다.

그런데, 어떤 길에는 깡패가 서식하고 있어, 그 길을 지나게 되면 깡패에게 일정한 양의 금품을 갈취당하게 된다. 그런가하면, 어떤 길에는 지나가던 행인들이 흘리고 간 금품들이 떨어져 있어, 그 길을 지나게 되면 일정한 양의 금품을 획득하게 된다. 한 번 지나간 길을 다시 방문하더라도 금품을 갈취당하거나 획득한다.

골목길의 연결 상태와, 각 골목길을 지날 때 갈취당하거나 획득하게 되는 금품의 양이 주어졌을 때, 민승이가 최대한 유리한 경로를 따라 집에서 코레스코 콘도까지 가기 위해서는 어떻게 해야 하는지 출력하는 프로그램을 작성하시오.

보유 중인 금품의 양이 음수가 될 수 있다. 최대한 유리한 경로 또는 최적의 경로는 민승이네 집에서 출발하여 코레스코 콘도에 도착하는 경로 중 금품의 양이 최대가 되는 경로이다.

입력
첫째 줄에 골목길들이 교차하는 지점의 개수 n (2 ≤ n ≤ 100)과 골목길의 개수 m (1 ≤ m ≤ 20,000) 이 차례로 주어진다. 이어지는 m개의 행에 각각의 골목길을 나타내는 세 정수 u, v, w가 차례로 주어진다. 이는 u번 교차점에서 v번 교차점으로 이동할 수 있는 골목길이 나있다는 의미이다. 즉, 주어지는 골목길들은 기본적으로 모두 일방통행로이다. w (0 ≤ |w| ≤ 1,000)는 이 길을 지날 때 갈취당하거나 획득하게 되는 금품의 양이다. 음수는 갈취, 양수는 획득을 뜻한다.

골목길의 교차점 번호는 1이상 n이하의 정수이다. 민승이네 집은 1번 교차점에 있고, 이곳 코레스코 콘도는 n번 교차점에 있다.

출력
최적의 경로를 구할 수 있다면 민승이네 집부터 코레스코 콘도까지 가는 동안 거치게 되는 교차점들의 번호를 공백 하나를 사이에 두고 차례로 출력하면 된다. 그런데, 경우에 따라서는 최적의 경로라는 것이 존재하지 않는 상황이 발생한다. 어떠한 경우에 그런 상황이 발생하는지 생각해 보자. 그러한 경우에는 -1을 출력하도록 한다.

최적의 경로가 여러 개 존재할 때는 아무거나 출력해도 된다.

금품의 양이 최대가 되는 값
음수는 갈취 양수는 획득. (-1)을 곱해서 넣어야 함.
최솟값을 찾는 것이기 때문.
*/ 