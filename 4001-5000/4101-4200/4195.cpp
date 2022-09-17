#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<map>
#define MAX 200010

using namespace std;

map<string, int> names;
int parents[MAX];
int friends[MAX];

int FIND(int x) {
	if (parents[x] == x) return x;
	return parents[x] = FIND(parents[x]);
}

void UNION(int x, int y) {
	x = FIND(x);
	y = FIND(y);

	//x와 y가 다르기 때문에 둘은 다른 집합임을 알 수 있음.
	if (x > y) {
		parents[x] = y;
		friends[y] += friends[x];
	}
	else if (y > x) {
		parents[y] = x;
		friends[x] += friends[y];
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;

	while (T--) {
		int F; cin >> F;
		for (int i = 0; i <= F * 2; i++) {
			parents[i] = i;
			friends[i] = 1;
		}
		names.clear();
		int idx = 0;
		for (int i = 0; i < F; i++) {
			string A, B; cin >> A >> B;
			if (names.count(A) == 0) {
				names[A] = idx;
				idx++;
			}
			if (names.count(B) == 0) {
				names[B] = idx;
				idx++;
			}
			UNION(names[A], names[B]);
			int parent1 = FIND(names[A]);
			int parent2 = FIND(names[B]);
			cout << max(friends[parent1], friends[parent2]) << '\n';
		}
	}
}


/*
4195. 친구 네트워크
https://www.acmicpc.net/problem/4195

문제
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.

어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.

출력
친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
*/ 