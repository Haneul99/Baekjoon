# -*- coding: utf-8 -*-

import sys

str = sys.stdin.readline().rstrip()
words = list(str.split())
space = int(sys.stdin.readline())
alphabets = list(map(int, sys.stdin.readline().split()))
need_alphabets = [0] * 26

title = ""
last_used = ''
for word in words:
    c = word.upper()[0]
    title += c
    if last_used != c:
        need_alphabets[ord(c) - ord('A')] += 1
       

last_used = ''
for word in words:
    last_used = ''
    for c in word:
        if last_used == c: continue
        if ord('a') <= ord(c) <= ord('z'):
            need_alphabets[ord(c) - ord('a')] += 1
        elif ord('A') <= ord(c) <= ord('Z'):
            need_alphabets[ord(c) - ord('A')] += 1
        last_used = c
  
isPossible = True  
  
if len(words) - 1 > space:
    isPossible = False
else:
    for i in range(26):
        if need_alphabets[i] > alphabets[i]: 
            isPossible = False
            break
    
if isPossible: print(title)
else: print("-1")


'''
19948. 음유시인 영재
https://www.acmicpc.net/problem/19948

문제
감수성이 뛰어난 음유시인 영재는 일상생활 중에 번뜩 시상이 떠오르곤 한다.

하지만 기억력이 좋지 못한 영재는 시상이 떠오르면 그 순간 컴퓨터로 기록해야만 안 까먹는다! 시는 대문자, 소문자 알파벳과 빈칸으로 이루어져 있다. 시상은 매번 훌륭하지만 제목 짓는 센스가 부족한 영재는 시에 나오는 단어들의 첫 글자를 대문자로 바꾼 뒤 순서대로 이어서 제목으로 만든다. 만약 시의 내용이 'There is no cow level' 이라면 시의 제목은 'TINCL'이 된다.

시도 때도 없이 시를 기록하느라 낡아버린 영재의 키보드는 수명이 얼마 남지 않았다. 앞으로 스페이스 바와 영자판을 누를 수 있는 횟수가 정해져 있어 이를 초과하면 키보드가 수명이 다 하여 어떠한 작업도 하지 못하게 된다. 하나 다행인 점은, 키보드를 쓸 때 같은 문자가 연속으로 나오거나 빈칸이 연속으로 나오는 경우 영재는 자판을 꾹 눌러 한 번만 사용해서 키보드를 좀 더 효율적으로 쓸 수 있다. (A와 a는 다른 문자이므로 'Aa'는 2번의 a자판을 누른 것으로 한다.)

시의 내용과 시의 제목은 Enter 키로 구분된다. 다행히 Shift 키와 Enter 키는 항상 수명이 무한한 상황이다!

음유시인 영재가 이번에 지은 시의 내용과 스페이스 바와 영자판을 누를 수 있는 횟수가 주어졌을 때, 시의 내용과 제목을 모두 기록할 수 있다면 시의 제목을 출력하고, 만약 키보드의 수명이 다 하여 기록을 완벽하게 못 하게 된다면 -1을 출력하여라.

입력
첫 줄에 시의 내용이 주어진다.

둘째 줄에는 스페이스 바의 남은 사용 가능 횟수 주어진다.

셋째 줄에는 대소문자를 구별하지 않고, 26개의 알파벳에 대한 영자판의 남은 사용 가능 횟수가 알파벳순으로 주어진다.

출력
시의 내용과 제목을 모두 기록할 수 있다면 시의 제목을 출력하여라.

만약 키보드의 수명이 다 하여 기록을 완벽하게 못 하게 된다면 작업을 하지 못한다면 -1을 출력하여라.


제목과 내용을 모두 출력할 수 있는지 확인해야 함.
스페이스바는 들어온 단어 배열 length - 1 만큼 사용됨
대소문자로 배열 구분
아니다 for 문 돌면서, 같이 aa는 a 하나로 취급 그런식으로 해야 할 듯
대문자인 경우, 소문자인 경우 c - ord('A') / c - ord('a')
'''