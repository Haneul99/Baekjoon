#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string roomNumber; cin >> roomNumber;
	int ans = 0;
	int len = roomNumber.size();

	int cnt[11] = { 0, };
	for (int i = 0; i < len; i++) {
		cnt[roomNumber[i] - '0']++;
	}

	cnt[6] = ceil((cnt[6] + cnt[9]) / 2.0);
	for (int i = 0; i < 9; i++) {
		ans = max(ans, cnt[i]);
	}

	cout << ans << '\n';
}


/*
1475. 방 번호
https://www.acmicpc.net/problem/1475

문제
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

입력
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 필요한 세트의 개수를 출력한다.

그니깐 6이랑 9는 합쳐서 세면 되고 필요한 세트 수는 절반임

*/