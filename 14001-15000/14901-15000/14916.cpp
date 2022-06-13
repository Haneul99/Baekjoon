#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int money;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> money;
	if (money == 1 || money == 3) {
		cout << "-1\n";
		return 0;
	}

	int cnt2 = 0, cnt5 = 0;
	if ((money - 5 * (money / 5)) % 2 != 0) {
		cnt5 = money / 5 - 1;
		money -= cnt5 * 5;
		cnt2 = money / 2;
	}
	else {
		cnt5 = money / 5;
		money -= cnt5 * 5;
		cnt2 = money / 2;
	}
	cout << cnt2 + cnt5 << '\n';
}

/*
14916. 거스름돈
https://www.acmicpc.net/problem/14916

문제
춘향이는 편의점 카운터에서 일한다.

손님이 2원짜리와 5원짜리로만 거스름돈을 달라고 한다. 2원짜리 동전과 5원짜리 동전은 무한정 많이 가지고 있다. 동전의 개수가 최소가 되도록 거슬러 주어야 한다. 거스름돈이 n인 경우, 최소 동전의 개수가 몇 개인지 알려주는 프로그램을 작성하시오.

예를 들어, 거스름돈이 15원이면 5원짜리 3개를, 거스름돈이 14원이면 5원짜리 2개와 2원짜리 2개로 총 4개를, 거스름돈이 13원이면 5원짜리 1개와 2원짜리 4개로 총 5개를 주어야 동전의 개수가 최소가 된다.

입력
첫째 줄에 거스름돈 액수 n(1 ≤ n ≤ 100,000)이 주어진다.

출력
거스름돈 동전의 최소 개수를 출력한다. 만약 거슬러 줄 수 없으면 -1을 출력한다.
*/