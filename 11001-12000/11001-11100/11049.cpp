#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 510

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;

	int MATRIX[MAX][2];
	for (int i = 1; i <= N; i++) {
		cin >> MATRIX[i][0] >> MATRIX[i][1];
	}

	int DP[MAX][MAX] = { 0, };

	for (int sectionSize = 1; sectionSize < N; sectionSize++) {
		for (int start = 1; start + sectionSize <= N; start++) {
			int end = start + sectionSize;
			DP[start][end] = INT_MAX;
			for (int k = start; k < end; k++) {
				DP[start][end] = min(DP[start][end], DP[start][k] + DP[k + 1][end] + MATRIX[start][0] * MATRIX[k+1][0] * MATRIX[end][1]);
			}
		}
	}
	cout << DP[1][N] << '\n';
}


/*
11049. 행렬 곱셈 순서
https://www.acmicpc.net/problem/11049

문제
크기가 N×M인 행렬 A와 M×K인 B를 곱할 때 필요한 곱셈 연산의 수는 총 N×M×K번이다. 행렬 N개를 곱하는데 필요한 곱셈 연산의 수는 행렬을 곱하는 순서에 따라 달라지게 된다.

예를 들어, A의 크기가 5×3이고, B의 크기가 3×2, C의 크기가 2×6인 경우에 행렬의 곱 ABC를 구하는 경우를 생각해보자.

AB를 먼저 곱하고 C를 곱하는 경우 (AB)C에 필요한 곱셈 연산의 수는 5×3×2 + 5×2×6 = 30 + 60 = 90번이다.
BC를 먼저 곱하고 A를 곱하는 경우 A(BC)에 필요한 곱셈 연산의 수는 3×2×6 + 5×3×6 = 36 + 90 = 126번이다.
같은 곱셈이지만, 곱셈을 하는 순서에 따라서 곱셈 연산의 수가 달라진다.

행렬 N개의 크기가 주어졌을 때, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램을 작성하시오. 입력으로 주어진 행렬의 순서를 바꾸면 안 된다.

입력
첫째 줄에 행렬의 개수 N(1 ≤ N ≤ 500)이 주어진다.

둘째 줄부터 N개 줄에는 행렬의 크기 r과 c가 주어진다. (1 ≤ r, c ≤ 500)

항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.

출력
첫째 줄에 입력으로 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값을 출력한다. 정답은 231-1 보다 작거나 같은 자연수이다. 또한, 최악의 순서로 연산해도 연산 횟수가 231-1보다 작거나 같다.

11066번 파일 합치기와 매우 유사한 문제.
다만 구간합을 더해주는 부분이 행렬의 곱이므로

[start:k][k+1:end] 에서
[ a x b ][ b x c ]의 형태이므로
[start][0]의 값과 [k][1] 또는 [k+1][0]의 값과 [end][1]의 값을 곱해줌.
*/ 