#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n, position;
	scanf("%d%d", &n, &position);

	int arr[100001];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int dist[100001];
	for (int i = 0; i < n; i++) {
		dist[i] = abs(arr[i] - position);
	}

	sort(dist, dist + n);
	int cd;
	if (n >= 2) {
		cd = gcd(dist[0], dist[1]);
		for (int i = 2; i < n; i++) {
			cd = gcd(dist[i], cd);
		}
	}
	else cd = abs(arr[0] - position);
	printf("%d\n", cd);
}


/*
17087. 숨바꼭질 6
https://www.acmicpc.net/problem/17087

문제
수빈이는 동생 N명과 숨바꼭질을 하고 있다. 수빈이는 현재 점 S에 있고, 동생은 A1, A2, ..., AN에 있다.

수빈이는 걸어서 이동을 할 수 있다. 수빈이의 위치가 X일때 걷는다면 1초 후에 X+D나 X-D로 이동할 수 있다. 수빈이의 위치가 동생이 있는 위치와 같으면, 동생을 찾았다고 한다.

모든 동생을 찾기위해 D의 값을 정하려고 한다. 가능한 D의 최댓값을 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 105)과 S(1 ≤ S ≤ 109)가 주어진다. 둘째 줄에 동생의 위치 Ai(1 ≤ Ai ≤ 109)가 주어진다. 동생의 위치는 모두 다르며, 수빈이의 위치와 같지 않다.

출력
가능한 D값의 최댓값을 출력한다.

*/