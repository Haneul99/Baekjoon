﻿#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int power[11][11];
int ans = 0;

void backtracking(int num, int pos, int powerSum, bool visit[11]) {
	if (power[num][pos] == 0) return;
	if (num == 10) {
		ans = powerSum > ans ? powerSum : ans;
	}
	for (int i = 0; i < 11; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			backtracking(num + 1, i, powerSum + power[num + 1][i], visit);
			visit[i] = false;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		memset(power, 0, sizeof(power));
		ans = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				scanf("%d", &power[i][j]);
			}
		}
		bool visit[11] = { 0, };
		for (int i = 0; i < 11; i++) {
			visit[i] = true;
			backtracking(0, i, power[0][i], visit);
			visit[i] = false;
		}
		printf("%d\n", ans);
	}
}

/*
3980. 선발 명단
https://www.acmicpc.net/problem/3980

문제
챔피언스 리그 결승전을 앞두고 있는 맨체스터 유나이티드의 명장 퍼거슨 감독은 이번 경기에 4-4-2 다이아몬드 전술을 사용하려고 한다.

오늘 결승전에 뛸 선발 선수 11명은 미리 골라두었지만, 어떤 선수를 어느 포지션에 배치해야 할지 아직 결정하지 못했다.

수석코치 마이크 펠란은 11명의 선수가 각각의 포지션에서의 능력을 0부터 100까지의 정수로 수치화 했다. 0은 그 선수가 그 포지션에 적합하지 않다는 뜻이다.

이때, 모든 선수의 포지션을 정하는 프로그램을 작성하시오. 모든 포지션에 선수를 배치해야 하고, 각 선수는 능력치가 0인 포지션에 배치될 수 없다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 첫째 줄에는 테스트 케이스의 개수 C가 주어진다. 각각의 케이스는 11줄로 이루어져 있고, i번 줄은 0과 100사이의 11개의 정수 sij를 포함하고 있다. sij는 i번선수가 j번 포지션에서 뛸 때의 능력이다. 모든 선수에게 적합한 포지션의 수는 최대 5개이다. (능력치가 0보다 크다)

출력
각각의 테스트 케이스에 대해서, 모든 포지션의 선수를 채웠을 때, 능력치의 합의 최댓값을 한 줄에 하나씩 출력한다. 항상 하나 이상의 올바른 라인업을 만들 수 있다.
*/