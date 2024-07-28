N=int(input())
if N == 1:
    print(1)
else:
    N-=1 # 수열로 생각
    dp = [0] * (N + 1)

    dp[0] = 1
    dp[1] = 1

    for i in range(2, N + 1):
        if i == N:
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
        else:
            dp[i] = dp[i - 1] + dp[i - 3]
        dp[i] %= 1_000_000_009

    print(dp[N])
