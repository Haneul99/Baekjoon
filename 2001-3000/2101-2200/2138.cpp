#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>

using namespace std;

int n, ans = 1234567890;

string changeOnOff(string s, int index) {
	if (index != 0) {
		if (s[index - 1] == '0') s[index - 1] = '1';
		else if (s[index - 1] == '1') s[index - 1] = '0';
	}//이전것 change
	if (index != n - 1) {
		if (s[index + 1] == '0') s[index + 1] = '1';
		else if (s[index + 1] == '1') s[index + 1] = '0';
	}//이후것 change
	if (s[index] == '0') s[index] = '1';
	else if (s[index] == '1') s[index] = '0';

	return s;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	string state, target; cin >> state >> target;

	int press = 0;
	string tmp = state;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (target[i] != tmp[i]) {
				tmp = changeOnOff(tmp, i + 1);
				press++;
			}
		}
		if (tmp == target) {
			ans = min(ans, press);
		}
		tmp = state;
		tmp = changeOnOff(tmp, 0);
		press = 1;
	}
	if (ans == 1234567890) cout << "-1\n";
	else cout << ans << '\n';
}


/*
2138. 전구와 스위치
https://www.acmicpc.net/problem/2138

문제
N개의 스위치와 N개의 전구가 있다. 각각의 전구는 켜져 있는 상태와 꺼져 있는 상태 중 하나의 상태를 가진다. i(1 < i < N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다. 즉, 꺼져 있는 전구는 켜지고, 켜져 있는 전구는 꺼지게 된다. 1번 스위치를 눌렀을 경우에는 1, 2번 전구의 상태가 바뀌고, N번 스위치를 눌렀을 경우에는 N-1, N번 전구의 상태가 바뀐다.

N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때, 그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(2 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 전구들의 현재 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 그 다음 줄에는 우리가 만들고자 하는 전구들의 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 0은 켜져 있는 상태, 1은 꺼져 있는 상태를 의미한다.

출력
첫째 줄에 답을 출력한다. 불가능한 경우에는 -1을 출력한다.
*/