#include<stdio.h>
#include<vector>

using namespace std;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
	long long int result = x1 * y2 + x2 * y3 + x3 * y1;
	result += (-y1 * x2 - y2 * x3 - y3 * x1);
	if (result / 2 > 0) return 1;
	else if (result / 2 < 0) return -1;
	else return 0;
}


int main() {
	pair<int, int> p[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}

	printf("%d", ccw(p[0].first, p[1].first, p[2].first, p[0].second, p[1].second, p[2].second));
}


/*
11758. CCW
https://www.acmicpc.net/problem/11758

문제
2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 P1의 (x1, y1), 둘째 줄에 P2의 (x2, y2), 셋째 줄에 P3의 (x3, y3)가 주어진다. (-10,000 ≤ x1, y1, x2, y2, x3, y3 ≤ 10,000) 모든 좌표는 정수이다. P1, P2, P3의 좌표는 서로 다르다.

출력
P1, P2, P3를 순서대로 이은 선분이 반시계 방향을 나타내면 1, 시계 방향이면 -1, 일직선이면 0을 출력한다.
*/
