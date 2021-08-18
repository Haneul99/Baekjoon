﻿#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>


using namespace std;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


vector<string> puyo;
vector< pair<int, int> > pop;

int visit[15][10];
void DFS(int x, int y, char p) {
	visit[x][y] = 1;
	pop.push_back({ x, y });

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 12 || nx < 0 || ny >= 6 || ny < 0) continue;
		if (!visit[nx][ny] && puyo[nx][ny] == p)
			DFS(nx, ny, p);
	}
}//네 방향으로 같은 뿌요의 개수

void drop() {
	for (int i = 0; i < 6; i++) {
		vector<char> non_empty;
		for (int j = 11; j >= 0; j--) {
			if (puyo[j][i] != '.') {
				non_empty.push_back(puyo[j][i]);
			}
		}
		int size = non_empty.size();//3개라고 하면 11, 10, 9에 차곡차곡
		for (int j = 11; j > 11 - size; j--) {
			puyo[j][i] = non_empty[11 - j];
		}//아래부터 쌓기
		for (int j = 11 - size; j >= 0; j--) {
			puyo[j][i] = '.';
		}//. 으로 채우기
	}//왼쪽에서부터, 아래에서 위로 가면서 . 이 아닌 것을 찾음.
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 12; i++) {
		string s;
		cin >> s;
		puyo.push_back(s);
	}
	int ans = 0;
	int flag = 1;

	while (flag) {
		flag = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visit[i][j] == 0 && puyo[i][j] != '.') {
					DFS(i, j, puyo[i][j]);
					int size = pop.size();
					if (size >= 4) {
						flag = 1;
						for (int i = 0; i < size; i++) {
							puyo[pop[i].first][pop[i].second] = '.';
						}
					}
					pop.clear();
				}
			}
		}
		//drop해줌.
		drop();
		if (flag) ans++;
	}
	cout << ans << '\n';
}


/*
11559. Puyo Puyo
https://www.acmicpc.net/problem/11559

문제
뿌요뿌요의 룰은 다음과 같다.

필드에 여러 가지 색깔의 뿌요를 놓는다. 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.

뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다. 이때 1연쇄가 시작된다.

뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례대로 아래로 떨어지게 된다.

아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데, 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.

터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.

남규는 최근 뿌요뿌요 게임에 푹 빠졌다. 이 게임은 1:1로 붙는 대전게임이라 잘 쌓는 것도 중요하지만, 상대방이 터뜨린다면 연쇄가 몇 번이 될지 바로 파악할 수 있는 능력도 필요하다. 하지만 아직 실력이 부족하여 남규는 자기 필드에만 신경 쓰기 바쁘다. 상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산하여 남규를 도와주자!

입력
총 12개의 줄에 필드의 정보가 주어지며, 각 줄에는 6개의 문자가 있다.

이때 .은 빈공간이고 .이 아닌것은 각각의 색깔의 뿌요를 나타낸다.

R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.

입력으로 주어지는 필드는 뿌요들이 전부 아래로 떨어진 뒤의 상태이다. 즉, 뿌요 아래에 빈 칸이 있는 경우는 없다.

출력
현재 주어진 상황에서 몇연쇄가 되는지 출력한다. 하나도 터지지 않는다면 0을 출력한다.

while flag로 연쇄터짐이 없을때까지 돌림.
여러 그룹이 터지면 한번에 터져야하니까 맵 전체를 돌아서 터질 수 있는 것들 터트려야함.
*/