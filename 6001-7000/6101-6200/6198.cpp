#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#include<stack>
#define MAX 200010

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	long long ans = 0;

	stack<int> stk;
	for (int i = 0; i < N; i++) {
		int h; cin >> h;
		if (!stk.empty() && stk.top() <= h) {
			while (stk.top() <= h) {
				stk.pop();
				if (stk.empty()) break;
			}

		}			
		ans += stk.size();
		stk.push(h);
	}
	cout << ans << '\n';
}


/*
6198. 옥상 정원 꾸미기
https://www.acmicpc.net/problem/6198

문제
sook-001(1).jpg

도시에는 N개의 빌딩이 있다.

빌딩 관리인들은 매우 성실 하기 때문에, 다른 빌딩의 옥상 정원을 벤치마킹 하고 싶어한다.

i번째 빌딩의 키가 hi이고, 모든 빌딩은 일렬로 서 있고 오른쪽으로만 볼 수 있다.

i번째 빌딩 관리인이 볼 수 있는 다른 빌딩의 옥상 정원은 i+1, i+2, .... , N이다.

그런데 자신이 위치한 빌딩보다 높거나 같은 빌딩이 있으면 그 다음에 있는 모든 빌딩의 옥상은 보지 못한다.

예) N=6, H = {10, 3, 7, 4, 12, 2}인 경우

			 =
 =           =
 =     -     =
 =     =     =        -> 관리인이 보는 방향
 =  -  =  =  =
 =  =  =  =  =  =
10  3  7  4  12 2     -> 빌딩의 높이
[1][2][3][4][5][6]    -> 빌딩의 번호
1번 관리인은 2, 3, 4번 빌딩의 옥상을 확인할 수 있다.
2번 관리인은 다른 빌딩의 옥상을 확인할 수 없다.
3번 관리인은 4번 빌딩의 옥상을 확인할 수 있다.
4번 관리인은 다른 빌딩의 옥상을 확인할 수 없다.
5번 관리인은 6번 빌딩의 옥상을 확인할 수 있다.
6번 관리인은 마지막이므로 다른 빌딩의 옥상을 확인할 수 없다.
따라서, 관리인들이 옥상정원을 확인할 수 있는 총 수는 3 + 0 + 1 + 0 + 1 + 0 = 5이다.

입력
첫 번째 줄에 빌딩의 개수 N이 입력된다.(1 ≤ N ≤ 80,000)
두 번째 줄 부터 N+1번째 줄까지 각 빌딩의 높이가 hi 입력된다. (1 ≤ hi ≤ 1,000,000,000)
출력
각 관리인들이 벤치마킹이 가능한 빌딩의 수의 합을 출력한다.

stack인듯
stack의 top보다 새로 들어오는게 작으면 stack의 size만큼 더하고 push
새로 들어오는게 크면 stack의 top보다 작거나 empty가 될 때까지 pop하고 stack의 size만큼 더하고 push
*/ 