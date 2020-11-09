#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct coord {
	int num;
	int index;
}coord;

bool comp(const coord& a, const coord& b) {
	return (a.num < b.num);
}

int n;
int arr[1000001];
coord loc[1000001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		loc[i].num = arr[i];
		loc[i].index = i;
	}
	sort(loc, loc + n, comp);
	int cnt = 0;
	arr[loc[0].index] = cnt;
	for (int i = 1; i < n; i++) {
		if (loc[i].num != loc[i - 1].num) cnt++;
		arr[loc[i].index] = cnt;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}


/*
18870. 좌표 압축
https://www.acmicpc.net/problem/18870

문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

*/