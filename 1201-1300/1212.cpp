#include <stdio.h>
#include <string.h>

int main(void) {
	char oct[333335];
	char bin[4];
	scanf("%s", oct);

	int len = 3 * strlen(oct);
	bin[3] = '\0';
	if (oct[0] == '0') printf("0");//0입력시 0출력
	else {
		for (int i = 0; i < len; i++) {
			bin[(len - i + 2) % 3] = (oct[i / 3] - 48) % 2 + 48;//2,1,0 순서로 저장, i번째 oct에 대해 세 번 연산함. int로 연산하고 char로 다시 바꿔주는 작업
			oct[i / 3] = (oct[i / 3] - 48) / 2 + 48;

			if (i % 3 == 2) {//bin이 꽉 찼을 때
				for (int j = 0; j < 3; j++) {
					if (i == 2 && j == 0 && bin[j] == '0');//0xx인 경우
					else if (i == 2 && bin[0] == '0' && bin[1] == '0') {
						printf("%c", bin[2]);
						break;
					}//00x인 경우 세번째 출력하고 break
					else {
						printf("%c", bin[j]);
					}//일반적인 경우
				}
			}
		}
	}
}

//A : 65 ~ Z : 90
//0 : 48

/*
1212. 8진수 2진수
https://www.acmicpc.net/problem/1212

문제
8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

입력
첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.

출력
첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

*/