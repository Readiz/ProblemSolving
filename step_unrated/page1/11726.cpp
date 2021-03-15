#include <stdio.h>

int main() {
    int dp[1001] = {0, 1, 2, };
    int N;
    scanf("%d", &N);
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] > 10007) dp[i] %= 10007;
    }
    printf("%d\n", dp[N]);
    return 0;
}

/* 피보나치가 나오는 유명한 문제..
하지만 왜 이게 나오는지는 잘 이해를 못함.. */
