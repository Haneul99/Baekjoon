#include<stdio.h>
#include<malloc.h>

typedef struct ListNode {
	int value;
	struct ListNode *pre;
	struct ListNode *next;
}ListNode;

typedef struct LinkedList {
	ListNode *head;
	ListNode *tail;
	ListNode *cursor;
}LinkedList;

void Init(LinkedList *list) {
	list->cursor = NULL;
	list->head = NULL;
	list->tail = NULL;
}

void insertNode(LinkedList *list, int x) {
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->value = x;
	if (list->head == NULL) {
		list->head = newNode;
		list->tail = newNode;
		list->cursor = newNode;
		newNode->next = list->head;
		newNode->pre = list->tail;
	}
	else {
		list->tail->next = newNode;
		list->head->pre = newNode;
		newNode->next = list->head;
		newNode->pre = list->tail;
		list->tail = newNode;
	}
}

int deleteNode(LinkedList *list) {
	int val;
	if (list->head == NULL) return 0;
	else {
		val = list->cursor->value;
		if (list->cursor == list->head) {
			list->tail->next = list->head->next;
			list->head = list->head->next;
			list->head->pre = list->tail;	
		}//head node delete
		else if (list->cursor == list->tail) {
			list->tail = list->tail->pre;
			list->tail->next = list->head;
			list->head->pre = list->tail;
		}//tail node delete
		else {
			list->cursor->pre->next = list->cursor->next;
			list->cursor->next->pre = list->cursor->pre;
		}//the other node delete
	}
	return val;
}

int main() {
	LinkedList list;
	Init(&list);
	int n;
	int K;
	scanf(" %d", &n);
	scanf(" %d", &K);
	for (int i = 1; i <= n; i++) {
		insertNode(&list, i);
	}//create node
	printf("<");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < K; j++) {
			list.cursor = list.cursor->next;
		}
		if (i == 0) list.cursor = list.cursor->pre;
		if(i!=n-1) printf("%d, ", deleteNode(&list));
		else printf("%d>", deleteNode(&list));
	}
}

/*
1158. 요세푸스 문제
https://www.acmicpc.net/problem/1158



Circular, doubly linked list
*/