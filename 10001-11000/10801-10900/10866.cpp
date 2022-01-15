#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct Deque {
	Node *front;
	Node *rear;
	int size;
}Deque;

void init(Deque *d) {
	d->front = NULL;
	d->rear = NULL;
	d->size = 0;
}

void push_front(Deque *d, int x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	if (d->front == NULL || d->rear == NULL) {
		d->front = newNode;
		d->rear = newNode;
		d->size++;
	}
	else {
		newNode->next = d->front;
		newNode->prev = NULL;
		d->front->prev = newNode;
		d->front = newNode;
		d->size++;
	}
}

void push_back(Deque *d, int x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	if (d->front == NULL || d->rear == NULL) {
		d->front = newNode;
		d->rear = newNode;
		d->size++;
	}
	else {
		newNode->next = NULL;
		newNode->prev = d->rear;
		d->rear->next = newNode;
		d->rear = newNode;
		d->size++;
	}
}

void pop_front(Deque *d) {
	if (d->front == NULL || d->rear == NULL) {
		printf("-1\n");
		return;
	}
	printf("%d\n", d->front->data);
	if (d->size == 1) {
		d->front = NULL;
		d->rear = NULL;
	}
	else {
		d->front = d->front->next;
		d->front->prev = NULL;
	}
	d->size--;
}

void pop_back(Deque *d) {
	if (d->front == NULL || d->rear == NULL) {
		printf("-1\n");
		return;
	}
	printf("%d\n", d->rear->data);
	if (d->size == 1) {
		d->front = NULL;
		d->rear = NULL;
	}
	else {
		d->rear = d->rear->prev;
		d->rear->next = NULL;
	}
	d->size--;
}

void empty(Deque *d) {
	if (d->front == NULL || d->rear == NULL) printf("1\n");
	else printf("0\n");
}


int main() {
	Deque d;
	init(&d);
	char cmd[15];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %s", cmd);
		if (strcmp(cmd, "push_front") == 0) {
			int n;
			scanf("%d", &n);
			push_front(&d, n);
		}
		else if (strcmp(cmd, "push_back") == 0) {
			int n;
			scanf("%d", &n);
			push_back(&d, n);
		}
		else if (strcmp(cmd, "pop_front") == 0) {
			pop_front(&d);
		}
		else if (strcmp(cmd, "pop_back") == 0) {
			pop_back(&d);
		}
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", d.size);
		}
		else if (strcmp(cmd, "empty") == 0) {
			empty(&d);
		}
		else if (strcmp(cmd, "front") == 0) {
			if (d.front == NULL) printf("-1\n");
			else printf("%d\n", d.front->data);
		}
		else if (strcmp(cmd, "back") == 0) {
			if (d.rear == NULL) printf("-1\n");
			else printf("%d\n", d.rear->data);
		}
	}
}

/*
10866. 덱
https://www.acmicpc.net/problem/10866

문제
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

Doubly Linked List

*/