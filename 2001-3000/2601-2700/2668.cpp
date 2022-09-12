#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 110

using namespace std;

int N, ans = 0;
int nums[MAX] = { 0, };
int visit[MAX] = { 0, };
vector<int> result;


void DFS(int start, int cur) {
	if (visit[cur] == 0) {
		visit[cur] = start;
		DFS(start, nums[cur]);
	}
	else if (cur == start) {
		result.push_back(start);
		return;
	}//사이클에 해당하면 정답에 삽입
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		DFS(i, i);
	}

	ans = result.size();
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << result[i] << '\n';
	}
}


/*
2668. 숫자고르기
https://www.acmicpc.net/problem/2668

문제
세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있다. 첫째 줄의 각 칸에는 정수 1, 2, …, N이 차례대로 들어 있고 둘째 줄의 각 칸에는 1이상 N이하인 정수가 들어 있다. 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다. 이러한 조건을 만족시키도록 정수들을 뽑되, 최대로 많이 뽑는 방법을 찾는 프로그램을 작성하시오. 예를 들어, N=7인 경우 아래와 같이 표가 주어졌다고 하자.



이 경우에는 첫째 줄에서 1, 3, 5를 뽑는 것이 답이다. 첫째 줄의 1, 3, 5밑에는 각각 3, 1, 5가 있으며 두 집합은 일치한다. 이때 집합의 크기는 3이다. 만약 첫째 줄에서 1과 3을 뽑으면, 이들 바로 밑에는 정수 3과 1이 있으므로 두 집합이 일치한다. 그러나, 이 경우에 뽑힌 정수의 개수는 최대가 아니므로 답이 될 수 없다.

입력
첫째 줄에는 N(1≤N≤100)을 나타내는 정수 하나가 주어진다. 그 다음 줄부터는 표의 둘째 줄에 들어가는 정수들이 순서대로 한 줄에 하나씩 입력된다.

출력
첫째 줄에 뽑힌 정수들의 개수를 출력하고, 그 다음 줄부터는 뽑힌 정수들을 작은 수부터 큰 수의 순서로 한 줄에 하나씩 출력한다.

모든 위치에서 시작해봐야 함. 사이클을 찾는 문제.
1 2 3 4 5 6 7 이런 입력이 들어왔을 땐 모든 수가 각자 사이클을 만들기 때문에 모두에서 시작해봐야 함.
그런데 2 3 4 1 이런식으로 있을 때, 사이클에 속한 1234를 삽입하게 되면 중복 삽입이 있을 수 있기 때문에
그냥 각 숫자에서 시작해보고, 사이클을 이루면 해당 수를 삽입.
결국 어떤 숫자에서 시작해서, 돌다가 자신으로 돌아올 수 있으면 정답에 해당
*/