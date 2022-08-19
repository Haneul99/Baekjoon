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
	int cnt[10] = { 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 1 };
	
	int n, ans = 0; cin >> n;
	int idx = 0;
	while (n > 0) {
		if (cnt[idx] < n) {
			ans += cnt[idx] * (idx + 1);
			n -= cnt[idx];
			idx++;
		}
		else {
			ans += n * (idx + 1);
			break;
		}
	}
	cout << ans << '\n';
}


/*
1748. 수 이어 쓰기 1
https://www.acmicpc.net/problem/1748

문제
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 100,000,000)이 주어진다.

출력
첫째 줄에 새로운 수의 자릿수를 출력한다.
*/