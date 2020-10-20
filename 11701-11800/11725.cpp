#include<stdio.h>
#include<malloc.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;


typedef struct LinkedList {
	Node *head;
	Node *tail;
}LinkedList;

int n;
LinkedList list[100001];
int parent[100001];
int visit[100001];
int queue[100001];
int front = 0, rear = 0;

void init() {
	for (int i = 0; i < n; i++) {
		list[i].head = NULL;
		list[i].tail = NULL;
	}
}

void insertNode(int start, int x) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	if (list[start].head == NULL) {
		list[start].head = newNode;
		list[start].tail = newNode;
	}
	else {
		list[start].tail->next = newNode;
		list[start].tail = newNode;
	}
}

void insert(int x) {
	queue[rear] = x;
	rear++;
}


void bfs() {
	visit[1] = 1;
	Node *temp = list[1].head;
	while(temp!=NULL) {
		insert(temp->data);
		parent[temp->data] = 1;
		temp = temp->next;
	}
	while (front < rear) {
		int p = queue[front];
		temp = list[p].head;
		front++;
		visit[p] = 1;
		while(temp!=NULL){
			if (visit[temp->data] == 0) {
				insert(temp->data);
				parent[temp->data] = p;
			}
			temp = temp->next;
		}
	}
}


int main() {
	init();
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x1, x2;
		scanf("%d%d", &x1, &x2);
		insertNode(x1, x2);
		insertNode(x2, x1);
	}

	bfs();
	for (int i = 2; i <= n; i++)
		printf("%d\n", parent[i]);
}

/*
11725. 트리의 부모 찾기
https://www.acmicpc.net/problem/11725

문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.


연결리스트로 각 연결된 정점에 대한 정보를 저장함(인접리스트 만들 듯)
이진트리라는 보장이 없기 때문에 동적 할당을 통해 연결리스트를 구현해야 한다.
1부터 시작해서 bfs, 1이랑 연결되어 있는 것에 대해 다시 bfs를 실행하는 방식
*/