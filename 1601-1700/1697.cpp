#include<stdio.h>
#include<limits.h>

int n, k;
int ans = INT_MAX;

typedef struct point {
	int num;
	int idx;
}point;

point queue[200001];
int visit[200001];
int front = 0, rear = 0;

void insert(int x, int i) {
	queue[rear].num = x;
	queue[rear].idx = i;
	rear++;
}

point remove() {
	point q = queue[front];
	front++;
	return q;
}

void BFS() {
	insert(n, 0);
	while (front < rear) {
		point q = remove();
		if (q.num == k) {
			if (q.idx < ans) ans = q.idx;
		}
		else {
			if (q.idx + 1 < ans) {
				if (visit[q.num - 1] == 0 && q.num - 1 >= 0 && q.num - 1 <= 100000) {
					insert(q.num - 1, q.idx + 1);
					visit[q.num - 1] = 1;
				}
				if (visit[q.num + 1] == 0 && q.num + 1 >= 0 && q.num + 1 <= 100000) {
					insert(q.num + 1, q.idx + 1);
					visit[q.num + 1] = 1;
				}
				if (visit[q.num * 2] == 0 && q.num * 2 >= 0 && q.num * 2 <= 100000) {
					insert(q.num * 2, q.idx + 1);
					visit[q.num * 2] = 1;
				}
			}
		}//q에서 pop할 때 visit를 체크하면 segmentation fault가 생김. out of bounds 런타임에러, 범위 체크 안해도 런타임에러
	}
}

int main() {
	scanf("%d%d", &n, &k);
	BFS();
	printf("%d\n", ans);
}

/*
1697. 숨바꼭질
https://www.acmicpc.net/problem/1697

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

*/