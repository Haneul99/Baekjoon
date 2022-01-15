#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX_SIZE 100000

typedef struct ListNode {
	char data;
	struct ListNode *pre;
	struct ListNode *next;
}ListNode;

typedef struct LinkedList {
	ListNode *frontNode;
	ListNode *backNode;
	ListNode *head;
	ListNode *tail;
	ListNode *cursor;
}LinkedList;

void Init(LinkedList *list) {
	ListNode *frontNode = (ListNode *)malloc(sizeof(ListNode));
	ListNode *backNode = (ListNode *)malloc(sizeof(ListNode));
	list->frontNode = frontNode;
	list->backNode = backNode;
	list->cursor = list->frontNode;
	list->head = list->frontNode;
	list->tail = list->backNode;
	list->frontNode->next = list->backNode;
	list->backNode->pre = list->frontNode;
}

void insertNode(LinkedList *list, char x) {
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = x;
	if (list->head == list->frontNode) {
		list->head = newNode;
		list->tail = newNode;
		list->cursor = newNode;
		list->frontNode->next = newNode;
		list->backNode->pre = newNode;
		newNode->next = list->backNode;
		newNode->pre = list->frontNode;
	}
	else {
		list->tail->next = newNode;
		newNode->pre = list->tail;
		list->tail = newNode;
		list->cursor = newNode;
		newNode->next = list->backNode;
		list->backNode->pre = newNode;
	}
}

void moveLeft(LinkedList *list) {
	if (list->frontNode == list->cursor) return;
	else {
		list->cursor = list->cursor->pre;
	}
}

void moveRight(LinkedList *list) {
	if (list->backNode == list->cursor) return;
	else {
		list->cursor = list->cursor->next;
	}
}

void removeChar(LinkedList *list) {
	if (list->cursor == list->frontNode) return;
	else {
		if (list->cursor == list->head) {
			list->frontNode->next = list->head->next;
			list->head->next->pre = list->frontNode;
			list->head = list->head->next;
			list->cursor = list->frontNode;
		}//첫번째 노드 삭제
		else if (list->cursor==list->backNode) {
			list->cursor->pre->next = list->backNode;
			list->backNode->pre = list->cursor->pre;
			list->tail = list->cursor->pre;
			list->cursor = list->tail;
		}//마지막 노드 삭제
		else {
			list->cursor->pre->next = list->cursor->next;
			list->cursor->next->pre = list->cursor->pre;
			list->cursor = list->cursor->pre;
			list->tail = list->backNode->pre;
		}
	}
}

void add(LinkedList *list, char x) {
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = x;
	if (list->frontNode == list->cursor) {
		list->head->pre = newNode;
		newNode->next = list->head;
		list->frontNode->next = newNode;
		list->head = newNode;
		newNode->pre = list->frontNode;
		list->cursor = newNode;
	}//add front
	else if (list->cursor == list->backNode) {
		list->tail->next = newNode;
		newNode->pre = list->tail;
		list->tail = newNode;
		newNode->next = list->backNode;
		list->backNode->pre = newNode;
		list->cursor = newNode;
	}//add back
	else {
		newNode->next = list->cursor->next;
		list->cursor->next->pre = newNode;
		list->cursor->next = newNode;
		newNode->pre = list->cursor;
		list->cursor = newNode;
	}//add middle
}

int main() {
	LinkedList list;
	Init(&list);
	char str[MAX_SIZE];
	scanf(" %s", &str);
	for (int i = 0; i<strlen(str); i++) {
		insertNode(&list, str[i]);
	}//create node

	int n;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		char cmd;
		char add_char;
		scanf(" %c", &cmd);
		switch (cmd) {
		case 'L': moveLeft(&list);
			break;
		case 'D': moveRight(&list);
			break;
		case 'B': removeChar(&list);
			break;
		case 'P': scanf(" %c", &add_char);
			add(&list, add_char);
			break;
		}
	}

	ListNode *temp = list.head;
	while (temp != list.backNode) {
		printf("%c", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

/*
1406. 
https://www.acmicpc.net/problem/1406

edit 09.16
but time exceeded.... I don't know why it's time over

Doubly linked list
*/