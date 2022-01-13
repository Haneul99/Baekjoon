#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>


using namespace std;


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	
	vector<int> hills;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		hills.push_back(x);
	}

	sort(hills.begin(), hills.end());

	int ans = 1234567890;

	if (hills[n - 1] - hills[0] <= 17) ans = 0;
	else {
		for (int i = 1; i <= hills[n - 1] - 17; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (hills[j] < i) sum += (i - hills[j])*(i - hills[j]);
				else if (hills[j] > i + 17) sum += (hills[j] - i - 17)*(hills[j] - i - 17);
			}
			ans = min(ans, sum);
		}//i는 시작 숫자
	}

	printf("%d\n", ans);
}


/*
9881. Ski Course Design
https://www.acmicpc.net/problem/9881

문제
Farmer John has N hills on his farm (1 <= N <= 1,000), each with an integer elevation in the range 0 .. 100. In the winter, since there is abundant snow on these hills, FJ routinely operates a ski training camp.

Unfortunately, FJ has just found out about a new tax that will be assessed next year on farms used as ski training camps. Upon careful reading of the law, however, he discovers that the official definition of a ski camp requires the difference between the highest and lowest hill on his property to be strictly larger than 17. Therefore, if he shortens his tallest hills and adds mass to increase the height of his shorter hills, FJ can avoid paying the tax as long as the new difference between the highest and lowest hill is at most 17.

If it costs x^2 units of money to change the height of a hill by x units, what is the minimum amount of money FJ will need to pay? FJ is only willing to change the height of each hill by an integer amount.

입력
Line 1: The integer N.
Lines 2..1+N: Each line contains the elevation of a single hill.
출력
Line 1: The minimum amount FJ needs to pay to modify the elevations of his hills so the difference between largest and smallest is at most 17 units.

가장 높은거랑 가장 낮은거의 높이를 수정해야함

언덕들의 높이의 range가
1-18 / 2-19 / 3-20 / ... / 83-100 이어야 함
언덕들의 높이의 range가 1-18일경우, 모든 언덕들의 높이를 1-18로 조정해줘야함(100까지 갈 거 없이 max까지 가는걸로 하면 되겠다)
ex.1 4 20 21 24 -> 범위를 넘어가는거 (20, 21, 24 -> (x-18)^2) --> 이 예시는 4-21이 정답범위

*/