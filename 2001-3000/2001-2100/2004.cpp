#include <stdio.h>

int countFive(int num) {
	int count = 0;
	for (long long int i = 5; num / i >= 1; i *= 5)
		count += num / i;
	return count;
}//5를 가지고 있는 수의 개수, 25를 가지고 있는 수의 개수 ...

int countTwo(int num) {
	int count = 0;
	for (long long int i = 2; num / i >= 1; i *= 2)
		count += num / i;
	return count;
}//2를 가지고 있는 수의 개수, 4를 가지고 있는 수의 개수 ...
/*
2의 배수, 4의 배수 이런식이기 때문에 4, 8, 16 ... -> num/4 가 되는 것
2의 배수를 할 때 8에서 2를 한 번 빼도, 2가 두 번 더 남았기 때문에 i=4, i=8일 때 한 번씩 더 빼주게 됨.
결과적으로 8이 가진 3개의 2를 i=2, i=4, i=8일 때 한 번씩 빼오게 되는 것.
*/

int main(void) {
	int n, m;
	scanf("%d%d", &n,&m);

	int count2 = countTwo(n);
	int count5 = countFive(n);

	if (m != 0) count2 -= countTwo(m);
	if (n != m) count2 -= countTwo(n - m);

	if (m != 0) count5 -= countFive(m);
	if (n != m) count5 -= countFive(n - m);

	if (count2 < 0 || count5 < 0) printf("0\n");
	if (count2 >= count5) printf("%d\n", count5);
	else printf("%d\n", count2);
}


/*
2004. 조합 0의 개수
https://www.acmicpc.net/problem/2004

문제
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤2,000,000,000, n!=0)이 들어온다.

출력
첫째 줄에 0의 개수를 출력한다.

*/