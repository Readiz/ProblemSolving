# Python Gosu project

N, K, M = map(int, input().split(' '))
a = map(int, input().split(' '))

K -= 1 # mapper

for i in range(M):
    op = int(input())
    if op > 0:
        op -= 1
        # [0, op] <- rev
        # 0 -> op
        # 1 -> op - 1
        # 2 -> op - 2 ...
        if K <= op:
            K = op - K
    elif op < 0:
        # -1 ~ -N 까지 가능
        # 시작점은 N이랑 더하면 된다.
        op = N + op
        # op -> N - op - 1
        # op + 1 -> N - op - 2
        # ...
        if K >= op:
            K = N - 1 - K + op

print(K + 1)
