#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 1010

using namespace std;

int src, dst;
int N, M;
int visit[MAX];
vector<int> graph[MAX];

int BFS() {
	queue<pair<int, int>> q;
	if (src == dst) return 0;
	q.push({ src, 0 });
	visit[src] = 0;

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < graph[num].size(); i++) {
			int nnum = graph[num][i];
			if (nnum == dst) {
				return cnt + 1;
			}
			if (visit[nnum]) continue;
			q.push({ nnum, cnt + 1 });
			visit[nnum] = 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> src >> dst;
	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << BFS() << '\n';
}


/*
14496. 그대, 그머가 되어
https://www.acmicpc.net/problem/14496

문제
선린에 합격한 대호에게는 큰 고민이 있다. 대호는 중학교 3년 내내 공부만 했기 때문에, 요즘 학생들이 사용하는 ‘야민정음’에 대해서는 문외한이다. 친구들의 대화에 끼고 싶은 대호는 야민정음을 공부하기로 했다.

야민정음이란, 비슷한 모양의 글자를 원래 문자 대신에 사용하는 것을 일컫는다. 예를 들어, ‘그대’는 ‘그머’로, ‘팔도비빔면’은 ‘괄도네넴댼’으로, ‘식용유’는 ‘식용윾’으로, ‘대호’는 ‘머호’로 바꿀 수 있다. 아무 문자나 치환할 수 있는 건 아니며 치환이 가능한 몇 개의 문자들이 정해져있다.

예를 들어보자. (a, b), (a, c), (b, d), (c, d)가 주어지는 경우, a를 d로 바꾸는 방법은 a-b-d, a-c-d로 2개가 있다. (a, b), (b, c), (a, c)가 주어지는 경우, a를 c로 바꾸는 방법은 a-b-c, a-c의 2개가 있다. 하지만 이 경우에는 치환횟수에 차이가 생기게 된다.

머호는 문자 a를 문자 b로 바꾸려하고, N개의 문자와 치환 가능한 문자쌍 M개가 있다. 머호에게 a를 b로 바꾸기 위한 치환의 최소 횟수를 구해서 머호에게 알려주자!

프로그램 작성의 편의를 위해, 머호가 공부하는 모든 문자는 자연수로 표현되어 주어진다.

입력
첫째 줄에 머호가 바꾸려 하는 문자 a와 b가 주어진다. 둘째 줄에 전체 문자의 수 N과 치환 가능한 문자쌍의 수 M이 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ M ≤ 10,000) 이후 M개의 줄에 걸쳐 치환 가능한 문자쌍이 주어진다. 모든 문자는 N이하의 자연수로 표현된다.

출력
a를 b로 바꾸기 위해 필요한 최소 치환 횟수를 출력한다. 치환이 불가능한 경우는 –1을 출력한다.
*/