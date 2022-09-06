#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>

using namespace std;

int A, B, C;
int visit[210][210][210] = { 0, };
vector<int> ans;

void BFS() {
	queue<pair<pair<int, int>, int>> q; // a,b,c
	q.push({ { 0, 0 }, C });

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visit[a][b][c]) continue;
		visit[a][b][c] = 1;

		//첫 번째 물통이 비어있을 때 세 번째 물통의 용량
		if (a == 0) ans.push_back(c);

		//a->b
		if (a + b > B) q.push({ { a + b - B, B }, c });
		else q.push({ {0, a + b}, c });

		//a->c
		if (a + c > C) q.push({ {a + c - C, b}, C });
		else q.push({ {0, b}, a + c });

		//b->a
		if (b + a > A) q.push({ { A, b + a - A }, c });
		else q.push({ {b + a, 0}, c });

		//b->c
		if (b + c > C) q.push({ {a, b + c - C}, C });
		else q.push({ {a, 0}, b + c });

		//c->a
		if (c + a > A) q.push({ { A, b }, c + a - A });
		else q.push({ {c + a, b}, 0 });

		//c->b
		if (c + b > B) q.push({ {a,B }, c + b - B });
		else q.push({ {a, b + c}, 0 });
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;

	BFS();

	sort(ans.begin(), ans.end());
	int len = ans.size();
	for (int i = 0; i < len; i++) {
		cout << ans[i] << ' ';
	}
}


/*
2251. 물통
https://www.acmicpc.net/problem/2251

문제
각각 부피가 A, B, C(1≤A, B, C≤200) 리터인 세 개의 물통이 있다. 처음에는 앞의 두 물통은 비어 있고, 세 번째 물통은 가득(C 리터) 차 있다. 이제 어떤 물통에 들어있는 물을 다른 물통으로 쏟아 부을 수 있는데, 이때에는 한 물통이 비거나, 다른 한 물통이 가득 찰 때까지 물을 부을 수 있다. 이 과정에서 손실되는 물은 없다고 가정한다.

이와 같은 과정을 거치다보면 세 번째 물통(용량이 C인)에 담겨있는 물의 양이 변할 수도 있다. 첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 세 정수 A, B, C가 주어진다.

출력
첫째 줄에 공백으로 구분하여 답을 출력한다. 각 용량은 오름차순으로 정렬한다.
*/