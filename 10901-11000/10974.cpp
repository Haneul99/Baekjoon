#include<stdio.h>

int n;
int arr[9] = { 0, };
int visit[9];

void Permutation(int start, int depth) {
	arr[depth] = start;//start에서 값을 설정하기 때문에 arr원래 배열값은 상관없음.
	if (depth == n) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 1) continue;//이미 방문했으면 pass
			else {
				visit[i] = 1;
				Permutation(i, depth + 1);
				visit[i] = 0;
			}
		}
	}
}


int main() {
	scanf("%d", &n);
	Permutation(1, 0);
}

/*
10974. 모든 순열
https://www.acmicpc.net/problem/10974


문제
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다. 

출력
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.



1234 43 324 42 423 32 ...
*/