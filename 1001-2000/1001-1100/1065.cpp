#include<stdio.h>
#include<string>

using namespace std;



int main() {
	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		string num = to_string(i);
		int len = num.length();
		if (len == 1) {
			ans++; continue;
		}
		int diff = num[1] - num[0];
		int flag = 0;
		for (int j = 1; j < len - 1; j++) {
			if (num[j + 1] - num[j] != diff) {
				flag = 1;
				break;
			}
		}//1234 : 01, 12, 23 len=4
		if (!flag) ans++;
	}
	printf("%d\n", ans);
}

/*
1065. 한수
https://www.acmicpc.net/problem/1065

문제
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.


110 99
1 1
210 105
1000 144
*/