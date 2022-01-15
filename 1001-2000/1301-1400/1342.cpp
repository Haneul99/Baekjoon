﻿#include<stdio.h>
#include<vector>
#include<queue>
#include<iostream>
#include<math.h>
#include<string>


using namespace std;

int alpha[26];
string s;
int len;

int backtracking(char pre, int idx) {
	int cnt = 0;
	if (idx == len) {
		cnt++;
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (alpha[i] >= 1 && 'a' + i != pre) {
				alpha[i]--;
				cnt += backtracking('a' + i, idx + 1);
				alpha[i]++;
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> s;

	len = s.length();
	for (int i = 0; i < len; i++) {
		alpha[s[i] - 'a']++;
	}

	cout << backtracking('0', 0) << '\n';

}


/*
1342. 행운의 문자열
https://www.acmicpc.net/problem/1342

문제
민식이와 준영이는 자기 방에서 문자열을 공부하고 있다. 민식이가 말하길 인접해 있는 모든 문자가 같지 않은 문자열을 행운의 문자열이라고 한다고 한다. 준영이는 문자열 S를 분석하기 시작했다. 준영이는 문자열 S에 나오는 문자를 재배치하면 서로 다른 행운의 문자열이 몇 개 나오는지 궁금해졌다. 만약 원래 문자열 S도 행운의 문자열이라면 그것도 개수에 포함한다.

입력
첫째 줄에 문자열 S가 주어진다. S의 길이는 최대 10이고, 알파벳 소문자로만 이루어져 있다.

출력
첫째 줄에 위치를 재배치해서 얻은 서로 다른 행운의 문자열의 개수를 출력한다.

순열 개념

*/