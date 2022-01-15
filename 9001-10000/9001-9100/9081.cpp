#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string str;
		cin >> str;
		string ans = str;
		int flag = next_permutation(str.begin(), str.end());
		if (flag) {
			cout << str << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}
}


/*
9081. 단어 맞추기
https://www.acmicpc.net/problem/9081

문제
BEER라는 단어를 이루는 알파벳들로 만들 수 있는 단어들을 사전 순으로 정렬하게 되면

BEER
BERE
BREE
EBER
EBRE
EEBR
EERB
ERBE
EREB
RBEE
REBE
REEB
와 같이 된다. 이러한 순서에서 BEER 다음에 오는 단어는 BERE가 된다. 이와 같이 단어를 주면 그 단어를 이루는 알파벳들로 만들 수 있는 단어들을 사전 순으로 정렬할 때에 주어진 단어 다음에 나오는 단어를 찾는 프로그램을 작성하시오.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T (1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스는 하나의 단어가 한 줄로 주어진다. 단어는 알파벳 A~Z 대문자로만 이루어지며 항상 공백이 없는 연속된 알파벳으로 이루어진다. 단어의 길이는 100을 넘지 않는다.

출력
각 테스트 케이스에 대해서 주어진 단어 바로 다음에 나타나는 단어를 한 줄에 하나씩 출력하시오. 만일 주어진 단어가 마지막 단어이라면 그냥 주어진 단어를 출력한다.



5 6 7 8 9
5 6 7 9 8
5 6 8 9 7 -> 5 6 8 7 9
5 6 8 9 7

5 7 8 9 6 -> 5 7 6 8 9        ( 5 6 9 7 8 )





*/