#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<math.h>
#define MAX 200010

using namespace std;


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, k, ans = 1844674407370955161;
	scanf("%lld%lld", &n, &k);
	long long Vs[MAX] = { 0, };
	for (int i = 0; i < n; i++) {
		scanf("%lld", &Vs[i]);
	}
	sort(Vs, Vs + n);

	for (int i = 1; i < n; i++) {
		long long v1 = Vs[0] * i;
		long long v2 = Vs[i] * (n - i);
		long long v = v1 + v2;	
		long long minute = k / v;
		if (k%v != 0) minute += 1;
		ans = min(ans, minute);
	}

	printf("%lld\n", ans);
}


/*
22981. 휴먼 파이프라인
https://www.acmicpc.net/problem/22981

문제
오늘은 중요한 날이다. SUAPC가 있는 날이기 때문이다.

이렇게 중요한 날이지만 안타깝게도 일을 해야 한다. 오늘 해야 할 일은 상자 $K$개를 적절한 곳으로 옮겨야 하는 일이다.

상자 $K$개는 너무 많아서 아무래도 혼자서 전부 나를 수는 없기 때문에, $N$명의 SUAPC 참가자들이 상자를 나르기 위해 모여 있다. $N$명 모두가 일을 최대한 빠르게 마치고 SUAPC에 참가하고 싶어한다.

참가자들은 두 팀으로 나눠져서 작업을 진행하기로 했다. 두 팀이 같은 수의 상자를 옮길 필요는 없다. 두 팀 모두 적어도 한 명은 포함되어야 한다. 각 사람의 분당 작업 속도는 $v_i$며 팀의 작업 속도는

 $($해당 팀에 속한 사람들의 작업 속도 중 가장 느린 작업 속도$)\times($팀에 속한 사람의 수$)$ 

이다. 상자 $K$개를 옮기는 팀의 분당 작업 속도가 $v$일 때, 팀이 작업을 마치는 데에는

$\left\lceil \frac{K}{v} \right\rceil$분이 걸린다.

모두가 행복하게 SUAPC에 참가할 수 있게, 모든 상자를 최대한 빠르게 옮길 수 있도록 $N$명을 적절히 두 팀으로 나누어 두 팀이 동시에 상자를 옮기기 시작했을 때 제일 빨리 끝나는 경우의 시간을 구하자.

입력
다음과 같이 입력이 주어진다.

 $N$  $K$ 
$v_1$ $v_2$ $\cdots$ $v_N$ 
 $N$은 모인 사람의 수다. ($2 \le N \le 200\,000$)
 $K$는 옮겨야 하는 상자의 개수이다. ($1 \le K \le 10^{18}$)
 $v_i$는 $i$번째 사람의 분당 작업 속도이며, 1분에 상자 $v_i$개를 옮길 수 있다는 뜻이다. ($1 \le v_i \le 10^9$)
입력으로 주어지는 모든 수는 정수다.
출력
모든 상자를 최대한 빠르게 옮기는 경우의 작업 시간을 분 단위로 출력한다.
*/