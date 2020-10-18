#include<stdio.h>

int n, m;
int arr[10001];
int count = 0;

void check(int start) {
	int sum = 0;
	for (int i = start; i < n; i++) {
		sum += arr[i];
		if (sum == m) {
			count++;
			break;
		}
		else if (sum > m) break;
	}
}//i(시작점)부터 쭉 더하다가 m값과 같으면 count더하고 break, 커지면 break

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		check(i);
	}
	printf("%d\n", count);
}

/*
2003. 수들의 합 2
https://www.acmicpc.net/problem/2003

문제
N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다.

*/