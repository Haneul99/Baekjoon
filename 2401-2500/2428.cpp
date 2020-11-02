#include<stdio.h>
#include<algorithm>

using namespace std;

int fileSize[100010];
long long cnt = 0;
int n;

int getDistance(int start, int left, int right) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (fileSize[mid] * 0.9 <= fileSize[start])
			left = mid + 1;
		else
			right = mid;
	}
	return right-1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &fileSize[i]);
	sort(fileSize, fileSize + n);
	fileSize[n] = 100000001;
	
	for (int i = 0; i < n-1; i++) {
		int dis = getDistance(i, i, n) - i;
		cnt += dis;
	}
	printf("%lld\n", cnt);
}


/*
2428. 표절
https://www.acmicpc.net/problem/2428

문제
세계적인 석유 재벌 "규현 조 압둘 티크리티 안드레스 후세인 리오넬 솔레르 살라 마리우 두스 산투스 펠리스 빈 자이드 술탄 친나왓 뱅거 7세"는 1등 상품으로 페라리를 걸고 프로그래밍 대회를 개최했다. 이 대회의 참석자는 총 N명이고 각각 솔루션 파일 1개를 제출했다. 이 솔루션 파일을 F1, F2, ..., Fn이라고 한다.

채점 결과를 발표하기 전에, 남의 것을 배낀 사람이 있는지 찾아내려고 한다. 이 대회의 주최측은 두 파일을 비교해서 너무 비슷한지 아닌지 판별하는 프로그램이 있다.

하지만, 제출한 파일의 개수가 너무 많아서, 모든 쌍을 검사한다면, 2012년 지구가 멸망할 때 까지도 검사를 해야할 판이다. 따라서, 파일 크기가 너무 다른 경우에는 그러한 쌍을 검사하지 않고 넘어가기로 했다.

좀더 정확하게 하기 위해서, 대회의 심판들은 두 파일이 있을 때, 작은 파일의 크기가 큰 파일 크기의 90%보다도 작을 때는, 이러한 쌍은 검사하지 않고 넘어가기로 했다. 따라서, (Fi, Fj) 쌍을 검사해야 하는데, 이때, i≠j이고, size(Fi) ≤ size(Fj)이면서, size(Fi) ≥ 0.9 × size(Fj)인 쌍만 검사하려고 한다.

몇 개의 쌍을 검사해야 하는 지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 제출한 솔루션의 개수 N이 주어진다. 둘째 줄에는 각 솔루션 파일의 크기 size(F1), size(F2), ..., size(FN)이 주어진다. (1<=N<=100,000, 1<=size(Fi)<=100,000,000)

출력
첫째 줄에 검사해야 하는 파일의 개수를 출력한다.

*/