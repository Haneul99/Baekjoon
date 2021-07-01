﻿#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;


int main() {
	int woolim[10];
	int startlink[10];

	for (int i = 0; i < 9; i++) {
		scanf("%d", &woolim[i]);
	}

	for (int i = 0; i < 9; i++) {
		scanf("%d", &startlink[i]);
	}

	int wool_score = 0;
	int start_score = 0;
	string ans = "No";
	for (int i = 0; i < 9; i++) {
		wool_score += woolim[i];

		if (wool_score > start_score) {
			ans = "Yes";
			break;
		}		
		start_score += startlink[i];
	}

	cout << ans << '\n';
}



/*
14582. 오늘도 졌다
https://www.acmicpc.net/problem/14582

문제
프로야구팀 울림 제미니스는 오늘도 졌다. 이번에는 스타트링크 걸리버스의 4번타자가 끝내기 홈런을 쳐서 졌다. 울림 제미니스의 열렬한 팬인 지수는 속으로 화를 참으며 어떤 선수 때문에 졌는지 생각해보았다. 지수는 팀이 역전패를 했다면 불펜 투수의 책임이고, 그렇지 않다면 타자와 선발 투수의 책임이라고 생각했다.

지수는 오늘 경기에서 울림이 어떻게 졌는지 생각해보려 했지만, 기분이 너무 더러워서 뭘 할 의욕이 나지 않았다. 지수를 도와 오늘 경기에서 울림 제미니스가 역전패를 했는지 구하는 프로그램을 작성하여라. 역전패가 성립하려면 경기 도중 울림 제미니스가 이기고 있는 순간이 있어야 한다.

입력
첫 번째 줄에는 9개의 정수가 주어지는데, 오늘 경기에서 울림 제미니스가 1회 초, 2회 초, ..., 9회 초에 낸 득점이 주어진다.

두 번째 줄에도 9개의 정수가 주어지는데, 스타트링크 걸리버스가 1회 말, 2회 말, ..., 9회 말에 낸 득점이 주어진다.

한 팀이 한 회에 낸 득점은 모두 0 이상 20 이하이며, 스타트링크 걸리버스의 총 득점이 울림 제미니스의 총 득점보다 많다.

경기는 1회 초->1회 말->2회 초->...->9회 초->9회 말 순서로 진행된다.

출력
만약 울림 제미니스가 역전패를 했다면 'Yes'를 출력한다.

그렇지 않으면 'No'를 출력한다.
*/
