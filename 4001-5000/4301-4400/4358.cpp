#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout << fixed; cout.precision(4);
	map<string, int> speciesMap;
	int size = 0;
	while (true) {
		string species; getline(cin, species);
		if (cin.eof()) break;
		speciesMap[species]++;
		size++;
	}
	for (auto species : speciesMap) {
		cout << species.first << ' ' << double(species.second) / double(size) * 100.0 << '\n';
	}
}


/*
4358. 생태학
https://www.acmicpc.net/problem/4358

문제
생태학에서 나무의 분포도를 측정하는 것은 중요하다. 그러므로 당신은 미국 전역의 나무들이 주어졌을 때, 각 종이 전체에서 몇 %를 차지하는지 구하는 프로그램을 만들어야 한다.

입력
프로그램은 여러 줄로 이루어져 있으며, 한 줄에 하나의 나무 종 이름이 주어진다. 어떤 종 이름도 30글자를 넘지 않으며, 입력에는 최대 10,000개의 종이 주어지고 최대 1,000,000그루의 나무가 주어진다.

출력
주어진 각 종의 이름을 사전순으로 출력하고, 그 종이 차지하는 비율을 백분율로 소수점 4째자리까지 반올림해 함께 출력한다.
*/