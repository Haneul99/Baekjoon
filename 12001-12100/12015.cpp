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
15685. 
https://www.acmicpc.net/problem/15685

9
10 20 10 30 20 50 15 25 17

실제로 길이가 증가하는 것은 마지막 원소보다 큰 경우이다.
그렇기 때문에, lower_bound를 통해 배열의 값을 바꾸면 선택된 가장 긴 증가하는 부분 수열의 원소로 구성되지 않지만
배열을 증가하는 배열의 최솟값으로 구성할 수 있으므로 배열의 마지막 값도 가능한 최솟값으로 구성할 수 있다.

그렇기 때문에 inc_arr을 출력했을 때 정답 배열과 일치하지 않지만 배열의 size는 가장 긴 증가하는 부분 수열의 크기와 같다.
*/