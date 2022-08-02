#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int dx[10] = { 1,-1,0,0,1,-1,1,-1 };
int dy[10] = { 0,0,-1,1,1,1,-1,-1 };

pair<int, int> kingPos, stonePos;

void moveChess(int dir) {
	pair<int, int> tmpKingPos, tmpStonePos;
	tmpKingPos.first = kingPos.first + dx[dir]; tmpKingPos.second = kingPos.second + dy[dir];
	if (tmpKingPos.first < 0 || tmpKingPos.first > 7 || tmpKingPos.second < 0 || tmpKingPos.second > 7) return;

	if (tmpKingPos.first == stonePos.first && tmpKingPos.second == stonePos.second) {
		tmpStonePos.first = stonePos.first + dx[dir]; tmpStonePos.second = stonePos.second + dy[dir];
		if (tmpStonePos.first < 0 || tmpStonePos.first > 7 || tmpStonePos.second < 0 || tmpStonePos.second > 7) return;
		stonePos.first = tmpStonePos.first;
		stonePos.second = tmpStonePos.second;
	}//밀어내기

	kingPos.first = tmpKingPos.first;
	kingPos.second = tmpKingPos.second;
}

int convertDirection(string dir) {
	if (dir == "R") {
		return 0;
	}
	else if (dir == "L") {
		return 1;
	}
	else if (dir == "B") {
		return 2;
	}
	else if (dir == "T") {
		return 3;
	}
	else if (dir == "RT") {
		return 4;
	}
	else if (dir == "LT") {
		return 5;
	}
	else if (dir == "RB") {
		return 6;
	}
	else if (dir == "LB") {
		return 7;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string king, stone;
	int n;

	cin >> king >> stone >> n;
	kingPos.first = king[0] - 'A';
	kingPos.second = king[1] - '0' - 1;

	stonePos.first = stone[0] - 'A';
	stonePos.second = stone[1] - '0' - 1;

	for (int i = 0; i < n; i++) {
		string cmd; cin >> cmd;
		moveChess(convertDirection(cmd));
	}

	cout << char(kingPos.first + 'A') << kingPos.second + 1 << '\n';
	cout << char(stonePos.first + 'A') << stonePos.second + 1 << '\n';
}


/*
1063. 킹
https://www.acmicpc.net/problem/1063

문제
8*8크기의 체스판에 왕이 하나 있다. 킹의 현재 위치가 주어진다. 체스판에서 말의 위치는 다음과 같이 주어진다. 알파벳 하나와 숫자 하나로 이루어져 있는데, 알파벳은 열을 상징하고, 숫자는 행을 상징한다. 열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 행은 가장 아래가 1이고 가장 위가 8이다. 예를 들어, 왼쪽 아래 코너는 A1이고, 그 오른쪽 칸은 B1이다.

킹은 다음과 같이 움직일 수 있다.

R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로
체스판에는 돌이 하나 있는데, 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다. 아래 그림을 참고하자.



입력으로 킹이 어떻게 움직여야 하는지 주어진다. 입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.

킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 킹의 위치, 돌의 위치, 움직이는 횟수 N이 주어진다. 둘째 줄부터 N개의 줄에는 킹이 어떻게 움직여야 하는지 주어진다. N은 50보다 작거나 같은 자연수이고, 움직이는 정보는 위에 쓰여 있는 8가지 중 하나이다.

출력
첫째 줄에 킹의 마지막 위치, 둘째 줄에 돌의 마지막 위치를 출력한다.
*/