#include<stdio.h>
#include<malloc.h>

typedef struct Node{
	int index;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct LinkedList {
	Node *head;
	Node *tail;
	Node *cursor;
}LinkedList;

void init(LinkedList *list) {
	list->head = NULL;
	list->tail = NULL;
	list->cursor = NULL;
}

void insertNode(LinkedList *list, int n) {
	for (int i = 1; i <= n; i++) {
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->index = i;
		if (list->head == NULL) {
			list->head = newNode;
			list->tail = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
			list->cursor = newNode;
		}
		else {
			newNode->next = list->head;
			list->head->prev = newNode;
			list->tail->next = newNode;
			newNode->prev = list->tail;
			list->tail = newNode;
		}
	}
}

void deleteNode(LinkedList *list, int k, int n) {
	int a = 1;
	while (list->head != NULL) {
		for (int i = 0; i < k-1; i++) {
			list->cursor = list->cursor->next;
		}
		if (a == 1) printf("<%d, ",list->cursor->index);
		else if (a == n) {
			printf("%d>\n", list->cursor->index);
		}
		else{
			printf("%d, ", list->cursor->index);
		}
		a++;
		if (list->head != list->head->next) {
			if (list->cursor == list->head) {
				list->tail->next = list->head->next;
				list->head->next->prev = list->tail;
				list->cursor = list->cursor->next;
				list->head = list->head->next;
			}//head�� ������ ��
			else if (list->cursor == list->tail) {
				list->tail->prev->next = list->head;
				list->tail = list->tail->prev;
				list->head->prev = list->tail;
				list->cursor = list->cursor->next;
			}//tail�� ������ ��
			else {
				list->cursor->prev->next = list->cursor->next;
				list->cursor->next->prev = list->cursor->prev;
				list->cursor = list->cursor->next;
			}
		}
		else {
			list->head == NULL;
			list->tail == NULL;
			list->cursor == NULL;
			break;
		}
	}
}

int main() {
	int n;
	int k;
	scanf("%d", &n);
	scanf("%d", &k);
	LinkedList list;
	init(&list);
	insertNode(&list, n);
	deleteNode(&list, k, n);
}


/*
1168. 요세푸스 문제 2
https://www.acmicpc.net/problem/1168


Circular linked list
*/