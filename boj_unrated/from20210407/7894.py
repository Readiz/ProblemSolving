import math

t = int(input())

for tc in range(0, t):
    n = int(input())
    if n == 1:
        print(1)
    else:
        logFactorial = 0
        for i in range(1, n + 1):
            logFactorial += math.log10(i)
        print(math.ceil(logFactorial))


# 팩토리얼의 자리수 구하기
# 감마 함수 활용 가능

# from math import *
# for i in range(int(input())):n=int(input());print([1,ceil(lgamma(n+1)/log(10))][n>1])

# 또는 스털링 근사 활용 가능 (100 이상에서 대략 성립)
# https://ko.wikipedia.org/wiki/%EC%8A%A4%ED%84%B8%EB%A7%81_%EA%B7%BC%EC%82%AC