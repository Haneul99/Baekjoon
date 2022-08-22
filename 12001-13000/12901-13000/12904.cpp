#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string S, T; cin >> S >> T;

	while (T.length() != S.length()) {
		if(T[T.length() - 1] == 'A') {
			T = T.substr(0, T.length() - 1);
		}
		else {
			T = T.substr(0, T.length() - 1);
			reverse(T.begin(), T.end());
		}
	}
	
	if (S == T) cout << "1\n";
	else cout << "0\n";
}


/*
12904. A와 B
https://www.acmicpc.net/problem/12904

문제
수빈이는 A와 B로만 이루어진 영어 단어가 존재한다는 사실에 놀랐다. 대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다. 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다. 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

문자열의 뒤에 A를 추가한다.
문자열을 뒤집고 뒤에 B를 추가한다.
주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 S가 둘째 줄에 T가 주어진다. (1 ≤ S의 길이 ≤ 999, 2 ≤ T의 길이 ≤ 1000, S의 길이 < T의 길이)

출력
S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다.

뒤에 A를 추가한다.
뒤집고 뒤에 B를 추가한다.

그러면 일단 완성될 문자열에 A와 B가 몇 번 추가되어야 하는지를 알아야 한다... 
예제 1의 경우, 2번의 A추가 한번의 B추가가 필요하다.

뒤집어서 시도해본다.
뒤에 A를 제거한다.
뒤에 B를 제거하고 뒤집는다.
*/