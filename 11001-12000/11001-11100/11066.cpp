#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<limits.h>
#include<queue>
#include<memory.h>
#define MAX 510

using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int K;
		int fileSize[MAX] = { 0, }, sum[MAX] = { 0, };
		int dp[MAX][MAX] = { 0, };

		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> fileSize[i];
			sum[i] = sum[i - 1] + fileSize[i];
		}
		for (int sectionSize = 1; sectionSize < K; sectionSize++) {
			for (int start = 1; start + sectionSize <= K; start++) {
				int end = start + sectionSize;
				dp[start][end] = 1234567890;
				for (int k = start; k < end; k++) {
					dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + sum[end] - sum[start - 1]);//[start:k][k+1:end]에 start부터 end까지의 구간합을 더한 값 중 최솟값을 찾기
				}
			}
		}
		cout << dp[1][K] << '\n';
	}
}


/*
11066. 파일 합치기
https://www.acmicpc.net/problem/11066

문제
소설가인 김대전은 소설을 여러 장(chapter)으로 나누어 쓰는데, 각 장은 각각 다른 파일에 저장하곤 한다. 소설의 모든 장을 쓰고 나서는 각 장이 쓰여진 파일을 합쳐서 최종적으로 소설의 완성본이 들어있는 한 개의 파일을 만든다. 이 과정에서 두 개의 파일을 합쳐서 하나의 임시파일을 만들고, 이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속이 되도록 파일을 합쳐나가고, 최종적으로는 하나의 파일로 합친다. 두 개의 파일을 합칠 때 필요한 비용(시간 등)이 두 파일 크기의 합이라고 가정할 때, 최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합을 계산하시오.

예를 들어, C1, C2, C3, C4가 연속적인 네 개의 장을 수록하고 있는 파일이고, 파일 크기가 각각 40, 30, 30, 50 이라고 하자. 이 파일들을 합치는 과정에서, 먼저 C2와 C3를 합쳐서 임시파일 X1을 만든다. 이때 비용 60이 필요하다. 그 다음으로 C1과 X1을 합쳐 임시파일 X2를 만들면 비용 100이 필요하다. 최종적으로 X2와 C4를 합쳐 최종파일을 만들면 비용 150이 필요하다. 따라서, 최종의 한 파일을 만드는데 필요한 비용의 합은 60+100+150=310 이다. 다른 방법으로 파일을 합치면 비용을 줄일 수 있다. 먼저 C1과 C2를 합쳐 임시파일 Y1을 만들고, C3와 C4를 합쳐 임시파일 Y2를 만들고, 최종적으로 Y1과 Y2를 합쳐 최종파일을 만들 수 있다. 이때 필요한 총 비용은 70+80+150=300 이다.

소설의 각 장들이 수록되어 있는 파일의 크기가 주어졌을 때, 이 파일들을 하나의 파일로 합칠 때 필요한 최소비용을 계산하는 프로그램을 작성하시오.

입력
프로그램은 표준 입력에서 입력 데이터를 받는다. 프로그램의 입력은 T개의 테스트 데이터로 이루어져 있는데, T는 입력의 맨 첫 줄에 주어진다.각 테스트 데이터는 두 개의 행으로 주어지는데, 첫 행에는 소설을 구성하는 장의 수를 나타내는 양의 정수 K (3 ≤ K ≤ 500)가 주어진다. 두 번째 행에는 1장부터 K장까지 수록한 파일의 크기를 나타내는 양의 정수 K개가 주어진다. 파일의 크기는 10,000을 초과하지 않는다.

출력
프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 한 행에 출력하는데, 모든 장을 합치는데 필요한 최소비용을 출력한다.

size 1   : [1-2] [2-3] ...
size 2   : [1-3] [2-4] ...
size 3   : [1-4] [2-5] ...
size k-1 : [1-K] 
어디서 자르면 최솟값이 될 지 옮겨가며 최솟값을 찾기

구간합을 구해나가고,
1:K까지 갈 때, 마지막으로 합칠 파일이 [1:2][3:K] 또는 [1:3][4:K] 또는  ... 이런식으로, 어떤 합이 가장 작은지를 찾는 것. 이렇게 합칠 때 결국 비용은 결국 구간합만큼 늘어나기 때문에 또 더해줌.
*/ 