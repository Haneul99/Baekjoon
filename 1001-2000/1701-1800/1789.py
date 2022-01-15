# -*- coding: utf-8 -*-
n = int(input())
sum = 0
cnt = 0
for i in range(1,n):
    sum = i*(i+1)/2
    if sum > n: break
    if sum <= n:
        cnt = i
    

print(cnt)
    


'''
1789. 수들의 합
https://www.acmicpc.net/problem/1789

문제
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?

입력
첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.

출력
첫째 줄에 자연수 N의 최댓값을 출력한다.
1~n까지의 합
: n(n+1)/2
'''