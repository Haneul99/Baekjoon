#include<stdio.h>
#include<malloc.h>
#define MAX_SIZE 100000

typedef struct Node {
	int index;
	int weight;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct Queue {
	Node *cursor;
	Node *front;
	Node *rear;
}Queue;

void init(Queue *q) {
	q->cursor = NULL;
	q->front = NULL;
	q->rear = NULL;
}

void insertNode(Queue *q, int val, int index) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->index = index;
	newNode->weight = val;
	if (index==0) {
		newNode->next = NULL;
		newNode->prev = NULL;
		q->front = newNode;
		q->rear = newNode;
		q->cursor = newNode;
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
		index = q->cursor->index;
		q->front = NULL;
		q->rear = NULL;
		q->cursor = NULL;
	}// 원소가 하나일 경우
	else if (q->cursor->next == q->front) {
		index = q->cursor->index;
		q->cursor = q->cursor->next;
		q->rear = q->rear->prev;
		q->rear->next = q->front;
		q->front->prev = q->rear;
	}//끝에서 삭제
	else if (q->cursor->prev == q->rear) {
		index = q->cursor->index;
		q->cursor = q->cursor->next;
		q->front = q->front->next;
		q->rear->next = q->front;
		q->front->prev = q->rear;
	}//처음에서 삭제
	else {
		index = q->cursor->index;
		q->cursor->next->prev = q->cursor->prev;
		q->cursor->prev->next = q->cursor->next;
		q->cursor = q->cursor->next;
	}//중간에서 삭제
	return index;
}

int main() {
	int n;//number of case
	scanf("%d",&n);
	Queue q;
	int num;//number of doc
	int target;//target doc
	int pop;
	int count = 0;
	for (int i = 0; i < n; i++) {
		init(&q);
		count = 0;
		scanf("%d", &num);
		scanf("%d", &target);
		for (int j = 0; j < num; j++) {
			int x;
			scanf("%d",&x);
			insertNode(&q, x, j);
		}//node insert
		int max = 0;
		Node *temp;
		while (q.front != NULL) {
			max = 0;
			for (int j = num; j > 0; j--) {
				if (max < q.cursor->weight) {
					max = q.cursor->weight;
					temp = q.cursor;
				}
				q.cursor = q.cursor->next;
			}
			q.cursor = temp;
			pop = deleteNode(&q);
			count++;
			if (pop == target) {
				printf("%d\n", count);
				break;
			}
		}
	}
}

/*
1966. 프린터 큐
https://www.acmicpc.net/problem/1966


*/