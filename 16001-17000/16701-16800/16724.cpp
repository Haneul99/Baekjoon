#include <string>
#include <vector>
#include <iostream>
#include <map>
#define MAX 1001

using namespace std;

char MAP[MAX][MAX];
vector<int> graph[MAX];
pair<int, int> parents[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};//URDL
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> FIND(int x, int y) {
	if (parents[x][y] == make_pair(x, y)) return { x, y };
	return parents[x][y] = FIND(parents[x][y].first, parents[x][y].second);
}

void UNION(pair<int, int> p1, pair<int, int> p2) {
	p1 = FIND(p1.first, p1.second);
	p2 = FIND(p2.first, p2.second);

	parents[p1.first][p1.second] = p2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			parents[i][j] = { i,j };
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'U') {
				UNION(make_pair(i, j), make_pair(i + dx[0], j + dy[0]));
			}
			if (MAP[i][j] == 'R') {
				UNION(make_pair(i, j), make_pair(i + dx[1], j + dy[1]));
			}
			if (MAP[i][j] == 'D') {
				UNION(make_pair(i, j), make_pair(i + dx[2], j + dy[2]));
			}
			if (MAP[i][j] == 'L') {
				UNION(make_pair(i, j), make_pair(i + dx[3], j + dy[3]));
			}

		}
	}

	map<pair<int,int>, int> cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cnt[FIND(i, j)]++;
		}
	}
	cout << cnt.size() << '\n';
}


/*
16724. 피리 부는 사나이
https://www.acmicpc.net/problem/16724

문제
피리 부는 사나이 성우는 오늘도 피리를 분다.

성우가 피리를 불 때면 영과일 회원들은 자기도 모르게 성우가 정해놓은 방향대로 움직이기 시작한다. 성우가 정해놓은 방향은 총 4가지로 U, D, L, R이고 각각 위, 아래, 왼쪽, 오른쪽으로 이동하게 한다.

이를 지켜보던 재훈이는 더 이상 움직이기 힘들어하는 영과일 회원들을 지키기 위해 특정 지점에 ‘SAFE ZONE’ 이라는 최첨단 방음 시설을 만들어 회원들이 성우의 피리 소리를 듣지 못하게 하려고 한다. 하지만 예산이 넉넉하지 않은 재훈이는 성우가 설정해 놓은 방향을 분석해서 최소 개수의 ‘SAFE ZONE’을 만들려 한다.

성우가 설정한 방향 지도가 주어졌을 때 재훈이를 도와서 영과일 회원들이 지도 어느 구역에 있더라도 성우가 피리를 불 때 ‘SAFE ZONE’에 들어갈 수 있게 하는 ‘SAFE ZONE’의 최소 개수를 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에 지도의 행의 수를 나타내는 N(1 ≤ N ≤ 1,000)과 지도의 열의 수를 나타내는 M(1 ≤ M ≤ 1,000)이 주어진다.

두 번째 줄부터 N개의 줄에 지도의 정보를 나타내는 길이가 M인 문자열이 주어진다.

지도 밖으로 나가는 방향의 입력은 주어지지 않는다.

출력
첫 번째 줄에 ‘SAFE ZONE’의 최소 개수를 출력한다.
*/ 