#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 100010

using namespace std;

int N;
int numChart[MAX][3];
int score[2][3] = { 0, };//0: 최대, 1: 최소

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	
	int a, b, c;
	cin >> a >> b >> c;
	score[0][0] = a; score[1][0] = a;
	score[0][1] = b; score[1][1] = b;
	score[0][2] = c; score[1][2] = c;

	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		int ex1 = score[0][0], ex2 = score[0][1], ex3 = score[0][2];
		score[0][0] = max(ex1, ex2) + a;
		score[0][1] = max(max(ex1, ex2), ex3) + b;
		score[0][2] = max(ex2, ex3) + c;

		ex1 = score[1][0], ex2 = score[1][1], ex3 = score[1][2];
		score[1][0] = min(ex1, ex2) + a;
		score[1][1] = min(min(ex1, ex2), ex3) + b;
		score[1][2] = min(ex2, ex3) + c;
	}

	cout << max(max(score[0][0], score[0][1]), score[0][2]) << " ";
	cout << min(min(score[1][0], score[1][1]), score[1][2]) << "\n";
}


/*
2096. 내려가기
https://www.acmicpc.net/problem/2096

문제
N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다. 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.

먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다. 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다. 바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다. 이 제약 조건을 그림으로 나타내어 보면 다음과 같다.



별표는 현재 위치이고, 그 아랫 줄의 파란 동그라미는 원룡이가 다음 줄로 내려갈 수 있는 위치이며, 빨간 가위표는 원룡이가 내려갈 수 없는 위치가 된다. 숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오. 점수는 원룡이가 위치한 곳의 수의 합이다.

입력
첫째 줄에 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 숫자가 세 개씩 주어진다. 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나가 된다.

출력
첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.
*/ 