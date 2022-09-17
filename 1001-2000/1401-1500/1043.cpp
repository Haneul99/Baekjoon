#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 51

using namespace std;

int N, M, ans;
int parents[MAX] = { 0, };
vector<int> knowTruth;
vector<int> party[MAX];

int FIND(int x) {
	if (parents[x] == x) return x;
	return x = FIND(parents[x]);
} // 부모를 찾는 함수

void UNION(int x, int y) {
	x = FIND(x);
	y = FIND(y);
	parents[x] = y;
} // 두 그룹을 합치는 함수

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	int trueCnt; cin >> trueCnt;
	for (int i = 0; i < trueCnt; i++) {
		int x; cin >> x;
		knowTruth.push_back(x);
	}

	for (int i = 0; i < N; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int attendee; cin >> attendee;
		int first; cin >> first;
		party[i].push_back(first);
		for (int j = 1; j < attendee; j++) {
			int num; cin >> num;
			UNION(first, num);
			party[i].push_back(num);
		}
	}

	for (int i = 0; i < M; i++) {
		bool flag = true;
		for (int j = 0; j < party[i].size(); j++) {
			if (!flag) break;
			int p1 = party[i][j];
			for (int k = 0; k < trueCnt; k++) {
				int p2 = knowTruth[k];
				if (FIND(p1) == FIND(p2)) {
					flag = false;
					break;
				}
			}
		}
		if (flag) ans++;
	}
	cout << ans << '\n';
}


/*
1043. 거짓말
https://www.acmicpc.net/problem/1043

문제
지민이는 파티에 가서 이야기 하는 것을 좋아한다. 파티에 갈 때마다, 지민이는 지민이가 가장 좋아하는 이야기를 한다. 지민이는 그 이야기를 말할 때, 있는 그대로 진실로 말하거나 엄청나게 과장해서 말한다. 당연히 과장해서 이야기하는 것이 훨씬 더 재미있기 때문에, 되도록이면 과장해서 이야기하려고 한다. 하지만, 지민이는 거짓말쟁이로 알려지기는 싫어한다. 문제는 몇몇 사람들은 그 이야기의 진실을 안다는 것이다. 따라서 이런 사람들이 파티에 왔을 때는, 지민이는 진실을 이야기할 수 밖에 없다. 당연히, 어떤 사람이 어떤 파티에서는 진실을 듣고, 또다른 파티에서는 과장된 이야기를 들었을 때도 지민이는 거짓말쟁이로 알려지게 된다. 지민이는 이런 일을 모두 피해야 한다.

사람의 수 N이 주어진다. 그리고 그 이야기의 진실을 아는 사람이 주어진다. 그리고 각 파티에 오는 사람들의 번호가 주어진다. 지민이는 모든 파티에 참가해야 한다. 이때, 지민이가 거짓말쟁이로 알려지지 않으면서, 과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N과 파티의 수 M이 주어진다.

둘째 줄에는 이야기의 진실을 아는 사람의 수와 번호가 주어진다. 진실을 아는 사람의 수가 먼저 주어지고 그 개수만큼 사람들의 번호가 주어진다. 사람들의 번호는 1부터 N까지의 수로 주어진다.

셋째 줄부터 M개의 줄에는 각 파티마다 오는 사람의 수와 번호가 같은 방식으로 주어진다.

N, M은 50 이하의 자연수이고, 진실을 아는 사람의 수는 0 이상 50 이하의 정수, 각 파티마다 오는 사람의 수는 1 이상 50 이하의 정수이다.

출력
첫째 줄에 문제의 정답을 출력한다.

진실을 아는 사람들이 속한 곳은 다 진실을 들어야 함.
분리 집합. union find ?
*/ 