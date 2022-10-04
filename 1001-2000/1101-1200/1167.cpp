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

vector<pair<int,int>> graph[MAX];//node, dist

int V, maxNode, maxDist;
bool visit[MAX];

void DFS(int v, int length) {
	if (maxDist < length) {
		maxDist = length;
		maxNode = v;
	}

	int size = graph[v].size();
	for (int i = 0; i < size; i++) {
		int next = graph[v][i].first;
		int dist = graph[v][i].second;
		if (visit[next] == true) continue;
		visit[next] = true;
		DFS(next, length + dist);
		visit[next] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> V;

	for (int i = 1; i <= V; i++) {
		int v; cin >> v;
		while (true) {
			int node, dist; cin >> node;
			if (node == -1) break;
			cin >> dist;

			graph[v].push_back({ node, dist });
		}
	}

	visit[1] = true;
	DFS(1, 0);

	maxDist = 0;
	memset(visit, false, sizeof(visit));

	visit[maxNode] = true;
	DFS(maxNode, 0);

	cout << maxDist << '\n';
}


/*
1167. 트리의 지름
https://www.acmicpc.net/problem/1167

문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

입력
트리가 입력으로 주어진다. 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 정점 번호는 1부터 V까지 매겨져 있다.

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

1. 임의의 점에서 가장 먼 점을 구한다.(가장 바깥의 점)
2. 1번에서 구한 점에서 가장 먼 점을 구한다.
총 두 번의 DFS로 트리의 지름을 구할 수 있음.
*/ 