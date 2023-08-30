N, M, H = map(int, input().split())
stu = [[] for _ in range(N+1)]
for i in range(1, N+1):
    stu[i] = list(map(int, input().split()))

dp = [[0 for _ in range(H+1)] for _ in range(N+1)]

for i in range(1, N+1):
    for k in stu[i]:
        if k <= H:
            dp[i][k] += 1
    for j in range(0, H+1): # i 번째 학생까지 블록을 쌓았을 때 j 높이에서의 경우의 수
        dp[i][j] += dp[i-1][j]
        for k in stu[i]:
            if j-k >= 0:
                dp[i][j] += dp[i-1][j-k]

print(dp[N][H] % 10007)