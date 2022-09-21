#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 110

using namespace std;

int GCD(int a, int b) {
	if (a % b == 0) return b;
	return GCD(b, a % b);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> nums;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		nums.push_back(x);
	}
	sort(nums.begin(), nums.end());

	int gcd = nums[1] - nums[0];
	for (int i = 2; i < N; i++) {
		gcd = GCD(gcd, nums[i] - nums[i - 1]);
	}//모든 수를 만족하는 최대공약수 찾기

	vector<int> result;
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i == 0) {
			result.push_back(i);
			result.push_back(gcd / i);
		}
	}//최대공약수와 그 약수들 구하기

	result.push_back(gcd);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}


/*
2981. 검문
https://www.acmicpc.net/problem/2981

문제
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 검문하는데 엄청나게 오랜 시간이 걸린다.

상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.

먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

입력
첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)

다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.

항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

출력
첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다.

arr[i] = gcd * 몫 + 나머지
의 형태이기 때문에
arr[i] - arr[i-1] = gcd*q(i) - gcd*q(i-1) + (R - R)
-> gcd를 구할 수 있음. 이걸 모든 수에 대해 반복하면 모든 수를 만족하는 최대공약수를 구할 수 있음.
최대 공약수의 약수들을 정답에 추가한 후, 중복값을 제거하면 정답이 됨.
*/ 