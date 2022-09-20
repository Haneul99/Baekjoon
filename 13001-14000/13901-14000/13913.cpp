#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<stack>
#define MAX 100010

using namespace std;

int N, K, cnt = -1;
int pre[MAX];
vector<int> ans;

void BFS() {
	queue<int> q;
	q.push(N);
	
	while (!q.empty()) {
		cnt++;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int pos = q.front();
			q.pop();

			if (pos == K) {
				return;
			}
			if (pos + 1 <= 100000 && pre[pos + 1] == -1) {
				q.push(pos + 1);
				pre[pos + 1] = pos;
			}
			if (pos - 1 >= 0 && pre[pos - 1] == -1) {
				q.push(pos - 1);
				pre[pos - 1] = pos;
			}
			if (pos * 2 <= 100000 && pre[pos * 2] == -1) {
				q.push(pos * 2);
				pre[pos * 2] = pos;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> K;

	memset(pre, -1, sizeof(pre));
	BFS();

	cout << cnt << '\n';

	int num = K;
	while (num != N) {
		ans.push_back(num);
		num = pre[num];
	}
	ans.push_back(num);
	for (int i = ans.size() -1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
}


/*
13913. 숨바꼭질 4
https://www.acmicpc.net/problem/13913

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.

pre를 0으로 초기화하면 시작점이 0인 경우 메모리 초과.
pre 배열에 그 값에 도달하기 이전 값을 저장해두고 역추적.
*/ 