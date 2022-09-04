#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	
	priority_queue<long long, vector<long long>, greater<long long>> cards;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long x; cin >> x;
		sum += x;
		cards.push(x);
	}

	while (m--) {
		long long first = cards.top(); cards.pop();
		long long second = cards.top(); cards.pop();
		cards.push(first + second);
		cards.push(first + second);
		sum += first + second;
	}

	cout << sum << '\n';
}


/*
15903. 카드 합체 놀이
https://www.acmicpc.net/problem/15903

문제
석환이는 아기다. 아기 석환이는 자연수가 쓰여져있는 카드를 갖고 다양한 놀이를 하며 노는 것을 좋아한다. 오늘 아기 석환이는 무슨 놀이를 하고 있을까? 바로 카드 합체 놀이이다!

아기 석환이는 자연수가 쓰여진 카드를 n장 갖고 있다. 처음에 i번 카드엔 ai가 쓰여있다. 카드 합체 놀이는 이 카드들을 합체하며 노는 놀이이다. 카드 합체는 다음과 같은 과정으로 이루어진다.

x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산한다. (x ≠ y)
계산한 값을 x번 카드와 y번 카드 두 장 모두에 덮어 쓴다.
이 카드 합체를 총 m번 하면 놀이가 끝난다. m번의 합체를 모두 끝낸 뒤, n장의 카드에 쓰여있는 수를 모두 더한 값이 이 놀이의 점수가 된다. 이 점수를 가장 작게 만드는 것이 놀이의 목표이다.

아기 석환이는 수학을 좋아하긴 하지만, 아직 아기이기 때문에 점수를 얼마나 작게 만들 수 있는지를 알 수는 없었다(어른 석환이는 당연히 쉽게 알 수 있다). 그래서 문제 해결 능력이 뛰어난 여러분에게 도움을 요청했다. 만들 수 있는 가장 작은 점수를 계산하는 프로그램을 만들어보자.

입력
첫 번째 줄에 카드의 개수를 나타내는 수 n(2 ≤ n ≤ 1,000)과 카드 합체를 몇 번 하는지를 나타내는 수 m(0 ≤ m ≤ 15×n)이 주어진다.

두 번째 줄에 맨 처음 카드의 상태를 나타내는 n개의 자연수 a1, a2, …, an이 공백으로 구분되어 주어진다. (1 ≤ ai ≤ 1,000,000)

출력
첫 번째 줄에 만들 수 있는 가장 작은 점수를 출력한다.

a b c d e f g ... 이런식으로 간다면 a, b를 선택했을 때 a+b b+a 이렇게 바뀌기 때문에 카드 총합이 결국 a+b만큼 증가하게 됨. 그렇기 때문에 최솟값 두 장을 선택해야 최소 총합을 만들 수 있음.
우선순위큐 말고 벡터 사용으로 정렬해도 문제 해결 가능.
long long first = cards[0];
long long second = cards[1];
sum += first + second;
cards[0] += second;
cards[1] += first;
*/