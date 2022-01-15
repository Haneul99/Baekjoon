#include <stdio.h>


void swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

int GCD(int a, int b)
{
	if (a < b) swap(a, b);
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void) {
	int n;
	scanf("%d", &n);
	int arr[101][101];
	long long result[101] = { 0, };
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i][0]);
		for(int j=1;j<=arr[i][0];j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 1; i <= n; i++) {
		for(int j=1;j<arr[i][0];j++)
			for (int k = j + 1; k <= arr[i][0]; k++)
				result[i] += GCD(arr[i][j], arr[i][k]);
		printf("%lld\n", result[i]);
	}
}



/*
9613. GCD 합
https://www.acmicpc.net/problem/9613

문제
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1,000,000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.

*/