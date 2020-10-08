#include <stdio.h>

int n, m, v;
int adj[1001][1001] = { 0, };
int queue[1001];
int B_visit[1001] = { 0, };
int D_visit[1001] = { 0, };

void BFS(int v, int vertice) {
	int front, rear, pop;
	front = rear = 0;

	printf("%d ", v);
	B_visit[v] = 1;
	queue[0] = v;
	rear++;

	while (front < rear) {
		pop = queue[front];
		front++;
		for (int i = 1; i <= vertice; i++) {
			if (adj[pop][i] == 1 && B_visit[i] == 0) {
				printf("%d ", i);
				queue[rear] = i;//front가 끝났을 때 다음 시작 정점을 저장
				rear++;
				B_visit[i] = 1;
			}
		}
	}
	
}

void DFS(int v, int vertice) {
	D_visit[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= vertice; i++) {
		if (adj[v][i] == 1 && D_visit[i] == 0) {
			DFS(i, vertice);
		}
	}
	return;
}


int main(void) {

	scanf("%d%d%d", &n, &m, &v);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	DFS(v, n);
	printf("\n");
	BFS(v, n);
}


/*
1260. DFS와 BFS
https://www.acmicpc.net/problem/1260

문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

*/