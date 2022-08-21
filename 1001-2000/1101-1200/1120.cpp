#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;

int compareString(string A, string B) {
	int lenA = A.size(), lenB = B.size();
	int minDiff = 1234567890;

	for (int i = 0; i <= lenA - lenB; i++) {
		//비교 시작하는 string A에서의 position
		int diffCount = 0;
		for (int j = 0; j < lenB; j++) {
			if (A[i + j] != B[j]) diffCount++;
		}
		minDiff = min(minDiff, diffCount);
	}
	return minDiff;
}//문자열 길이가 더 긴것을 A, 짧은것을 B라고 함.


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string strA, strB; cin >> strA >> strB;
	int strALen = strA.size(), strBLen = strB.size();
	int ans = 0;
	if (strALen >= strBLen) {
		ans = compareString(strA, strB);
	}
	else {
		ans = compareString(strB, strA);
	}

	cout << ans << '\n';
}


/*
1120. 문자열
https://www.acmicpc.net/problem/1120

문제
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.

두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. A와 B의 길이는 최대 50이고, A의 길이는 B의 길이보다 작거나 같고, 알파벳 소문자로만 이루어져 있다.

출력
A와 B의 길이가 같으면서, A와 B의 차이를 최소가 되도록 했을 때, 그 차이를 출력하시오.

더 짧은 문자열을 긴 문자열에 대서 가장 차이가 적은 것을 찾는 것
*/