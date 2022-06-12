#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

string board = "";
string ans = "";
bool ansFlag = true;

void convert(int xCnt) {
    if (xCnt % 2 != 0) {
        ansFlag = false;
    }
    if (xCnt % 4 == 0) {
        for (int j = 0; j < xCnt; j++) {
            ans += 'A';
        }
    }
    else {
        for (int j = 0; j < xCnt - 2; j++) {
            ans += 'A';
        }
        ans += "BB";
    }
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> board;
	int boardLen = board.size();

	int xCnt = 0;

	for (int i = 0; i < boardLen; i++) {
		if (board[i] == 'X') xCnt++;
		else {
            convert(xCnt);
			ans += ".";
			xCnt = 0;
		}
	}
    convert(xCnt);

	if (!ansFlag) cout << "-1\n";
	else cout << ans << '\n';
}

/*
1343. 폴리오미노
https://www.acmicpc.net/problem/1343

문제
민식이는 다음과 같은 폴리오미노 2개를 무한개만큼 가지고 있다. AAAA와 BB

이제 '.'와 'X'로 이루어진 보드판이 주어졌을 때, 민식이는 겹침없이 'X'를 모두 폴리오미노로 덮으려고 한다. 이때, '.'는 폴리오미노로 덮으면 안 된다.

폴리오미노로 모두 덮은 보드판을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 보드판이 주어진다. 보드판의 크기는 최대 50이다.

출력
첫째 줄에 사전순으로 가장 앞서는 답을 출력한다. 만약 덮을 수 없으면 -1을 출력한다.
*/