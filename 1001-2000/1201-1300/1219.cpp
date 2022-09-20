#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 52

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, src, dst, M; cin >> N >> src >> dst >> M;
	vector <pair<int, int>> edge[MAX];
	for (int i = 0; i < M; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		edge[from].push_back({to, cost});
	}

	vector<int> earn;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		earn.push_back(x);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			edge[i][j].second -= earn[edge[i][j].first];
		}
	}

	long long dist[MAX] = { 0, };
	for (int i = 0; i < N; i++) {
		dist[i] = LONG_MAX;
	}


	dist[src] = -earn[src];
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < edge[j].size(); k++) {
				int from = j;
				int to = edge[j][k].first;
				int cost = edge[j][k].second;

				if (dist[from] == LONG_MAX) continue;
				if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
			}
		}
	}

	
	vector<int> updated;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			int from = i;
			int to = edge[i][j].first;
			int cost = edge[i][j].second;


			if (dist[from] == LONG_MAX) continue;
			if (dist[to] - earn[to] > dist[from] + cost - earn[to]) {
				updated.push_back(to);
			}
		}
	}

	bool cycle = false;
	for (int i = 0; i < updated.size(); i++) {
		bool visit[MAX] = { 0, };
		queue<int> q;
		q.push(updated[i]);
		visit[updated[i]] = true;

		while (!q.empty()) {
			int node = q.front();
			visit[node] = true;
			q.pop();
			for (int i = 0; i < edge[node].size(); i++) {
				int next = edge[node][i].first;
				if (visit[next] == false) {
					q.push(next);
				}

			}
		}
		if (visit[dst] == true) {
			cycle = true;
			break;
		}
	}

	if (dist[dst] == LONG_MAX) cout << "gg\n";
	else if (cycle) cout << "Gee\n";
	else cout << (-1) * dist[dst] << '\n';
}


/*
1219. 오민식의 고민
https://www.acmicpc.net/problem/1219

문제
오민식은 세일즈맨이다. 오민식의 회사 사장님은 오민식에게 물건을 최대한 많이 팔아서 최대 이윤을 남기라고 했다.

오민식은 고민에 빠졌다.

어떻게 하면 최대 이윤을 낼 수 있을까?

이 나라에는 N개의 도시가 있다. 도시는 0번부터 N-1번까지 번호 매겨져 있다. 오민식의 여행은 A도시에서 시작해서 B도시에서 끝난다.

오민식이 이용할 수 있는 교통수단은 여러 가지가 있다. 오민식은 모든 교통수단의 출발 도시와 도착 도시를 알고 있고, 비용도 알고 있다. 게다가, 오민식은 각각의 도시를 방문할 때마다 벌 수 있는 돈을 알고있다. 이 값은 도시마다 다르며, 액수는 고정되어있다. 또, 도시를 방문할 때마다 그 돈을 벌게 된다.

오민식은 도착 도시에 도착할 때, 가지고 있는 돈의 액수를 최대로 하려고 한다. 이 최댓값을 구하는 프로그램을 작성하시오.

오민식이 버는 돈보다 쓰는 돈이 많다면, 도착 도시에 도착할 때 가지고 있는 돈의 액수가 음수가 될 수도 있다. 또, 같은 도시를 여러 번 방문할 수 있으며, 그 도시를 방문할 때마다 돈을 벌게 된다. 모든 교통 수단은 입력으로 주어진 방향으로만 이용할 수 있으며, 여러 번 이용할 수도 있다.

입력
첫째 줄에 도시의 수 N과 시작 도시, 도착 도시 그리고 교통 수단의 개수 M이 주어진다. 둘째 줄부터 M개의 줄에는 교통 수단의 정보가 주어진다. 교통 수단의 정보는 “시작 끝 가격”과 같은 형식이다. 마지막 줄에는 오민식이 각 도시에서 벌 수 있는 돈의 최댓값이 0번 도시부터 차례대로 주어진다.

N과 M은 50보다 작거나 같고, 돈의 최댓값과 교통 수단의 가격은 1,000,000보다 작거나 같은 음이 아닌 정수이다.

출력
첫째 줄에 도착 도시에 도착할 때, 가지고 있는 돈의 액수의 최댓값을 출력한다. 만약 오민식이 도착 도시에 도착하는 것이 불가능할 때는 "gg"를 출력한다. 그리고, 오민식이 도착 도시에 도착했을 때 돈을 무한히 많이 가지고 있을 수 있다면 "Gee"를 출력한다.


출발 도시에서 earn[src]로 초기화 해줄 것.
음수사이클이 존재해서 Gee로 가기 위해서는, 해당 사이클을 통해 dst에 도달해야 함.
그러므로 음수사이클에서 업데이트 된 값 하나하나에 대해 BFS를 돌려서 dst에 도달할 수 있는 지 검사.
*/ 