#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 110

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ans = 0;
	string S, T; cin >> S >> T;
	int sLen = S.length();
	int tLen = T.length();

	queue<string> q;
	q.push(T);
	while (!q.empty()) {
		string t = q.front(); q.pop();
		if (t.size() == sLen) {
			if (t == S) {
				ans = 1;
			}
		}
		if (t.size() <= sLen) continue;
		string temp;
		if (t[0] == 'B') {
			temp = t;
			temp = temp.substr(1, t.length() - 1);
			reverse(temp.begin(), temp.end());
			q.push(temp);
		}
		if (t[t.size() - 1] == 'A') {
			temp = t;
			temp = temp.substr(0, temp.length() - 1);
			q.push(temp);
		}
	}
	cout << ans << '\n';
}


/*
12919. A와 B 2
https://www.acmicpc.net/problem/12919

문제
수빈이는 A와 B로만 이루어진 영어 단어 존재한다는 사실에 놀랐다. 대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다. 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다. 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

문자열의 뒤에 A를 추가한다.
문자열의 뒤에 B를 추가하고 문자열을 뒤집는다.
주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 S가 둘째 줄에 T가 주어진다. (1 ≤ S의 길이 ≤ 49, 2 ≤ T의 길이 ≤ 50, S의 길이 < T의 길이)

출력
S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다.
*/ 