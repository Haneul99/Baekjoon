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

int N, M;
char BOARD[MAX][MAX];
bool check[MAX][MAX][MAX][MAX];
pair<int, int> red, blue, hole;

int dx[4] = { 0,0,-1,1 };//왼오위아래
int dy[4] = { -1,1,0,0 };

pair<pair<int, int>, pair<int,int>> moveRedFirst(int nrx, int nry, int nbx, int nby, int dir) {
	int moveDist = 0;
	while (1) {
		if (nrx == hole.first && nry == hole.second) break;
		if (nrx >= 0 && nrx < N && nry >= 0 && nry < M && BOARD[nrx][nry] != '#') {
			nrx += dx[dir]; nry += dy[dir];
			moveDist++;
		}
		else {
			if (moveDist > 0) nrx -= dx[dir], nry -= dy[dir];
			break;
		}
	}
	moveDist = 0;
	while (1) {
		if (nbx == hole.first && nby == hole.second) break;
		if (nbx >= 0 && nbx < N && nby >= 0 && nby < M && BOARD[nbx][nby] != '#' && (nrx != nbx || nry != nby)) {
			nbx += dx[dir]; nby += dy[dir];
			moveDist++;
		}
		else {
			if (moveDist > 0) nbx -= dx[dir], nby -= dy[dir];
			break;
		}
		//한칸도 못움직이면 -=dy[0]을 해주기 때문에 칸을 움직이게 됨
	}

	return { {nrx, nry}, {nbx,nby} };
}

pair<pair<int, int>, pair<int, int>> moveBlueFirst(int nrx, int nry, int nbx, int nby, int dir) {
	int moveDist = 0;
	while (1) {
		if (nbx == hole.first && nby == hole.second) break;
		if (nbx >= 0 && nbx < N && nby >= 0 && nby < M && BOARD[nbx][nby] != '#') {
			nbx += dx[dir]; nby += dy[dir];
			moveDist++;
		}
		else {
			if (moveDist > 0) nbx -= dx[dir], nby -= dy[dir];
			break;
		}
	}
	moveDist = 0;
	while (1) {
		if (nrx == hole.first && nry == hole.second) break;
		if (nrx >= 0 && nrx < N && nry >= 0 && nry < M && BOARD[nrx][nry] != '#' && (nbx != nrx || nby != nry)) {
			nrx += dx[dir]; nry += dy[dir];
			moveDist++;
		}
		else {
			if (moveDist > 0) nrx -= dx[dir], nry -= dy[dir];
			break;
		}
	}
	return { {nrx, nry}, {nbx,nby} };
}

pair<pair<int,int>,pair<int,int>> moveLeft(int rx, int ry, int bx, int by) {
	if (ry < by) return moveRedFirst(rx, ry, bx, by, 0);
	else return moveBlueFirst(rx, ry, bx, by, 0);
}

pair<pair<int, int>, pair<int, int>> moveRight(int rx, int ry, int bx, int by) {
	if (ry > by) return moveRedFirst(rx, ry, bx, by, 1);
	else return moveBlueFirst(rx, ry, bx, by, 1);
}

pair<pair<int, int>, pair<int, int>> moveUp(int rx, int ry, int bx, int by) {
	if (rx < bx) return moveRedFirst(rx, ry, bx, by, 2);
	else return moveBlueFirst(rx, ry, bx, by, 2);
}

pair<pair<int, int>, pair<int, int>> moveDown(int rx, int ry, int bx, int by) {
	if (rx > bx) return moveRedFirst(rx, ry, bx, by, 3);
	else return moveBlueFirst(rx, ry, bx, by, 3);
}

bool movable(pair<pair<int, int>, pair<int, int>> movePos) {
	if (movePos.second.first == hole.first && movePos.second.second == hole.second) return false;
	if (check[movePos.first.first][movePos.first.second][movePos.second.first][movePos.second.second] == true) return false;
	return true;
}

int BFS() {
	queue < pair<pair<int, int>, pair<int, int>>> q;

	int cnt = 0;
	q.push({ {red.first, red.second}, {blue.first, blue.second} });
	check[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty()) {
		cnt++;
		if (cnt > 10) return -1;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int rx = q.front().first.first;
			int ry = q.front().first.second;
			int bx = q.front().second.first;
			int by = q.front().second.second;
			q.pop();
			pair<pair<int, int>, pair<int, int>> movePos;
			movePos = moveLeft(rx, ry, bx, by);
			if (movable(movePos)) {
				if (movePos.first == hole) return cnt;
				q.push(movePos);
				check[movePos.first.first][movePos.first.second][movePos.second.first][movePos.second.second] = true;
			}

			movePos = moveRight(rx, ry, bx, by);
			if (movable(movePos)) {
				if (movePos.first == hole) return cnt;
				q.push(movePos);
				check[movePos.first.first][movePos.first.second][movePos.second.first][movePos.second.second] = true;
			}

			movePos = moveUp(rx, ry, bx, by);
			if (movable(movePos)) {
				if (movePos.first == hole) return cnt;
				q.push(movePos);
				check[movePos.first.first][movePos.first.second][movePos.second.first][movePos.second.second] = true;
			}

			movePos = moveDown(rx, ry, bx, by);
			if (movable(movePos)) {
				if (movePos.first == hole) return cnt;
				q.push(movePos);
				check[movePos.first.first][movePos.first.second][movePos.second.first][movePos.second.second] = true;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string line; cin >> line;
		for (int j = 0; j < M; j++) {
			BOARD[i][j] = line[j];
			if (BOARD[i][j] == 'R') red = { i,j };
			else if (BOARD[i][j] == 'B') blue = { i,j };
			else if (BOARD[i][j] == 'O') hole = { i,j };
		}
	}

	cout << BFS();
}


/*
13460. 구슬 탈출 2
https://www.acmicpc.net/problem/13460

문제
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.

이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.


이동하다가 구멍 만나면 빠짐.
한 번 기울이면 이동할 수 없을때까지 이동됨.
*/ 