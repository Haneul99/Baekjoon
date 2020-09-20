#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000

int main() {
	int n;
	scanf("%d",&n);
	int arr[MAX_SIZE];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int dp[MAX_SIZE];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}
	//init

	int min;
	int max = 0;
	if (n == 1) max = 1;
	else {
		for (int i = 0; i < n; i++) {
			min = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i] && min<dp[j]) {
					min = dp[j];
				}
				//�ڽ�(i)���� ���� �͵��� ã�ư��� ����.
				//dp[j]�� ���� ������
			}
			dp[i] = min + 1;//min���� �ڽ��� �߰��ؼ� +1
			if (max < dp[i])
				max = dp[i];
		}
	}
	printf("%d\n", max);
}

/*
11053. ���� �� �����ϴ� �κ� ����
https://www.acmicpc.net/problem/11053

����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
*/