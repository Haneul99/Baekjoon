#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, m, ans;
vector<int> chicken[31];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			chicken[i].push_back(x);
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				int localAns = 0;
				for (int t = 0; t < n; t++) {
					localAns += max(chicken[t][i], max(chicken[t][j], chicken[t][k]));
				}
				ans = max(localAns, ans);
			}
		}
	}
	cout << ans << '\n';
}


/*
16439. 치킨치킨치킨
https://www.acmicpc.net/problem/16439

문제
N명의 고리 회원들은 치킨을 주문하고자 합니다.

치킨은 총 M가지 종류가 있고 회원마다 특정 치킨의 선호도가 있습니다. 한 사람의 만족도는 시킨 치킨 중에서 선호도가 가장 큰 값으로 결정됩니다. 진수는 회원들의 만족도의 합이 최대가 되도록 치킨을 주문하고자 합니다.

시키는 치킨의 종류가 많아질수록 치킨을 튀기는 데에 걸리는 시간도 길어지기 때문에 최대 세 가지 종류의 치킨만 시키고자 합니다.

진수를 도와 가능한 만족도의 합의 최댓값을 구해주세요.

입력
첫 번째 줄에 고리 회원의 수 N (1 ≤ N ≤ 30) 과 치킨 종류의 수 M (3 ≤ M ≤ 30) 이 주어집니다.

두 번째 줄부터 N개의 줄에 각 회원의 치킨 선호도가 주어집니다.

i+1번째 줄에는 i번째 회원의 선호도 ai,1, ai,2, ..., ai,M (1 ≤ ai,j ≤ 9) 가 주어집니다.

출력
첫 번째 줄에 고리 회원들의 만족도의 합의 최댓값을 출력합니다.

회원의 수 N / 치킨 종류 M개중에 3개만 시켜먹음

*/