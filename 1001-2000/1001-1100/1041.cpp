#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;

long long n;
long long oneD = 1234567890, twoD = 1234567890, threeD = 1234567890;
vector<long long> dices;

void getMinComb() {
	for (int i = 0; i < 6; i++) {
		oneD = min(oneD, dices[i]);
	}

	vector<long long> tD;
	for (int i = 1; i < 5; i++) {
		tD.push_back(dices[0] + dices[i]);
	}//AB, AC, AD, AE
	tD.push_back(dices[1] + dices[2]);//BC
	tD.push_back(dices[1] + dices[3]);//BD
	tD.push_back(dices[1] + dices[5]);//BF

	tD.push_back(dices[2] + dices[4]);//CE
	tD.push_back(dices[2] + dices[5]);//CF

	tD.push_back(dices[3] + dices[4]);//DE
	tD.push_back(dices[3] + dices[5]);//DF

	tD.push_back(dices[4] + dices[5]);//EF

	sort(tD.begin(), tD.end());
	twoD = tD[0];

	tD.clear();
	tD.push_back(dices[0] + dices[1] + dices[2]);//ABC
	tD.push_back(dices[0] + dices[1] + dices[3]);//ABD
	tD.push_back(dices[0] + dices[2] + dices[4]);//ACE
	tD.push_back(dices[0] + dices[3] + dices[4]);//ADE

	tD.push_back(dices[1] + dices[2] + dices[5]);//BCF
	tD.push_back(dices[1] + dices[3] + dices[5]);//BDF
	tD.push_back(dices[2] + dices[4] + dices[5]);//CEF
	tD.push_back(dices[3] + dices[4] + dices[5]);//DEF
	sort(tD.begin(), tD.end());
	threeD = tD[0];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < 6; i++) {
		int x; cin >> x;
		dices.push_back(x);
	}

	long long ans = 0;

	if (n == 1) {
		sort(dices.begin(), dices.end());
		for (int i = 0; i < 5; i++) {
			ans += dices[i];
		}
	}
	else {
		getMinComb();
		ans = threeD * 4 + twoD * (8 * n - 12) + oneD * (5 * n*n - 16 * n + 12);
	}
	cout << ans << '\n';
}


/*
1041. 주사위
https://www.acmicpc.net/problem/1041

문제
	+---+
	| D |
+---+---+---+---+
| E | A | B | F |
+---+---+---+---+
	| C |
	+---+
주사위는 위와 같이 생겼다. 주사위의 여섯 면에는 수가 쓰여 있다. 위의 전개도를 수가 밖으로 나오게 접는다.

A, B, C, D, E, F에 쓰여 있는 수가 주어진다.

지민이는 현재 동일한 주사위를 N3개 가지고 있다. 이 주사위를 적절히 회전시키고 쌓아서, N×N×N크기의 정육면체를 만들려고 한다. 이 정육면체는 탁자위에 있으므로, 5개의 면만 보인다.

N과 주사위에 쓰여 있는 수가 주어질 때, 보이는 5개의 면에 쓰여 있는 수의 합의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에 주사위에 쓰여 있는 수가 주어진다. 위의 그림에서 A, B, C, D, E, F에 쓰여 있는 수가 차례대로 주어진다. N은 1,000,000보다 작거나 같은 자연수이고, 쓰여 있는 수는 50보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.
*/