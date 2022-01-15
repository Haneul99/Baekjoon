#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int T, V, E, to, from;
int check[20002];
vector<int> v[20002];

bool dfs(int pos, int color)
{
	check[pos] = color;

	for (int i = 0; i < v[pos].size(); i++)
	{
		int next = v[pos][i];
		if (check[next] == color) return false;
		if (check[next] == -1 && !dfs(next, !color)) return false;
	}
	return true;
}


int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &V, &E);

		fill(check, check + 20002, -1);

		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &to, &from);
			v[to].push_back(from);
			v[from].push_back(to);
		}

		int graph = 1;

		for (int i = 1; i <= V; i++)
			if (check[i] == -1 && !dfs(i, 1))
			{
				graph = 0;
				break;
			}
		graph ? printf("YES\n") : printf("NO\n");

		for (int i = 0; i <= 20001; i++)
			v[i].clear();
	}
	return 0;
}



/*
int v, e;


int BFS(int ver, bool adj[][20001], short visit[]) {
	int front, rear, pop;
	int queue[20001];
	front = rear = 0;
	queue[0] = ver;
	rear++;
	visit[ver] = 1;
	int check = 1;

	printf("front: %d, rear: %d\n", front, rear);
	while (front < rear) {
		pop = queue[front];
		front++;
		for (int i = 1; i <= v; i++) {
			printf("visit[%d]: %d\n", i, visit[i]);
			if (adj[pop][i] == 1 && visit[i] == 0) {
				if (visit[pop] == 1) visit[i] = 2;
				else if (visit[pop] == 2) visit[i] = 1;;
				queue[rear] = i;
				rear++;
			}
			if (adj[pop][i] == 1 && visit[pop] == visit[i]) {
				check = 0;
				return check;
			}
		}
	}
	return check;
}


int main(void) {
	int n;
	scanf("%d", &n);
	for (int t = 0; t < n; t++) {
		int chk = 1;
		bool adj[20001][20001] = { 0 };
		short visit[20001] = { 0 };
		scanf("%d%d", &v, &e);
		for (int i = 1; i <= e; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a][b] = 1;
			adj[b][a] = 1;
		}
		int check = BFS(1, adj,visit);
		for(int i=1;i<=v;i++){
			if (check == 0) break;
			if (visit[i] == 0) check = BFS(i,adj, visit);
		}

		if (check == 1) printf("YES\n");
		else printf("NO\n");
	}
}
*/

/*
1707. 이분 그래프
https://www.acmicpc.net/problem/1707

문제
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K(2≤K≤5)가 주어진다. 각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)가 빈 칸을 사이에 두고 순서대로 주어진다. 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호가 빈 칸을 사이에 두고 주어진다.

출력
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.


C로 구현할 때는 메모리가 너무 커서 메모리 초과, 구현할 수 없었음.
대신 C++의 벡터를 사용.
이분 그래프는 자신은 1, 인접한 노드에는 2를 칠하고, 자신과 인접했는데 색이 같다면 이분 그래프가 아님.

*/