#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<math.h>
#define MAX 5010

using namespace std;

int n, ans;
int arr[MAX] = { 0, }, cnt[MAX];


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		int val = 1;
		for (int j = 0; j <= i; j++) {
			if (arr[i] % arr[j] == 0) {
				val = max(cnt[j] + 1, val);
			}
		}
		ans = max(ans, val);
		cnt[i] = val;
	}

	printf("%d\n", n - ans);
}


/*
19576. 약수
https://www.acmicpc.net/problem/19576

문제


♪ 한가람 구비구비 유구하네 / 와우의 푸른 기슭에 높이 솟은 진리의 전당 ♪
(홍익대학교 교가 / 이은상 작사, 김동진 작곡)

홍익대학교 바로 뒤편에 위치한 와우산의 와우약수터는 현재 폐쇄되어있다. 와우산의 정기가 그대로 흘러나오는 약수를 다시 회복하기 위한 “와우 프로젝트”가 시작되었다. 와우산의 지하수에는 여러 가지 미네랄 성분이 포함되어있다. 만약 지하수에 포함된 모든 미네랄 성분의 함량들의 관계가 약수면, 약수다.

다시 말해 모든 미네랄 성분의 함량의 쌍이 항상 약수(divisor)-배수 관계가 될 때, 이 지하수는 약수(mineral water)가 될 수 있다. 엄밀하게 표현하면, 지하수에 포함된 서로 다른 임의의 두 미네랄 성분의 함량 x, y에 대해 항상 x가 y로 나누어 떨어지거나 y가 x로 나누어 떨어져야한다.

당신은 “와우매직”이라는 특별한 마법을 사용하여, 지하수에 포함되어있는 미네랄 성분을 하나 골라 그 함량을 원하는 양의 정수로 바꿀 수 있다. “와우매직”을 최소한으로 사용하여 와우산의 지하수를 약수로 바꿔보자.

입력
첫 번째 줄에 와우산의 지하수에 포함되어있는 미네랄 성분의 개수 N이 주어진다. (1 ≤ N ≤ 5,000)

두 번째 줄에 각 미네랄 성분의 함량을 나타내는 정수 a1, a2, …, aN이 주어진다. (1 ≤ ai ≤ 109)

출력
와우산의 지하수를 약수로 바꾸기 위해 “와우매직”을 최소 몇 번 사용해야 하는지 출력한다.
*/