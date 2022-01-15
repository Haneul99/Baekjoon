#include<stdio.h>
#include<vector>
#include<algorithm>


using namespace std;


int n;
vector<int> arr;
vector<int> inc_arr;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr.push_back(x);
	}
	inc_arr.push_back(0); // arr의 최솟값이 1이므로, 0을 미리 넣어둠.

	int left = 0;
	int right = 0;
	int mid = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > inc_arr.back()) {
			inc_arr.push_back(arr[i]);
		}
		else {
			left = 0;
			right = inc_arr.size();
			while (left < right) {
				mid = (left + right) / 2;

				if (inc_arr[mid] < arr[i])
					left = mid + 1;
				else
					right = mid;
			}
			inc_arr[right] = arr[i];
		}
	}
	printf("%d\n", inc_arr.size() - 1);
}


/*
12015. 가장 긴 증가하는 부분 수열 2
https://www.acmicpc.net/problem/12015

문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

실제로 길이가 증가하는 것은 마지막 원소보다 큰 경우이다.
그렇기 때문에, lower_bound를 통해 배열의 값을 바꾸면 선택된 가장 긴 증가하는 부분 수열의 원소로 구성되지 않지만
배열을 증가하는 배열의 최솟값으로 구성할 수 있으므로 배열의 마지막 값도 가능한 최솟값으로 구성할 수 있다.

그렇기 때문에 inc_arr을 출력했을 때 정답 배열과 일치하지 않지만 배열의 size는 가장 긴 증가하는 부분 수열의 크기와 같다.



#include<stdio.h>
#include<vector>
#include<algorithm>


using namespace std;


int n;
vector<int> arr;
vector<int> inc_arr;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr.push_back(x);
	}
	inc_arr.push_back(0); // arr의 최솟값이 1이므로, 0을 미리 넣어둠.

	for (int i = 0; i < n; i++) {
		if (arr[i] > inc_arr.back()) {
			//벡터의 가장 마지막 값보다 크다면(증가하는 순서) push
			inc_arr.push_back(arr[i]);
		}
		else {
			//arr[i] 이상의 값이 처음으로 나타나는 위치에 arr[i]를 넣는다. (더 낮은 값으로 배열 값을 바꿔줌)
			int index = lower_bound(inc_arr.begin(), inc_arr.end(), arr[i]) - inc_arr.begin();
			inc_arr[index] = arr[i];
			printf("arr[%d]: %d, idx: %d\n", i, arr[i], index);
		}
	}
	printf("%d\n", inc_arr.size() - 1);
}

*/