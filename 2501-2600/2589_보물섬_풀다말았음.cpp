#include<stdio.h>


int col, row;
int arr[60][60];
int cnt[60][60] = { 0, };
int visit[60][60];
int max = 0;


void DFS(int x, int y) {
	visit[x][y] = 1;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (arr[x - 1][y] == 1 && visit[x - 1][y] == 0) {
				if (cnt[x][y] + 1 < cnt[x - 1][y]) cnt[x - 1][y] = cnt[x][y] + 1;
				DFS(x - 1, y);
			}
			else if (arr[x + 1][y] == 1 && visit[x + 1][y] == 0) {
				if (cnt[x][y] + 1 < cnt[x + 1][y]) cnt[x + 1][y] = cnt[x][y] + 1;
				DFS(x + 1, y);
			}
			else if (arr[x][y + 1] == 1 && visit[x][y + 1] == 0) {
				if (cnt[x][y] + 1 < cnt[x][y + 1]) cnt[x][y + 1] = cnt[x][y] + 1;
				DFS(x, y + 1);
			}
			else if (arr[x][y - 1] == 1 && visit[x][y - 1] == 0) {
				if (cnt[x][y] + 1 < cnt[x][y - 1]) cnt[x][y - 1] = cnt[x][y] + 1;
				DFS(x, y - 1);
			}
		}//�����¿쿡 �湮���� ���� ���� �ִٸ� DFS ����
	}
}


int main() {
	char str[51];
	scanf("%d%d", &col,&row);
	for (int i = 0; i < col; i++) {
		scanf(" %s", str);
		for (int j = 0; j < row; j++) {
			if(str[j]=='W') arr[i][j] = 0;
			else if (str[j] == 'L') arr[i][j] = 1;
		}
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] == 1 && visit[i][j] == 0)
				DFS(i, j);
		}
	}
}


/*
2589. 
https://www.acmicpc.net/problem/2589


������ ���� ���� ��� üŷ�Ұ��ΰ�... �̰��� �𸣰ڵ�...
*/