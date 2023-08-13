import random

N = 49999

a = [(0, 0), *((i, 0) for i in range(1, N+1)), *((0, i) for i in range(1, N+1))]
random.shuffle(a)
print(len(a))
for i in a: print(*i)