#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;

int bingoBoard[6][6] = { 0, };


bool checkBingo() {
	int bingo = 0;
	bool flag = true;

	//가로빙고 체크
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingoBoard[i][j] != 0) {
				flag = false;
				break;
			}
		}
		if(flag) bingo++;
		flag = true;
	}

	//세로빙고 체크
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingoBoard[j][i] != 0) {
				flag = false;
				break;
			}
		}
		if (flag) bingo++;
		flag = true;
	}
	

	//대각선 빙고 체크
	for (int i = 0; i < 5; i++) {
		if (bingoBoard[i][i] != 0) {
			flag = false;
			break;
		}
	}
	if (flag) bingo++;

	flag = true;
	for (int i = 0; i < 5; i++) {
		if (bingoBoard[i][4 - i] != 0) {
			flag = false;
			break;
		}
	}
	if (flag) bingo++;

	if (bingo >= 3) return true;
	return false;
}

void noteNumber(int num) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingoBoard[i][j] == num) {
				bingoBoard[i][j] = 0;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> bingoBoard[i][j];
		}
	}

	int numArr[26] = { 0, };
	int ans = 0;
	for (int i = 0; i < 25; i++) {
		cin >> numArr[i];
	}
	for (int i = 0; i < 25; i++) {
		noteNumber(numArr[i]);
		if (checkBingo()) {
			cout << i + 1 << '\n';
			break;
		}
	}
}


/*
2578. 빙고
https://www.acmicpc.net/problem/2578

문제
빙고 게임은 다음과 같은 방식으로 이루어진다.

먼저 아래와 같이 25개의 칸으로 이루어진 빙고판에 1부터 25까지 자연수를 한 칸에 하나씩 쓴다



다음은 사회자가 부르는 수를 차례로 지워나간다. 예를 들어 5, 10, 7이 불렸다면 이 세 수를 지운 뒤 빙고판의 모습은 다음과 같다.




차례로 수를 지워가다가 같은 가로줄, 세로줄 또는 대각선 위에 있는 5개의 모든 수가 지워지는 경우 그 줄에 선을 긋는다.



이러한 선이 세 개 이상 그어지는 순간 "빙고"라고 외치는데, 가장 먼저 외치는 사람이 게임의 승자가 된다.



철수는 친구들과 빙고 게임을 하고 있다. 철수가 빙고판에 쓴 수들과 사회자가 부르는 수의 순서가 주어질 때, 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지를 출력하는 프로그램을 작성하시오.

입력
첫째 줄부터 다섯째 줄까지 빙고판에 쓰여진 수가 가장 위 가로줄부터 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 여섯째 줄부터 열째 줄까지 사회자가 부르는 수가 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 빙고판에 쓰여진 수와 사회자가 부르는 수는 각각 1부터 25까지의 수가 한 번씩 사용된다.

출력
첫째 줄에 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지 출력한다.

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44
*/