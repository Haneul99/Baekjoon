#include<stdio.h>
#include<algorithm>

using namespace std;

int combi[10];
int arr[10];
int n, m;

void permutation(int idx, int depth) {
	combi[depth] = arr[idx];
	if (depth == m) {
		for (int i = 1; i <= m; i++) {
			printf("%d ", combi[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			permutation(i, depth + 1);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	permutation(0, 0);
}


/*
15656. N과 M (7)
https://www.acmicpc.net/problem/15656

문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

*/