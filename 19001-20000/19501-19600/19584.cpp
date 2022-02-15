#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#define MAX 200020

using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first < b.first.first) {
		return true;
	}
	else if (a.first.first == b.first.first) {
		return a.first.second < b.first.second;
	}
	else { 
		return false; 
	}
}//start 순으로 정렬

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	int building[MAX];
	vector<pair<pair<int,int>, int>> road;//start, end, cost

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//end, cost

	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &building[i]);
	}

	for (int i = 0; i < m; i++) {
		int v1, v2, cost;
		scanf("%d%d%d", &v1, &v2, &cost);
		int start = min(building[v1], building[v2]);
		int end = max(building[v1], building[v2]);
		road.push_back({ {start, end}, cost });
	}

	sort(road.begin(), road.end());

	long long ans = 0;
	int index = 0;
	long long cost = 0;
	while (1) {		
		int start = road[index].first.first;
		int end = road[index].first.second;
		if (pq.empty() || start <= pq.top().first) {
			pq.push({ end, road[index].second });
			cost += road[index].second;
			index++;
			ans = max(ans, cost);
		}//push
		else if (start > pq.top().first) {
			cost -= pq.top().second;
			pq.pop();
		}//pop
		if (index >= m) break;
	}
	printf("%lld\n", ans);
}


/*
19584. 난개발
https://www.acmicpc.net/problem/19584

문제
이 사실은 대회에 참가하고 있는 여러분들만 알고 있는 사실이다. 방금 외계인들이 지구를 정복했고 서울시청과 서울시의회를 장악했다. 이들은 인간들이 통근과 통학으로 고통받게 하려고 대규모 토목공사를 기획하고 있는데, 바로 지상에 서울 지하철 10호선을 짓는 것이다.

‘10호선을 만들어 준다니 좋은 거 아닌가?’라고 생각할지도 모르겠지만, 이들의 목적은 따로 있다. 바로 도로들을 철도노선으로 전부 가로막아 버리는 것이다. 이렇게 되면 서울의 남북을 가로지르는 버스 노선은 전부 사라지게 된다.

좋은 소식은 여러분들이 이 계획을 알고 있다는 것이다.

외계인들은 뛰어난 건축 기술을 갖고 있지만 x축에 평행하도록 철길을 놓을 때 가장 빠르게 철길을 완성할 수 있으므로 그렇게 할 것이다. 철길의 시점과 종점은 서울 바깥에 있으며, 철길과 도로가 만나면 도로는 전부 철거된다. 도로의 시점이나 종점이 철길과 만나는 경우에도 도로가 철거된다.

외계인들은 철거될 도로들의 통행량의 합이 가장 큰 곳에 철길을 놓으려 한다.

서울시내 주요 장소 N개의 직교좌표계상의 좌표와, 이를 잇는 도로 총 M개의 정보가 주어지면 외계인들이 어디에 10호선을 지을지 예상하는 프로그램을 작성하자.

입력
첫째 줄에는 N과 M이 주어진다. (2 ≤ N ≤ 2 × 105, 1 ≤ M ≤ 2 × 105)

이후 N줄에 걸쳐 한 줄에 하나씩 서울시내 주요 장소들의 x좌표와 y좌표가 공백으로 구분되어 주어진다. 좌표는 정수이며 그 절댓값은 109를 넘지 않는다.

이후 M줄에 걸쳐 한 줄에 하나씩 세 정수 ui, vi, ci가 주어진다. (1 ≤ ui, vi ≤ N, ui ≠ vi, 0 ≤ ci ≤ 109) 이는 ui번째 장소와 vi번째 장소를 잇는 통행량 ci의 도로가 있음을 의미한다. 각 도로는 직선형으로 ui번째 장소와 vi번째 장소를 최단 거리로 연결해 준다. 도로는 교차할 수는 있으나, 한 도로로 주행 중 다른 도로로 진입할 수는 없다. 같은 장소를 잇는 도로가 여러 개 존재할 수 있다.

출력
외계인들이 철도노선을 지었을 때 최대로 파괴되는 통행량을 출력한다.



배열은 start 순으로
우선순위큐는 end 순으로 정렬

배열의 start와 우선순위큐의 end 값에서
start가 더 작으면 우선순위큐에 push, end 값이 더 작으면 pop
*/