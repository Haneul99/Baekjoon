a, b = map(int, input().split(' '))

def prime_list(a, b):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    sieve = [True] * (b+1)

    # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    m = int(b ** 0.5)
    for i in range(2, m + 1):
        if sieve[i] == True:           # i가 소수인 경우
            for j in range(i+i, n, i): # i이후 i의 배수들을 False 판정
                sieve[j] = False

    # 소수 목록 산출
    return [i for i in range(a, b+1) if sieve[i] == True]


'''
A <= num <= B 중에서, 소수의 제곱인 num

문제
어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 그 수를 거의 소수라고 한다.

A와 B가 주어지면, A보다 크거나 같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다.

입력
첫째 줄에 왼쪽 범위 A와 오른쪽 범위 B가 공백 한 칸을 사이에 두고 주어진다. A의 범위는 10^14보다 작거나 같은 자연수이고, B는 A보다 크거나 같고, 10^14보다 작거나 같은 자연수이다.

출력
첫째 줄에 총 몇 개가 있는지 출력한다.

'''