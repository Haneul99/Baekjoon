#include <stdio.h>

typedef struct n {
	int x;
	int y;
}q;

q queue[1000000];
int front = 0;
int rear = 0;

int map[1011][1011];
int visit[1001][1001];
int cnt;
int sizeX, sizeY;

void insert(int _x, int _y)
{
	queue[rear].x = _x;
	queue[rear].y = _y;
	rear = rear + 1;
}

q pop()
{
	q temp;
	temp.x = queue[front].x;
	temp.y = queue[front].y;
	front++;
	return temp;
}

int isEmpty() {
	if (rear == front)
		return 0;
	else
		return 1;
}

int m, n, i, j;
int vectX[4] = { 1,-1,0,0 };//동서남북 
int vectY[4] = { 0,0,-1,1 };//동서남북 
//X,Y 좌표 이동을 위한 X,Y vertor 배열

int bfs() {
	int y, x;
	int nextX;
	int nextY;
	while (isEmpty()) {
		q temp = pop();//1인 토마토
		x = temp.x;
		y = temp.y;

		for (i = 0; i < 4; i++) {
			nextX = x + vectX[i];
			nextY = y + vectY[i];
			if (nextX >= 0 && nextX < sizeX && nextY >= 0 && nextY < sizeY) {//적정 범위 내의 좌표인지 체크
				if (map[nextX][nextY] == 0) {
					map[nextX][nextY] = map[x][y] + 1;//map[x][y]는 1인 토마토이고, day를 측정해야 하기 때문에 +1을 함. day3에 바뀐 토마토가 바꾸는 토마토는 day4에 바뀌는 것이기 때문.
					insert(nextX, nextY);//다시 큐에 삽입
					cnt--;//0인 토마토의 개수
				}
			}
		}
	}
	if (cnt == 0)
		return map[x][y] - 1;//첫째날에 바뀐 토마토도 1+1이라 2의 값을 가지고 있으므로 -1을 해줘야 며칠이 걸렸는지를 표시하는 것.
	return -1;
}
int main() {
	scanf("%d %d", &sizeY, &sizeX);
	for (i = 0; i < sizeX; i++) {
		for (j = 0; j < sizeY; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				cnt++; //바뀌어야 하는 토마토의 개수
			else if (map[i][j] == 1)
				insert(i, j);//1인 토마토는 큐에 insert
		}
	}

	printf("%d", bfs());
}


/*
int arr[1002][1002] = { 0, };
int next[1002][1002] = { 0, };
int w, h;
int count = 0;

int DFS() {
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= w; j++)
			next[i][j] = arr[i][j];
	}
	int flag = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if ((arr[i - 1][j] == 1 || arr[i + 1][j] == 1 || arr[i][j + 1] == 1 || arr[i][j - 1] == 1) && arr[i][j] == 0){
				next[i][j] = 1;
				flag = 1;
			}
		}
	}
	return flag;
}

int main()
{
	scanf("%d%d", &w, &h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int check = 1;
	while (1) {
		check = DFS();
		if (check == 1) {
			for (int i = 0; i <= h; i++) {
				for (int j = 0; j <= w; j++)
					arr[i][j] = next[i][j];
			}
			count++;
		}
		else break;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++)
			if (arr[i][j] == 0) count = -1;
	}
	

	printf("%d\n", count);
}

답은 정확하게 나올 것 같지만 time limit
*/

/*
7576. 토마토
https://www.acmicpc.net/problem/7576

문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 



창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 

출력
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

*/