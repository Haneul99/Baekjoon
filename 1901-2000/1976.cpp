#include<stdio.h>
#include<vector>

using namespace std;

int n, m;
int map[201];
vector<int> plan;

int find(int x) {
	if (map[x] == x) return x;//서로소 집합
	return map[x] = find(map[x]);//다른 그룹에 합쳐진 집합 ex. map[13] = 5일 때, 루트 노드를 찾아가는 것. map[5] = 5이면 그대로 5를 return, 아니면 또 다시 map[5]의 부모 노드를 찾아감
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	map[y] = x;
}

//union find -> find는 해당 원소가 속한 집합의 대표값을 return. 즉, 두 원소의 find가 같다면 같은 집합에 속해있을 것

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		map[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int link;
			scanf("%d", &link);
			if (link) {
				if (find(i) != find(j)) 
					Union(i, j);//다른 집합인 경우
			}
		}
	}
	int start;
	scanf("%d", &start);
	start = find(start);
	for (int i = 0; i < m - 1; i++) {
		int city;
		scanf("%d", &city);
		if (start != find(city)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}


/*
1976. 여행 가자
https://www.acmicpc.net/problem/1976

문제
동혁이는 친구들과 함께 여행을 가려고 한다. 한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다. 동혁이의 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 알아보자. 물론 중간에 다른 도시를 경유해서 여행을 할 수도 있다. 예를 들어 도시가 5개 있고, A-B, B-C, A-D, B-D, E-A의 길이 있고, 동혁이의 여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D라는 여행경로를 통해 목적을 달성할 수 있다.

도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때 가능한지 여부를 판별하는 프로그램을 작성하시오. 같은 도시를 여러 번 방문하는 것도 가능하다.

입력
첫 줄에 도시의 수 N이 주어진다. N은 200이하이다. 둘째 줄에 여행 계획에 속한 도시들의 수 M이 주어진다. M은 1000이하이다. 다음 N개의 줄에는 N개의 정수가 주어진다. i번째 줄의 j번째 수는 i번 도시와 j번 도시의 연결 정보를 의미한다. 1이면 연결된 것이고 0이면 연결이 되지 않은 것이다. A와 B가 연결되었으면 B와 A도 연결되어 있다. 마지막 줄에는 여행 계획이 주어진다. 도시의 번호는 1부터 N까지 차례대로 매겨져 있다.

출력
첫 줄에 가능하면 YES 불가능하면 NO를 출력한다.

*/