#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 4000010

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N; cin >> N;

	int check[MAX] = { 0, };
	check[0] = check[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= N; j += i) {
				check[j] = true;
			}
		}
	}

	vector<int> prime;
	for (int i = 2; i <= N; i++) {
		if (check[i] == false) prime.push_back(i);
	}

	int ans = 0, sum = 0, left = 0, right = 0;
	while (1) {
		if (sum >= N) sum -= prime[left++];
		else if (right == prime.size()) break;
		else sum += prime[right++];
		if (sum == N) ans++;
	}

	cout << ans << '\n';
}


/*
1644. 소수의 연속합
https://www.acmicpc.net/problem/1644

문제
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.

3 : 3 (한 가지)
41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
53 : 5+7+11+13+17 = 53 (두 가지)
하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.

자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

출력
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

1. 에라토스테네스의 체로 소수들을 400만까지 구해놓기
2. 두 포인터로 1부터 시작해서 target보다 작으면 오른쪽 포인터를 늘리고, 크면 왼쪽 포인터를 늘림
*/ 