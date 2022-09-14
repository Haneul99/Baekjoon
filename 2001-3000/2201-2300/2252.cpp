#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 32010

using namespace std;

int N, M;
int pre[MAX] = { 0, };
bool CHECK[MAX] = { 0, };
vector<int> graph[MAX];


void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (pre[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int idx = q.front(); q.pop();
		cout << idx << " ";

		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i];
			pre[next]--;
			if (pre[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		pre[b]++;
	}
	
	topologicalSort();
}


/*
2252. 줄 세우기
https://www.acmicpc.net/problem/2252

문제
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 32,000), M(1 ≤ M ≤ 100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

출력
첫째 줄에 학생들을 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.

위상정렬!

graph[i] 가 비어있다면 앞에 와야 하는 것이 없다는 뜻 -> 출력

10 10
10 3
10 2
3 1
2 1
9 1
1 7
1 5
7 8
5 6
6 4
*/ 