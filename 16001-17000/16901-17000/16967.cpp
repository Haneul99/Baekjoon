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

	int H, W, X, Y;
	int arr[601][601] = { 0 };

	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = X; i < H; i++) {
		for (int j = Y; j < W; j++) {
			arr[i][j] -= arr[i - X][j - Y];
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}


/*
16967. 배열 복원하기
https://www.acmicpc.net/problem/16967

문제
크기가 H × W인 배열 A와 두 정수 X와 Y가 있을 때, 크기가 (H + X) × (W + Y)인 배열 B는 배열 A와 배열 A를 아래로 X칸, 오른쪽으로 Y칸 이동시킨 배열을 겹쳐 만들 수 있다. 수가 겹쳐지면 수가 합쳐진다.

즉, 배열 B의 (i, j)에 들어있는 값은 아래 3개 중 하나이다.

(i, j)가 두 배열 모두에 포함되지 않으면, Bi,j = 0이다.
(i, j)가 두 배열 모두에 포함되면, Bi,j = Ai,j + Ai-X,j-Y이다.
(i, j)가 두 배열 중 하나에 포함되면, Bi,j = Ai,j 또는 Ai-X,j-Y이다.
배열 B와 정수 X, Y가 주어졌을 때, 배열 A를 구해보자.

입력
첫째 줄에 네 정수 H, W, X, Y가 주어진다. 둘째 줄부터 H + X개의 줄에 배열 B의 원소가 주어진다.

항상 배열 A가 존재하는 경우만 입력으로 주어진다.

출력
총 H개의 줄에 배열 A의 원소를 출력한다.
*/