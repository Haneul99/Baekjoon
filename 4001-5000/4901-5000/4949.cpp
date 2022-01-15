#include<stdio.h>
#include<string.h>
#define MAX_SIZE 10000

typedef struct Stack {
	char arr[MAX_SIZE];
	int size;
}Stack;

void StackInit(Stack *s) {
	s->size = -1;
}

void push(Stack *s, char x) {
	s->arr[s->size + 1] = x;
	s->size++;
}

char pop(Stack *s) {
	char n = s->arr[s->size];
	s->size--;
	return n;
}

int main() {
	Stack s;
	char c;
	char str[110];
	gets_s(str);
	while (strcmp(str,".")!=0) {
		int check = 1;
		StackInit(&s);
		while (1) {
			for (int i = 0; i < strlen(str); i++) {
				c = str[i];
				if (c == '(' || c=='[') {
					push(&s, c);
				}
				else if (c == ')' || c == ']') {
					if (s.size != -1) {
						char out = pop(&s);
						if (out == '(') {
							if (c != ')') check = 0;
						}
						else if (out == '[') {
							if (c != ']')check = 0;
						}
					}
					else check = 0;
				}
				if (check == 0) break;
			}
			if (strchr(str, '.') != NULL) break;
			gets_s(str);
		}
		if (s.size != -1) {
			check = 0;
		}
		if (check == 0) printf("no\n");
		else printf("yes\n");
		gets_s(str);
	}
}

/*
4949. 균형잡힌 세상
https://www.acmicpc.net/problem/4949

get string inlcude blank

Baekjoon C code didn't allow gets_s
so if you check in Baekjoon, change gets_s to gets
*/