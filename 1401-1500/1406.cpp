#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAX_SIZE 100000

typedef struct ListNode {
	char data;
	struct ListNode *next;
	struct ListNode *pre;
}ListNode;

typedef struct LinkedList {
	ListNode *cursor;
	ListNode *tail;
	ListNode *head;
}LinkedList;

void init(LinkedList *list) {
	list->cursor = NULL;
	list->head = NULL;
	list->tail = NULL;
}

void moveLeft(LinkedList *list) {
	printf("moveLeft\n");
	if (list->head == list->cursor) return;
	else {
		list->cursor = list->cursor->pre;
	}
}

void moveRight(LinkedList *list) {
	printf("moveRight\n");
	if (list->tail == list->cursor) return;
	else {
		list->cursor = list->cursor->next;
	}
}

void removeChar(LinkedList *list) {
	printf("remove\n");
	if (list->cursor == list->head) return;
	else {
		list->cursor->pre = list->cursor->pre->pre;
		list->cursor->pre->pre->next = list->cursor;
	}
}

void add(LinkedList *list,char x) {
	printf("add %c\n",x);
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = x;
	if (list->head == list->cursor) {
		list->head = newNode;
		newNode->next = list->cursor;
		newNode->pre = NULL;
	}
	else {
		newNode->pre = list->cursor->pre;
		list->cursor->pre->next = newNode;
		newNode->next = list->cursor;
	}
}

void createNode(LinkedList *list, char data) {
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	newNode->pre = NULL;
	if (list->head == NULL && list->tail==NULL && list->cursor==NULL) {
		list->head = list->tail = list->cursor = newNode;
	}
	else {
		newNode->pre = list->tail;
		list->tail->next = newNode;
		list->tail = newNode;
		list->cursor = newNode;
	}
}

int main() {
	char str[MAX_SIZE];
	scanf("%s", &str);
	LinkedList *list;
	list = (LinkedList *)malloc(sizeof(LinkedList));
	init(list);
	for (int i = 0; i < strlen(str); i++) {
		createNode(list, str[i]);
	}
	int n;
	scanf(" %d", &n);

	for (int i = 0; i < n; i++) {
		char cmd;
		char add_char;
		scanf(" %c", &cmd);
		switch (cmd) {
		case 'L': moveLeft(list);
			break;
		case 'D': moveRight(list);
			break;
		case 'B': removeChar(list);
			break;
		case 'P': scanf(" %c", &add_char);
			add(list,add_char);
			break;
		}
		printf("\n");
	}

	ListNode *temp=list->head;
	while (temp != NULL) {
		printf("%c", temp->data);
		temp = temp->next;
	}
}

/*
1406. 에디터
https://www.acmicpc.net/problem/1406

not completed,
time limit
i will do after,,,,



linkedList
*/