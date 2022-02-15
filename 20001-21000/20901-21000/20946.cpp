#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n;
	scanf("%lld", &n);
	long long limit = sqrt(n);

	vector<long long> arr;
	while (1) {
		if (n % 2 == 0) {
			arr.push_back(2);
			n /= 2;
		}
		else break;
	}

	for (long long i = 3; i <= limit; i += 2) {
		while (1) {
			if (n % i == 0) {
				arr.push_back(i);
				n /= i;
			}
			else break;
		}
	}

	if (n != 1) arr.push_back(n);

	int len = arr.size();	

	if (len < 2) {
		printf("-1\n");
	}
	else {
		if (len % 2 == 0) {
			for (int i = 0; i < len; i += 2) {
				printf("%lld ", arr[i] * arr[i + 1]);
			}
		}
		else {
			for (int i = 0; i < len - 3; i += 2) {
				printf("%lld ", arr[i] * arr[i + 1]);
			}
			printf("%lld", arr[len - 3] * arr[len - 2] * arr[len - 1]);
		}
	}
}


/*
20946. 합성인수분해
https://www.acmicpc.net/problem/20946

문제
소인수분해란 어떤 자연수를 소수의 곱으로 나타내는 것이다. 정수론을 끔찍하게 싫어하는 연두는 소수만 보면 치가 떨려, 대신에 자연수를 합성수의 곱으로 나타내는 “합성인수분해”라는 것을 만들었다.

자연수 $N$의 합성인수분해는 다음의 조건을 모두 만족하는 수열 $A$로 정의한다.

 $A$의 모든 원소는 합성수이다. (합성수란 $1$과 자기 자신 이외의 다른 약수를 가지는 정수이다.)
 $A$의 모든 원소의 곱은 $N$이다.
하지만 연두는 $N$의 합성인수분해가 여러 개이거나 존재하지 않을 수도 있다는 것을 깨달았다. 연두를 대신해 $N$을 합성인수분해 해주는 프로그램을 만들어보자. 만약 가능한 결과가 여러 개일 경우, 사전 순으로 가장 앞서는 것을 선택해야 한다.

입력
다음과 같이 입력이 주어진다.

 $N$
출력
 $N$의 합성인수분해 중 사전순으로 가장 앞서는 수열의 원소들을 순서대로 공백으로 구분하여 출력한다.

합성인수분해가 불가능하다면 대신에 -1을 출력한다.
*/