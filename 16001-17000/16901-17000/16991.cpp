#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 16
#define INF 123456789

using namespace std;

int N, LAST;
vector<pair<double, double>> pos;
double DIST[MAX][MAX];
double DP[MAX][1 << MAX]; //i: 마지막으로 도착한 도시, j: status


double TSP(int city, int visited) {
	if (visited == LAST) return DIST[city][0] ? DIST[city][0] : INF;

	if (DP[city][visited] != -1) return DP[city][visited];//이미 계산된 값

	DP[city][visited] = INF;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) continue;//i번째 city가 방문돼있다면 pass
		if (DIST[city][i] == 0) continue;
		double res = TSP(i, visited | (1 << i));//i번째 city를 방문처리해서 DFS
		DP[city][visited] = min(DP[city][visited], res + DIST[city][i]);
	}

	return DP[city][visited];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout << fixed; cout.precision(6);
	cin >> N;
	LAST = (1 << N) - 1;


	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		pos.push_back({ x, y });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int Xa = pos[i].first, Ya = pos[i].second;
			int Xb = pos[j].first, Yb = pos[j].second;
			DIST[i][j] = sqrt(pow((Xb - Xa), 2) + pow((Yb - Ya), 2));
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < (1 << MAX); j++) {
			DP[i][j] = -1.0;
		}
	}

	cout << TSP(0, 1) << '\n';
}


/*
16991. 외판원 순회 3
https://www.acmicpc.net/problem/16991

문제
외판원 순회 문제는 영어로 Traveling Salesman problem (TSP) 라고 불리는 문제로 computer science 분야에서 가장 중요하게 취급되는 문제 중 하나이다. 여러 가지 변종 문제가 있으나, 여기서는 가장 일반적인 형태의 문제를 살펴보자.

1번부터 N번까지 번호가 매겨져 있는 도시들이 있고, 모든 도시 사이에는 길이 있다. 이제 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로를 계획하려고 한다. 단, 한 번 갔던 도시로는 다시 갈 수 없다. (맨 마지막에 여행을 출발했던 도시로 돌아오는 것은 예외) 이런 여행 경로는 여러 가지가 있을 수 있는데, 가장 적은 비용을 들이는 여행 계획을 세우고자 한다.

도시 A에서 도시 B로 가는 비용은 두 도시 사이의 거리와 같다. 한 도시 A의 좌표가 (xA, yA), B의 좌표가 (xB, yB)라고 한다면, 두 도시의 거리는 √((xB-xA)2 + (yB-yA)2)와 같다.

도시의 수 N과 모든 도시의 위치가 주어졌을 때, 가장 적은 비용을 들이는 외판원의 순회 여행 경로를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 수 N이 주어진다. (2 ≤ N ≤ 16) 다음 N개의 줄에는 도시의 좌표 x, y가 주어진다. 모든 좌표는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다. 두 도시의 위치가 같은 경우는 없다.

출력
첫째 줄에 외판원의 순회에 필요한 최소 비용을 출력한다. 절대/상대 오차는 10-6까지 허용한다.

기본 외판원 순회 문제와는 int/double 차이밖에 없음.
*/ 