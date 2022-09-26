#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>

#define MAX 52

using namespace std;

char matrixA[MAX][MAX], matrixB[MAX][MAX];

void change3X3(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (matrixA[i][j] == '0') matrixA[i][j] = '1';
			else matrixA[i][j] = '0';
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M, ans = 0; cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> matrixA[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> matrixB[i][j];
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (matrixA[i][j] != matrixB[i][j]) {
				change3X3(i, j);
				ans++;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (ans == -1) break;
		for (int j = 1; j <= M; j++) {
			if (matrixA[i][j] != matrixB[i][j]) {
				ans = -1; break;
			}
		}
	}

	cout << ans << '\n';
}


/*
1080. 행렬
https://www.acmicpc.net/problem/1080

문제
0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 이때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.

행렬을 변환하는 연산은 어떤 3×3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다. (0 → 1, 1 → 0)

입력
첫째 줄에 행렬의 크기 N M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 행렬 A가 주어지고, 그 다음줄부터 N개의 줄에는 행렬 B가 주어진다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 A를 B로 바꿀 수 없다면 -1을 출력한다.
*/ 