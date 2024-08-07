n = int(input())
expression = ''
while True:
    try:
        expression += input()
    except EOFError:
        break

expression = expression.replace('/', '//')
print((eval(expression)))

# 큰 수 계산 분류
# 시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
# 2 초	128 MB	491	160	112	34.675%
# 문제
# 어떤 임의의 수식이 입력으로 들어올때 수식을 계산하는 프로그램을 짜시오. 단 수 하나하나의 크기는 -10100 이상 10100이하 이다. 단, 수식에 괄호는 없다고 가정한다.

# 소수점이 나올 경우, 소수점은 내린다. 참고로, -5/2 = -3이고, 5/-2도 -3이다. -5/-2는 2이다.

# 입력
# 수의 개수 N(1 ≤ N ≤ 10) 이 주어지고 다음 2＊N - 1 줄에는 수와 연산자(+, -, *, /) 가 번갈아서 들어온다.

# 출력
# 한 줄에 계산이 끝난 후 수를 출력한다.

# 예제 입력 1 
# 4
# 2
# *
# 3
# +
# 1
# *
# 4
# 예제 출력 1 
# 10
