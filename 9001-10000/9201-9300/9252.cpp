#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 1010

using namespace std;

int DP[MAX][MAX] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string A, B; cin >> A >> B;
	int Alen = A.length(), Blen = B.length();

	for (int i = 0; i < Alen; i++) {
		for (int j = 0; j < Blen; j++) {
			if (A[i] == B[j]) DP[i + 1][j + 1] = DP[i][j] + 1;
			else DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j + 1]);
		}
	}
	
	string ans = "";
	int row = Alen, col = Blen;
	while (DP[row][col] > 0) {
		if (DP[row][col] == DP[row - 1][col]) {
			row--;
		}//왼쪽에서 받아온 값인 경우
		else if (DP[row][col] == DP[row][col - 1]) {
			col--;
		}//위에서 받아온 값인 경우
		else {
			ans = A[row - 1] + ans;
			row--; col--;
		}
	}

	cout << DP[Alen][Blen] << '\n' << ans << '\n';
}


/*
9252. LCS 2
https://www.acmicpc.net/problem/9252

문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.

LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.

string을 배열에 삽입할 경우, 복사하는 시간이 string의 시간만큼 걸리게 됨. 그래서 LCS 배열을 만들어 DP배열처럼 사용할 경우 시간초과 발생.
그렇기 때문에 최종 값(DP[A.lenght()][B.length()])에서부터 시작해서 DP[i+1][j+1] = DP[i][j]+1 로, 값이 증가한 부분을 찾아나가는 것.
왼쪽이나 위 중 같은 값이 있다면 그곳에서 받아온 것이기 때문에 탐색 위치를 변경해주고,
둘 중 같은 값이 없다면 +1 된 것이므로 해당 위치의 문자열을 추가해줌.
*/ 