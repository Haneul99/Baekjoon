#include<stdio.h>
#include<queue>

using namespace std;

typedef struct pizza {
	int slice;
	int idx;
	int order;
}pizza;

int main() {
	int n;
	scanf("%d", &n);
	int pi[1001];
	int ans[1001] = { 0, };
	queue<pizza> queue;
	for (int i = 0; i < n; i++) {
		scanf("%d", &pi[i]);
		pizza p;
		p.idx = i;
		p.slice = pi[i];
		queue.push(p);
	}
	int ord = 1;
	while (!queue.empty()) {
		pizza p = queue.front();
		queue.pop();
		p.slice--;
		if (p.slice == 0) {
			ans[p.idx] = ord;
		}
		else {
			queue.push(p);
		}
		ord++;
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}

/*
15235. Olympiad Pizza
https://www.acmicpc.net/problem/15235

문제
During the Olympiad finals we usually serve pizza for the contestants. When the food arrives, the contestants to queue to get some pizza. Each student will be given a single slice of pizza when his/her turn arrives. The problem is that some people need more than one slice of pizza to be well fed so they need to queue again for more pizza after they get the first one.

Given a list of slices needed to fed each of the contestants, compute how long it will take to fed all of them. We can give a slice of pizza every second and when a contestant is well fed he does not return to the queue.

입력
The first line will contain an integer N. The number of contestants.

The second line will contain N integers separated by spaces. The number of slices of pizza needed to feed each contestant.

N <= 1000

The numbers in the sequence will be between 1 and 1000.

Each contestant will need at least 1 and at most 100 slices of pizza.

출력
A line containing N integers separated by spaces. The time in which each of the contestant get all the slices he/she needs.

*/                      