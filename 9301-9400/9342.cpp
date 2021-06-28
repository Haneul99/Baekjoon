#include<iostream>
#include<string>
#include<algorithm>
#include<regex>


using namespace std;


int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;

	regex reg("[A|B|C|D|E|F]{0,1}A+F+C+[A|B|C|D|E|F]*");

	while (t--) {
		string str;
		cin >> str;

		if (regex_match(str, reg)) cout << "Infected!\n";
		else cout << "Good\n";

	}

}



/*
9342. 염색체
https://www.acmicpc.net/problem/9342

문제
상근이는 생명과학 연구소에서 염색체가 특정한 패턴인지를 확인하는 일을 하고 있다. 염색체는 알파벳 대문자 (A, B, C, ..., Z)로만 이루어진 문자열이다. 상근이는 각 염색체가 다음과 같은 규칙을 만족하는지 검사해야 한다.

문자열은 {A, B, C, D, E, F} 중 0개 또는 1개로 시작해야 한다.
그 다음에는 A가 하나 또는 그 이상 있어야 한다.
그 다음에는 F가 하나 또는 그 이상 있어야 한다.
그 다음에는 C가 하나 또는 그 이상 있어야 한다.
그 다음에는 {A, B, C, D, E, F} 중 0개 또는 1개가 있으며, 더 이상의 문자는 없어야 한다.
문자열이 주어졌을 때, 위의 규칙을 만족하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T ≤ 20 이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 최대 200개의 알파벳 대문자로 이루어진 문자열이 주어진다.

출력
각 테스트 케이스에 대해서, 문제의 규칙을 지키는 문자열인 경우에는  "Infected!"를, 아닌 경우에는 "Good"을 출력한다.
*/
