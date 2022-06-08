#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string englishName, failedString = "I'm Sorry Hansoo", successString = "", outputString = "";
	cin >> englishName;
	int nameLen = englishName.size();

	char alpha[27] = { 0, };

	for (int i = 0; i < nameLen; i++) {
		alpha[englishName[i] - 'A']++;
	}

	int oddCount = 0;
	int oddIndex = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			oddCount++;
			oddIndex = i;
		}
		for (int j = 0; j < alpha[i] / 2; j++) {
			successString += char(i+'A');
		}
	}

	outputString += successString;
	if(oddCount == 1) outputString += char(oddIndex + 'A');
	reverse(successString.begin(), successString.end());
	outputString += successString;

	if (oddCount > 1) cout << failedString << '\n';
	else cout << outputString << '\n';
}



/*
1213. 팰린드롬 만들기
https://www.acmicpc.net/problem/1213

문제
임한수와 임문빈은 서로 사랑하는 사이이다.

임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.

임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.

임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

입력
첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.

ACBBA
-> 홀수개 있는건 반드시 가운데로 와야함. 만약에 홀수개 있는게 여러개라면 I'm Sorry Hansoo 출력.
-> 
*/