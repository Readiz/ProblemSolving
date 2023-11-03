N = int(input())
t = [0] * 36
t[0] = 1

for i in range(1, N + 1):
    cur = i
    for k in range(0, cur):
        inv = cur - k - 1
        t[cur] += t[k] * t[inv]

for i in range(1, N + 1):
    print(t[i])