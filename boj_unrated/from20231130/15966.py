# Python Gosu project
N = int(input())
A = map(int, input().split(' '))

cache = [0] * 1_000_001

for i in A: # 순서대로 순회하자
    if cache[i - 1] + 1 > cache[i]:
        cache[i] = cache[i - 1] + 1

print(max(cache))
