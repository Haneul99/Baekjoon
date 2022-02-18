#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<math.h>
#define MAX 100010

using namespace std;

int n, bizz[MAX];

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &bizz[i]);
	}

	sort(bizz, bizz + n);

	long long sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += bizz[i];
	}
	if (sum <= bizz[n - 1]) {
		printf("%d", bizz[n - 1] - sum);
	}
	else {
		printf("%d\n", (sum + bizz[n - 1]) % 2);
	}
}


/*
19590. 비드맨
https://www.acmicpc.net/problem/19590

문제
구슬을 엄청 좋아하는 비드맨이 있다. 구슬만 보면 갖고 싶어 하는 비드맨은 오늘도 갖고 싶은 구슬을 발견했다. 그러나 비드맨은 현재 구슬을 너무 많이 갖고 있기 때문에 더 이상 구슬을 가질 수 없는 지경에 이르렀다.

비드맨은 서로 다른 종류의 구슬 두 개를 부딪히면 서로 깨져 없어진다는 것을 알고 있다. 이 사실을 이용해서 비드맨은 현재 가지고 있는 구슬의 개수를 최소로 하고자 한다. 그러나 구슬의 개수가 많기 때문에 비드맨은 도저히 계산을 할 수가 없었다.

길거리 해결사인 당신은 길거리에서 고민에 빠진 비드맨을 발견했고, 비드맨에게 고민에 빠진 이유를 듣게 된다. 인연인 만큼 당신은 비드맨의 고민을 해결해주려고 한다. 서로 다른 종류의 구슬 두 개를 부딪혀서 최대한 구슬을 없앤다고 할 때 남게 되는 구슬의 개수는 몇 개인지를 구하면 된다.

입력
첫 번째 줄에는 비드맨이 가지고 있는 구슬의 종류 N이 주어진다. (1 ≤ N ≤ 105)

두 번째 줄부터 N개의 줄에는 x1, x2​, x3, ..., xN이 주어진다. xi는 비드맨이 가지고 있는 i번째 종류의 구슬의 개수이다. (1 ≤ xi ≤ 109)

출력
비드맨이 최대한 많이 구슬을 없앴을 때 남는 구슬의 개수를 출력한다.
*/