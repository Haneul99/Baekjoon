#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>


using namespace std;

int n;
map<int, int> m;


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		m[x]++;
	}

	int ans = 0;
	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (ans < it->second) ans = it->second;
	}
	printf("%d\n", ans);
}


/*
20937. 떡국
https://www.acmicpc.net/problem/20937

문제


Naver D2를 아시나요? D2는 For Developers, By Developers의 약자로, 개발자들을 위해 개발자들이 직접 만들어 가고 있는 네이버 개발자 지원 프로그램입니다. 네이버가 축적한 기술과 지식을 공유하고, 외부 개발자들을 지원해 대한민국 개발자 역량 강화를 이끌고, 이를 통해 업계 전체와 네이버가 함께 성장하는 선순환 구조를 만들고자 합니다.

사실 네이버의 개발자 지원은 오랜 기간 꾸준히 이어져 왔습니다. 개발자 컨퍼런스 DEVIEW를 비롯, 오픈 소스와 개발 도구 공개, 학회 및 커뮤니티 지원 등 여러 지원 프로그램이 있었습니다. 이런 다양한 프로그램을 하나로 통합한 것이 바로 Naver D2입니다.

함께 성장하는 개발자 지원 프로그램인 NAVER D2에서는 매년 개발자 컨퍼런스 DEVIEW를 개최한다.

2021년 DEVIEW에도 다양한 주제를 선보이기 위한 발표 준비 작업이 한창이다. 그런데 아주 큰 문제가 생겼다. 책상 위에 다 먹고 남은 떡국 그릇이 너무 많이 쌓여 작업을 진행할 수가 없다. 우연히 옆을 지나가던 당신이 이를 도와주기로 했다!

떡국 그릇 위에는 크기가 더 작은 떡국 그릇 하나를 쌓을 수 있다. 쌓은 떡국 그릇 위에 같은 방법으로 떡국 그릇을 또 쌓을 수 있다. 예를 들어, 크기가 $4$, $2$, $3$, $1$인 떡국 그릇에 대해 $4-3-2-1$ 순서로 쌓을 수 있지만 $3-4-2-1$ 순서로는 쌓을 수 없다. 이렇게 쌓은 한 개 이상의 떡국 그릇들을 떡국 그릇 탑이라고 하자.

당신은 떡국 그릇 탑의 개수를 최소로 만들어 책상 위의 공간을 확보하려고 한다.

다음은 $4$, $2$, $3$, $1$, $2$인 떡국 그릇으로 쌓을 수 있는 떡국 그릇 탑의 개수의 예시이고, 최소 개수는 $2$개이다.

 $5$개 : $[4,\,2,\,3,\,1,\,2]$ 
 $4$개 : $[4-2,\,3,\,1,\,2]$ 또는 $[4-3,\,2,\,1,\,2]$ 또는 $[4,\,3-2,\,1,\,2]$ 또는 $\cdots$ 
 $3$개 : $[4-2,\,3-1,\,2]$ 또는 $[4-1,\,3-2,\,2]$ 또는 $[4-3,\,2-1,\,2]$ 또는 $\cdots$ 
 $2$개 : $[4-2,\,3-2-1]$ 또는 $[4-2-1,\,3-2]$ 또는 $[4-3-2,\,2-1]$ 또는 $\cdots$ 
 $1$개의 떡국 그릇 탑으로 만들 수 없다.
떡국 그릇들의 크기가 주어졌을 때, 떡국 그릇 탑의 최소 개수를 구해주자. 당신에게 감사의 표시로 NAVER D2에서 후원하는 SUAPC 2021w의 한 문제를 정답 처리해줄 것이다.

입력
다음과 같이 입력이 주어진다.

 $N$ 

 $c_1 \ c_2 \ ... \ c_N$ 

출력
떡국 그릇 탑의 최소 개수를 출력한다.
*/