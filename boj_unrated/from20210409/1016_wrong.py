min, max = map(int, input().split())

count = max - min + 1
n = 1
while n * n <= max:
    if n * n >= min:
        count -= 1
    n += 1
print(count)


# 제곱 ㄴㄴ 수 출처분류
# 시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
# 2 초	512 MB	32870	5552	3723	19.871%
# 문제
# 어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. min과 max가 주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

# 입력
# 첫째 줄에 두 정수 min과 max가 주어진다.

# 출력
# 첫째 줄에 [min,max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다.

# 제한
# 1 ≤ min ≤ 1,000,000,000,000
# min ≤ max ≤ min + 1,000,000