#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, ans = 0; cin >> n >> m;
	int arr[51][51] = { 0, };

	for (int i = 0; i < n; i++) {
		string numbers; cin >> numbers;
		for (int j = 0; j < m; j++) {
			arr[i][j] = numbers[j] - '0';
		}
	}

	int size = min(n, m);
	bool flag = false;
	for (int k = size - 1; k >= 0; k--) {
		for (int i = 0; i < n - k; i++) {
			for (int j = 0; j < m - k; j++) {
				if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j + k]) {
					ans = (k + 1) * (k + 1);
					flag = true;
				}
			}
		}
		if (flag) break;
	}
	cout << ans << '\n';
}


/*
1051. 숫자 정사각형
https://www.acmicpc.net/problem/1051

문제
N×M크기의 직사각형이 있다. 각 칸에는 한 자리 숫자가 적혀 있다. 이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오. 이때, 정사각형은 행 또는 열에 평행해야 한다.

입력
첫째 줄에 N과 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 수가 주어진다.

출력
첫째 줄에 정답 정사각형의 크기를 출력한다.

3 5
42101
22100
22101

9

정사각형 크기 출력
*/