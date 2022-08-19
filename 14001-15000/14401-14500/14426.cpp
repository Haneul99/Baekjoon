#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

vector<string> wordSet;
int n, m, ans = 0;

bool checkPrefix(string word) {
	bool isPrefix = false;
	for (int i = 0; i < n; i++) {
		if (isPrefix) return isPrefix;

		int wordSize = word.size();
		if (wordSize > wordSet[i].size()) continue;

		bool flag = true;
		for (int j = 0; j < wordSize; j++) {
			if (word[j] != wordSet[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) isPrefix = true;
	}
	return isPrefix;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		wordSet.push_back(word);
	}

	for (int i = 0; i < m; i++) {
		string word; cin >> word;
		if (checkPrefix(word)) {
			ans++;
		}
	}

	cout << ans << '\n';
}


/*
14426. 접두사 찾기
https://www.acmicpc.net/problem/14426

문제
문자열 S의 접두사란 S의 가장 앞에서부터 부분 문자열을 의미한다. 예를 들어, S = "codeplus"의 접두사는 "code", "co", "codepl", "codeplus"가 있고, "plus", "s", "cude", "crud"는 접두사가 아니다.

총 N개의 문자열로 이루어진 집합 S가 주어진다.

입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 문자열 중 적어도 하나의 접두사인 것의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다.

다음 N개의 줄에는 집합 S에 포함되어 있는 문자열이 주어진다.

다음 M개의 줄에는 검사해야 하는 문자열이 주어진다.

입력으로 주어지는 문자열은 알파벳 소문자로만 이루어져 있으며, 길이는 500을 넘지 않는다. 집합 S에 같은 문자열이 여러 번 주어지는 경우는 없다.

출력
첫째 줄에 M개의 문자열 중에 총 몇 개가 포함되어 있는 문자열 중 적어도 하나의 접두사인지 출력한다.
*/