#include<stdio.h>
#include<map>

using namespace std;

long long n, p, q;
map<long long, long long > m;//idx, value

long long recur(long long num) {
	if (m.count(num) > 0) {
		return m[num];
	}
	else return m[num] = recur(num / p) + recur(num / q);
}


int main() {
	scanf("%lld%lld%lld", &n, &p, &q);
	m[0] = 1;
	printf("%lld\n", recur(n));
}



                                                 
/*
1351.
https://www.acmicpc.net/problem/1351



*/                      