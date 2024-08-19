#include <stdio.h>

long long dp[5001][2501];

const long long MOD = 1'000'000'007;
void preprocessing() {
    for(int i=0;i<=5000;++i) dp[i][0] = 0;
    for(int i=0;i<=5000;++i) dp[i][1] = 1;
    for(int j=1; j<=2500;++j) {
        for(int i=2;i<=5000;++i) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i][j] %= MOD;
        }
    }
}

void solve(int n) {
    if (n % 2 == 1) {
        printf("0\n");
        return;
    }
    printf("%lld\n", dp[n][n/2]);
}

int main() {
    preprocessing();
    int TC; scanf("%d", &TC);
    while(TC--) {
        int n; scanf("%d", &n);
        solve(n);
    }
    return 0;
}
