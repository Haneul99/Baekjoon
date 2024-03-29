#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<stack>

using namespace std;

int R, C, ans = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

char MAP[51][51];
int visit[51][51];
queue<pair<int, int>> wq; //물의 위치
queue<pair<int, int>> bq; //비버의 위치

int BFS() {

	while (!wq.empty() || !bq.empty()) {
		ans++;
		//일단 물부터 퍼트리기
		int ws = wq.size();
		for (int i = 0; i < ws; i++) {
			int x = wq.front().first;
			int y = wq.front().second;
			wq.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) continue;
				if (MAP[nx][ny] == 'D' || MAP[nx][ny] == 'X' || MAP[nx][ny] == '*') continue;
				MAP[nx][ny] = '*';
				wq.push({ nx, ny });
			}
		}

		int bs = bq.size();
		for (int i = 0; i < bs; i++) {
			int x = bq.front().first;
			int y = bq.front().second;
			bq.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) continue;
				if (MAP[nx][ny] == '*' || MAP[nx][ny] == 'X') continue;
				if (visit[nx][ny]) continue;
				if (MAP[nx][ny] == 'D') return ans;
				bq.push({ nx, ny });
				visit[nx][ny] = 1;
			}
		}
		//그리고 가능한 위치로 비버 움직이기
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++) {
			MAP[i][j] = s[j];
			if (s[j] == 'S') {
				bq.push({ i,j });
			}
			else if (s[j] == '*') wq.push({ i,j });
		}
	}

	if (BFS() == -1) cout << "KAKTUS\n";
	else cout << ans << '\n';
}


/*
3055. 탈출
https://www.acmicpc.net/problem/3055

문제
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.

티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.

티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다.

입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와 'S'는 하나씩만 주어진다.

출력
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.


물이 이동하는 곳으로는 이동할 수 없으므로 물을 먼저 spread 해야함.
BFS.. 그치만 큐에 map을 삽입할수는 없는데..
아니지 시간이 지나면 물이 어떻게 퍼지는지는 동일함. 그냥 비버의 위치만 큐에 삽입하면 됨.
*/