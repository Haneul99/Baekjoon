#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>

using namespace std;
 

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, removeNode, root = 0, ans = 0; cin >> n;
	vector<int> graph[55];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == -1) root = i;
		else {
			graph[x].push_back(i);
		}
	}
	cin >> removeNode;
	queue<int> q;
	if (removeNode != root) {
		q.push(root);
	}
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		int len = graph[idx].size();
		if (len == 0 || (len == 1 && graph[idx][0] == removeNode)) {
			ans++;
		}
		for (int i = 0; i < len; i++) {
			int child = graph[idx][i];
			if (child == removeNode) continue;
			q.push(child);
		}
	}

	cout << ans << '\n';
}


/*
1068. 트리
https://www.acmicpc.net/problem/1068

문제
트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.

트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오. 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.

예를 들어, 다음과 같은 트리가 있다고 하자.



현재 리프 노드의 개수는 3개이다. (초록색 색칠된 노드) 이때, 1번을 지우면, 다음과 같이 변한다. 검정색으로 색칠된 노드가 트리에서 제거된 노드이다.



이제 리프 노드의 개수는 1개이다.

입력
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.
*/