﻿#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

int getMax(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	vector<int> adj[1001];
	int indegree[1001] = { 0, };
	int result[1001] = { 0, };

	for (int i = 0; i < m; i++) {
		int pre, post;
		scanf("%d%d", &pre, &post);
		adj[pre].push_back(post);
		indegree[post]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
		result[i] = 1;
	}

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		int size = adj[p].size();
		for (int i = 0; i < size; i++) {
			int next = adj[p][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
				result[next] = getMax(result[next], result[p] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}


/*
14567. 선수과목 (Prerequisite)
https://www.acmicpc.net/problem/14567

문제
올해 Z대학 컴퓨터공학부에 새로 입학한 민욱이는 학부에 개설된 모든 전공과목을 듣고 졸업하려는 원대한 목표를 세웠다. 어떤 과목들은 선수과목이 있어 해당되는 모든 과목을 먼저 이수해야만 해당 과목을 이수할 수 있게 되어 있다. 공학인증을 포기할 수 없는 불쌍한 민욱이는 선수과목 조건을 반드시 지켜야만 한다. 민욱이는 선수과목 조건을 지킬 경우 각각의 전공과목을 언제 이수할 수 있는지 궁금해졌다. 계산을 편리하게 하기 위해 아래와 같이 조건을 간소화하여 계산하기로 하였다.

한 학기에 들을 수 있는 과목 수에는 제한이 없다.
모든 과목은 매 학기 항상 개설된다.
모든 과목에 대해 각 과목을 이수하려면 최소 몇 학기가 걸리는지 계산하는 프로그램을 작성하여라.

입력
첫 번째 줄에 과목의 수 N(1≤N≤1000)과 선수 조건의 수 M(0≤M≤500000)이 주어진다. 선수과목 조건은 M개의 줄에 걸쳐 한 줄에 정수 A B 형태로 주어진다. A번 과목이 B번 과목의 선수과목이다. A<B인 입력만 주어진다. (1≤A<B≤N)

출력
1번 과목부터 N번 과목까지 차례대로 최소 몇 학기에 이수할 수 있는지를 한 줄에 공백으로 구분하여 출력한다.
*/