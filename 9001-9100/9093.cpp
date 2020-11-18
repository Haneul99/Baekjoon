#include<stdio.h>
#include<string.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int start = 0;
		char str[1001];
		scanf(" %[^\n]s", str);
		int len = strlen(str);
		str[len] = ' ';
		for (int i = 0; i <= len; i++) {
			if (str[i] == ' ') {
				for (int j = i - 1; j >= start; j--)
					printf("%c", str[j]);
				printf(" ");
				start = i + 1;
			}
		}
		printf("\n");
	}
}


/*
9093.
https://www.acmicpc.net/problem/9093


*/