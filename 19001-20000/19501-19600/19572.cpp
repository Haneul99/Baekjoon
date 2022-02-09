#include<stdio.h>

using namespace std;

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int d1, d2, d3;
	scanf("%d%d%d", &d1, &d2, &d3);
	double sum = double(d1 + d2 + d3) / 2;


	double a, b, c;
	a = sum - d3, b = sum - d2, c = sum - d1;

	if (a <= 0 || b <= 0 || c <= 0) printf("-1\n");
	else {
		printf("1\n");
		printf("%.1lf %.1lf %.1lf\n", a, b, c);
	}

}


/*
19572. 가뭄(Small)
https://www.acmicpc.net/problem/19572

문제
가뭄에 찌든 신촌을 위해서 국렬이는 세 칸으로 구성되어 있는 신촌에 비를 내릴 것이다. 그러나 국렬이는 무능해서 각 칸마다 비를 내리지 못하고, 두 칸에 동일하게 비를 내리는 것만 할 수 있다.

1번째 칸, 2번째 칸에 동시에 뿌리는 비의 강수량을 a cm, 1번째 칸, 3번째 칸에 동시에 뿌리는 비의 강수량을 b cm, 2번째 칸, 3번째 칸에 동시에 뿌리는 비의 강수량을 c cm라고 하자. a, b, c는 모두 양의 실수여야 한다. 가뭄에 찌든 신촌이라도 비가 너무 많이 오면 상당히 곤란하고, 비가 너무 조금 와도 곤란하다. 그래서 각 칸에 해당하는 지역은 강수량이 정확히 di cm가 되어야 한다. 이때 정확한 a, b, c의 값을 구하여라.

입력
3개의 양의 정수가 입력으로 들어온다. 각각은 d1, d2, d3을 의미한다. (1 ≤ d1, d2, d3 ≤ 106)

출력
조건에 맞게 비를 내릴 수 없다면 -1을 출력한다.

조건에 맞게 비를 내릴 수 있다면 1을 출력하고, 다음 줄에 a, b, c를 소수 첫째 자리까지 반올림한 것을 공백으로 구분하여 출력한다.
*/