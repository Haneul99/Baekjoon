#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100000

typedef struct Queue {
	int arr[MAX_SIZE];
	int front;
	int back;
}Queue;

void InitQueue(Queue *q) {
	q->front = -1;
	q->back = -1;
}

void empty(Queue *q) {
	if (q->front > q->back || q->front == -1) printf("%d\n", 1);
	else printf("%d\n", 0);
}

void push(Queue *q, int x) {
	if (q->front == -1) {
		q->front = 0;
		q->back = 0;
		q->arr[q->back] = x;
	}
	else {
		q->arr[q->back + 1] = x;
		q->back++;
	}
}

void pop(Queue *q) {
	if (q->front > q->back || q->front == -1) printf("%d\n", -1);
	else {
		printf("%d\n", q->arr[q->front]);
		q->front++;
	}
}

void size(Queue *q) {
	if (q->front > q->back || q->front == -1) printf("%d\n", 0);
	else {
		printf("%d\n", q->back - q->front + 1);
	}
}

void printFront(Queue *q) {
	if (q->front > q->back || q->front == -1) printf("%d\n", -1);
	else {
		printf("%d\n", q->arr[q->front]);
	}
}

void printBack(Queue *q) {
	if (q->front > q->back || q->front == -1) printf("%d\n", -1);
	else {
		printf("%d\n", q->arr[q->back]);
	}
}


int main() {
	Queue queue;
	InitQueue(&queue);
	int n;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		char str[15];
		int x;
		scanf(" %s", &str);
		if (strcmp(str,"push") == 0) {
			scanf(" %d", &x);
			push(&queue, x);
		}
		else if (strcmp(str, "pop") == 0) {
			pop(&queue);
		}
		else if (strcmp(str, "size") == 0) {
			size(&queue);
		}
		else if (strcmp(str, "empty") == 0) {
			empty(&queue);
		}
		else if (strcmp(str, "front") == 0) {
			printFront(&queue);
		}
		else {
			printBack(&queue);
		}
	}
}

/*
10845. 큐
https://www.acmicpc.net/problem/10845

문제
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


check when queue is null!
if there's no push, it's null
*/