#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>

using namespace std;

int n, m, ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	vector<int> rollcakes;
	vector<int> rollcakesWithMult;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 10) {
			ans++;
		}
		else if (x % 10 == 0) {
			rollcakesWithMult.push_back(x);
		}
		else if (x > 10) {
			rollcakes.push_back(x);
		}
	}

	sort(rollcakesWithMult.begin(), rollcakesWithMult.end());

	int length = rollcakesWithMult.size();
	for (int i = 0; i < length; i++) {
		while (rollcakesWithMult[i] > 10) {
			if (m <= 0) break;
			ans++; m--;
			rollcakesWithMult[i] -= 10;
		}
		if (rollcakesWithMult[i] == 10) ans++;
	}

	length = rollcakes.size();
	for (int i = 0; i < length; i++) {
		while (rollcakes[i] > 10) {
			if (m <= 0) break;
			ans++; m--;
			rollcakes[i] -= 10;
		}
		if (rollcakes[i] == 10) ans++;
	}

	cout << ans << '\n';
}


/*
16206. 롤케이크
https://www.acmicpc.net/problem/16206

문제
오늘은 재현이의 생일이다. 재현이는 친구 N명에게 롤케이크를 1개씩 선물로 받았다. 롤케이크의 길이는 A1, A2, ..., AN이다. 재현이는 길이가 10인 롤케이크만 먹는다. 따라서, 롤케이크를 잘라서 길이가 10인 롤케이크를 최대한 많이 만들려고 한다.

롤케이크는 다음과 같은 과정을 통해서 자를 수 있다.

자를 롤케이크를 하나 고른다. 길이가 1보다 큰 롤케이크만 자를 수 있다. 이때, 고른 롤케이크의 길이를 x라고 한다.
0보다 크고, x보다 작은 자연수 y를 고른다.
롤케이크를 잘라 길이가 y, x-y인 롤케이크 두 개로 만든다.
재현이는 롤케이크를 최대 M번 자를 수 있다. 이때, 만들 수 있는 길이가 10인 롤케이크 개수의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 롤케이크의 개수 N과 자를 수 있는 최대 횟수 M이 주어진다. (1 ≤ N, M ≤ 1,000)

둘째 줄에 롤케이크의 길이 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 1,000)

출력
재현이가 만들 수 있는 길이가 10인 롤케이크 개수의 최댓값을 출력한다.
*/