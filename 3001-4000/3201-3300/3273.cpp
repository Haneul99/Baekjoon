#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, target, ans = 0; cin >> n;
	vector<int> numbers;
	
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		numbers.push_back(x);
	}
	cin >> target;
	sort(numbers.begin(), numbers.end());

	int left = 0, right = n - 1;
	while (left < right && left <= n - 1 && right >= 0) {
		if (numbers[left] + numbers[right] == target) {
			ans++;
			left++;
			right--;
		}
		else if (numbers[left] + numbers[right] > target) {
			right--;
		}
		else {
			left++;
		}
	}
	cout << ans << '\n';
}


/*
3273. 두 수의 합
https://www.acmicpc.net/problem/3273

문제
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

출력
문제의 조건을 만족하는 쌍의 개수를 출력한다.
*/