import sys

def power(a, b):
    if b == 1:
        return a % C
    
    tmp = power(a, b//2)
    if b % 2 == 0:
        return tmp * tmp % C
    else:
        return tmp * tmp * a % C

A, B, C = map(int, input().split())
answer = power(A, B)
print(answer)

'''
1629. 곱셈
https://www.acmicpc.net/problem/1629

문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

짝수, 홀수 파악
원래: A ^ B
짝수)
(A ^ (B/2))^2
홀수)
(A ^ (B/2))^2 * A
'''