#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <limits.h>

#define MAX 9

using namespace std;

map<string, int> permutations;
int comb[MAX] = { 0, };
bool visit[MAX];
vector<int> nums;

int N, M; 

void permutation(int depth) {
	if (depth == M) {
		string num = "";
		for (int i = 0; i < depth; i++) {
			num += to_string(comb[i]) + " ";
		}
		if (permutations.count(num) == 0) cout << num << '\n';	
		permutations[num]++;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			comb[depth] = nums[i];
			permutation(depth + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		nums.push_back(x);
	}
	
	sort(nums.begin(), nums.end());
	permutation(0);
}


/*
15663. N과 M (9)
https://www.acmicpc.net/problem/15663

문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/ 