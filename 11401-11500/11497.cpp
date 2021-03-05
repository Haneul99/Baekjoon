#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[10001];
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		sort(arr, arr + n);
		int ans = 0;
		for (int i = 0; i < n - 2; i += 2) {
			if (abs(arr[i] - arr[i + 2]) > ans) {
				ans = abs(arr[i] - arr[i + 2]);
			}
		}
		for (int i = 1; i < n - 2; i += 2) {
			if (abs(arr[i] - arr[i + 2]) > ans) {
				ans = abs(arr[i] - arr[i + 2]);
			}
		}
		if (abs(arr[n - 1] - arr[n - 2]) > ans) {
			ans = abs(arr[n - 1] - arr[n - 2]);
		}
		if (abs(arr[1] - arr[0]) > ans) {
			ans = abs(arr[1] - arr[0]);
		}
		printf("%d\n", ans);
	}
}


                                                 
/*
11497. 통나무 건너뛰기
https://www.acmicpc.net/problem/11497

문제
남규는 통나무를 세워 놓고 건너뛰기를 좋아한다. 그래서 N개의 통나무를 원형으로 세워 놓고 뛰어놀려고 한다. 남규는 원형으로 인접한 옆 통나무로 건너뛰는데, 이때 각 인접한 통나무의 높이 차가 최소가 되게 하려 한다.



통나무 건너뛰기의 난이도는 인접한 두 통나무 간의 높이의 차의 최댓값으로 결정된다. 높이가 {2, 4, 5, 7, 9}인 통나무들을 세우려 한다고 가정하자. 이를 [2, 9, 7, 4, 5]의 순서로 세웠다면, 가장 첫 통나무와 가장 마지막 통나무 역시 인접해 있다. 즉, 높이가 2인 것과 높이가 5인 것도 서로 인접해 있다. 배열 [2, 9, 7, 4, 5]의 난이도는 |2-9| = 7이다. 우리는 더 나은 배열 [2, 5, 9, 7, 4]를 만들 수 있으며 이 배열의 난이도는 |5-9| = 4이다. 이 배열보다 난이도가 낮은 배열은 만들 수 없으므로 이 배열이 남규가 찾는 답이 된다.

입력
입력은 T개의 테스트 케이스로 이루어져 있다. 첫 줄에 T가 주어진다.

이어지는 각 줄마다 첫 줄에 통나무의 개수를 나타내는 정수 N(5 ≤ N ≤ 10,000), 둘째 줄에 각 통나무의 높이를 나타내는 정수 Li가 주어진다. (1 ≤ Li ≤ 100,000)

출력
각 테스트 케이스마다 한 줄에 주어진 통나무들로 만들 수 있는 최소 난이도를 출력하시오.

*/                      