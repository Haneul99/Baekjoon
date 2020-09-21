#include<stdio.h>
#include<malloc.h>
#define MAX_SIZE 500000

typedef struct Node {
	int index;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct Queue {
	Node *front;
	Node *rear;
}Queue;

void init(Queue *q) {
	q->front = NULL;
	q->rear = NULL;
}

void insertNode(Queue *q, int index) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->index = index;
	if (index==1) {
		newNode->next = NULL;
		newNode->prev = NULL;
		q->front = newNode;
		q->rear = newNode;
	}
	else {
		newNode->next = NULL;
		q->rear->next = newNode;
		newNode->prev = q->rear;
		q->rear = newNode;
		q->rear->next = q->front;
		q->front->prev = q->rear;
	}
}

int deleteNode(Queue *q) {
	int index = -1;
	if (q->rear == NULL) return index;
	else if (q->front == q->rear) {
		index = q->front->index;
		q->front = NULL;
		q->rear = NULL;
	}
	else {
		index = q->front->index;
		q->rear->next = q->front->next;
		q->front->next->prev = q->rear;
		q->rear = q->rear->next;
		q->front = q->front->next->next;
		q->front->prev = q->rear;
	}//delete front, front->next => rear->next
	return index;
}
//delete and move last

int main() {
	int n;
	scanf("%d", &n);
	Queue q;
	init(&q);
	for (int i = 1; i <= n; i++) {
		insertNode(&q, i);
	}//create Queue

	while (q.front != q.rear) {
		deleteNode(&q);
	}
	printf("%d\n", q.front->index);

}

/*
2163. 카드2
https://www.acmicpc.net/problem/2164

문제
N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.

이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 우선, 제일 위에 있는 카드를 바닥에 버린다. 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다. 1을 버리면 234가 남는다. 여기서 2를 제일 아래로 옮기면 342가 된다. 3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다. 마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.

N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(1≤N≤500,000)이 주어진다.

출력
첫째 줄에 남게 되는 카드의 번호를 출력한다.

*/