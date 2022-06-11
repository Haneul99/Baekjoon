#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n; 
vector<int> trees;
vector<int> grows;
vector<pair<int, int>> set;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

void init() {
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		trees.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		grows.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		set.push_back({ grows[i], trees[i] });
	}
	sort(set.begin(), set.end(), cmp);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	init();

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (set[i].second + set[i].first*i);
	}

	cout << ans << '\n';
}




/*
14247. 나무 자르기
https://www.acmicpc.net/problem/14247

문제
영선이는 나무꾼으로 나무를 구하러 오전에 산에 오른다. 산에는 n개의 나무가 있는데, 영선이는 하루에 한 나무씩 n일 산에 오르며 나무를 잘라갈 것이다. 하지만 이 산은 영험한 기운이 있어 나무들이 밤만 되면 매우 빠른 속도로 자라는데, 그 자라는 길이는 나무마다 다르다.

따라서, 어느 나무를 먼저 잘라가느냐에 따라서 총 구할 수 있는 나무의 양이 다른데,

나무의 처음 길이와 하루에 자라는 양이 주어졌을 때, 영선이가 얻을 수 있는 최대 나무양을 구하시오.

참고로, 자른 이후에도 나무는 0부터 다시 자라기 때문에 같은 나무를 여러 번 자를 수는 있다.

입력
첫째 줄에는 나무의 개수 n개가 있다.(1≤n≤100,000) 나무는 1번부터 n번까지 있다.

다음 줄에는 첫날 올라갔을 때 나무의 길이들 Hi가 n개가 순서대로 주어진다.(1≤Hi≤100,000)

그 다음 줄에는 나무들이 자라는 길이 Ai가 n개가 순서대로 주어진다.(1≤Ai≤10,000)

출력
영선이가 나무를 잘라서 구할 수 있는 최대 양을 출력하시오.

나무가 느리게 자라는 순서대로 정렬
*/