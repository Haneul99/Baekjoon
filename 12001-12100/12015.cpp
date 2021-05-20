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
	inc_arr.push_back(0); // arr�� �ּڰ��� 1�̹Ƿ�, 0�� �̸� �־��.

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

������ ���̰� �����ϴ� ���� ������ ���Һ��� ū ����̴�.
�׷��� ������, lower_bound�� ���� �迭�� ���� �ٲٸ� ���õ� ���� �� �����ϴ� �κ� ������ ���ҷ� �������� ������
�迭�� �����ϴ� �迭�� �ּڰ����� ������ �� �����Ƿ� �迭�� ������ ���� ������ �ּڰ����� ������ �� �ִ�.

�׷��� ������ inc_arr�� ������� �� ���� �迭�� ��ġ���� ������ �迭�� size�� ���� �� �����ϴ� �κ� ������ ũ��� ����.
*/