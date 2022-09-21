#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 12

using namespace std;

int SDOCU[10][10] = { 0, };
vector<pair<int, int>> blanks;

bool checkSquare(int num, int x, int y) {
	int startX = ((x - 1) / 3) * 3 + 1;
	int startY = ((y - 1) / 3) * 3 + 1;

	for (int i = startX; i < startX + 3; i++) {
		for (int j = startY; j < startY + 3; j++) {
			if (i == x && j == y) continue;
			if (SDOCU[i][j] == num) return false;
		}
	}
	return true;
}

bool checkHorizon(int num, int x, int y) {
	for (int i = 1; i <= 9; i++) {
		if (i == y) continue;
		if (SDOCU[x][i] == num) {
			return false;
		}
	}
	return true;
}

bool checkVertical(int num, int x, int y) {
	for (int i = 1; i <= 9; i++) {
		if (i == x) continue;
		if (SDOCU[i][y] == num) {
			return false;
		}
	}
	return true;
}

void backtracking(int depth) {
	if (depth == blanks.size()) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << SDOCU[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}
	
	int x = blanks[depth].first;
	int y = blanks[depth].second;

	for (int i = 1; i <= 9; i++) {
		if (checkSquare(i, x, y) && checkHorizon(i, x, y) && checkVertical(i, x, y)) {
			SDOCU[x][y] = i;
			backtracking(depth + 1);
			SDOCU[x][y] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 9; i++) {
		string line; cin >> line;
		for (int j = 0; j < 9; j++) {
			SDOCU[i][j + 1] = line[j] - '0';
			if (SDOCU[i][j + 1] == 0) {
				blanks.push_back({ i,j + 1 });
			}
		}
	}

	backtracking(0);
}


/*
2239. 스도쿠
https://www.acmicpc.net/problem/2239

문제
스도쿠는 매우 간단한 숫자 퍼즐이다. 9×9 크기의 보드가 있을 때, 각 행과 각 열, 그리고 9개의 3×3 크기의 보드에 1부터 9까지의 숫자가 중복 없이 나타나도록 보드를 채우면 된다. 예를 들어 다음을 보자.



위 그림은 참 잘도 스도쿠 퍼즐을 푼 경우이다. 각 행에 1부터 9까지의 숫자가 중복 없이 나오고, 각 열에 1부터 9까지의 숫자가 중복 없이 나오고, 각 3×3짜리 사각형(9개이며, 위에서 색깔로 표시되었다)에 1부터 9까지의 숫자가 중복 없이 나오기 때문이다.

하다 만 스도쿠 퍼즐이 주어졌을 때, 마저 끝내는 프로그램을 작성하시오.

입력
9개의 줄에 9개의 숫자로 보드가 입력된다. 아직 숫자가 채워지지 않은 칸에는 0이 주어진다.

출력
9개의 줄에 9개의 숫자로 답을 출력한다. 답이 여러 개 있다면 그 중 사전식으로 앞서는 것을 출력한다. 즉, 81자리의 수가 제일 작은 경우를 출력한다.
*/ 