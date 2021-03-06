#include<stdio.h>
#include<vector>

using namespace std;


vector<int> gear[5];//톱니바퀴 4개
int k;


void rotate(int gnum, int d) {
	if (d == 1) {
		int last = gear[gnum].back();
		gear[gnum].pop_back();
		gear[gnum].insert(gear[gnum].begin(), last);
	}
	else {
		int first = gear[gnum][0];
		gear[gnum].erase(gear[gnum].begin());
		gear[gnum].push_back(first);
	}
	//1  시계방향 : 마지막 원소 뽑아서 맨 앞으로 넣어주기
	//-1 반시계방향 : 첫번째 원소 마지막으로 넣어주기
}


int main() {
	for (int i = 1; i <= 4; i++) {
		char g[9];
		scanf("%s", &g);
		for (int j = 0; j < 8; j++) {
			gear[i].push_back(g[j] - '0');
		}
	}

	scanf("%d", &k);

	while (k--) {
		int gear_num, dir;
		scanf("%d%d", &gear_num, &dir);//1은 시계, -1은 반시계

		int dir_info[4] = { 0, };//12, 23, 34 톱니바퀴의 다름 여부. 다르면 1
		int rot_info[5] = { 0, };//각 톱니바퀴가 어떤 방향으로 회전했는지.

		//현재 상태를 보고 회전을 결정
		for (int i = 1; i < 4; i++) {
			if (gear[i][2] == gear[i + 1][6]) {
				dir_info[i] = 0;
			}//같으면 회전하지 않음
			else dir_info[i] = 1;
		}//12, 23, 34 의 2번 6번

		rotate(gear_num, dir);
		rot_info[gear_num] = dir;

		for (int i = gear_num + 1; i <= 4; i++) {
			if (dir_info[i - 1] && (rot_info[i - 1] == 1 || rot_info[i - 1] == -1)) {
				if (rot_info[i - 1] == 1) {
					rotate(i, -1);
					rot_info[i] = -1;
				}
				else {
					rotate(i, 1);
					rot_info[i] = 1;
				}
			}//ex. 3번을 회전시키고 싶으면 23의 회전 방향을 봐야함
			else rot_info[i] = 0;
		}//1234번 톱니바퀴
		for (int i = gear_num - 1; i > 0; i--) {
			if (dir_info[i] && (rot_info[i + 1] == 1 || rot_info[i + 1] == -1)) {
				if (rot_info[i + 1] == 1) {
					rotate(i, -1);
					rot_info[i] = -1;
				}
				else {
					rotate(i, 1);
					rot_info[i] = 1;
				}
			}
			else rot_info[i] = 0;
		}//4321번 톱니바퀴, 1번은 2번이 회전해야 회전가능. 2번은 3번이 회전해야 회전가능, 3번은 4번이 회전해야 회전가능 4번은 3번이 회전해야 회전가능

		/*
		우선 gear_num에 해당하는 톱니바퀴를 바꿔준다. -> rotate 함수를 작성해주기.
		다음 오른쪽에 있는 톱니부터 순서대로. 2번을 바꿨으면 3번4번1번순서, 3번을 바꿨으면 4번2번1번
		판단 후 같으면 회전 X, 다르면 반대 방향으로 회전
		*/
	}
	int ans = 0;
	if (gear[1][0] == 1) ans += 1;
	if (gear[2][0] == 1) ans += 2;
	if (gear[3][0] == 1) ans += 4;
	if (gear[4][0] == 1) ans += 8;

	printf("%d\n", ans);
}



/*
14891. 톱니바퀴
https://www.acmicpc.net/problem/14891

문제
총 8개의 톱니를 가지고 있는 톱니바퀴 4개가 아래 그림과 같이 일렬로 놓여져 있다. 또, 톱니는 N극 또는 S극 중 하나를 나타내고 있다. 톱니바퀴에는 번호가 매겨져 있는데, 가장 왼쪽 톱니바퀴가 1번, 그 오른쪽은 2번, 그 오른쪽은 3번, 가장 오른쪽 톱니바퀴는 4번이다.



이때, 톱니바퀴를 총 K번 회전시키려고 한다. 톱니바퀴의 회전은 한 칸을 기준으로 한다. 회전은 시계 방향과 반시계 방향이 있고, 아래 그림과 같이 회전한다.





톱니바퀴를 회전시키려면, 회전시킬 톱니바퀴와 회전시킬 방향을 결정해야 한다. 톱니바퀴가 회전할 때, 서로 맞닿은 극에 따라서 옆에 있는 톱니바퀴를 회전시킬 수도 있고, 회전시키지 않을 수도 있다. 톱니바퀴 A를 회전할 때, 그 옆에 있는 톱니바퀴 B와 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전하게 된다. 예를 들어, 아래와 같은 경우를 살펴보자.



두 톱니바퀴의 맞닿은 부분은 초록색 점선으로 묶여있는 부분이다. 여기서, 3번 톱니바퀴를 반시계 방향으로 회전했다면, 4번 톱니바퀴는 시계 방향으로 회전하게 된다. 2번 톱니바퀴는 맞닿은 부분이 S극으로 서로 같기 때문에, 회전하지 않게 되고, 1번 톱니바퀴는 2번이 회전하지 않았기 때문에, 회전하지 않게 된다. 따라서, 아래 그림과 같은 모양을 만들게 된다.



위와 같은 상태에서 1번 톱니바퀴를 시계 방향으로 회전시키면, 2번 톱니바퀴가 반시계 방향으로 회전하게 되고, 2번이 회전하기 때문에, 3번도 동시에 시계 방향으로 회전하게 된다. 4번은 3번이 회전하지만, 맞닿은 극이 같기 때문에 회전하지 않는다. 따라서, 아래와 같은 상태가 된다.



톱니바퀴의 초기 상태와 톱니바퀴를 회전시킨 방법이 주어졌을 때, 최종 톱니바퀴의 상태를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 1번 톱니바퀴의 상태, 둘째 줄에 2번 톱니바퀴의 상태, 셋째 줄에 3번 톱니바퀴의 상태, 넷째 줄에 4번 톱니바퀴의 상태가 주어진다. 상태는 8개의 정수로 이루어져 있고, 12시방향부터 시계방향 순서대로 주어진다. N극은 0, S극은 1로 나타나있다.

다섯째 줄에는 회전 횟수 K(1 ≤ K ≤ 100)가 주어진다. 다음 K개 줄에는 회전시킨 방법이 순서대로 주어진다. 각 방법은 두 개의 정수로 이루어져 있고, 첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향이다. 방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.

출력
총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력한다. 점수란 다음과 같이 계산한다.

1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점

*/