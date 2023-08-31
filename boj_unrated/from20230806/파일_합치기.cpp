#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

constexpr int INF = 987654321;
void solve() {
    int N;
    scanf("%d", &N);
    vector<int> cost(N+1);
    vector<int> pSum(N+1);
    
    FOR(i,1,N+1) {
        scanf("%d", &cost[i]);
        pSum[i] = pSum[i-1] + cost[i];
    }

    int DP[501][501];
    fill((int*)DP, (int*)DP+501*501, INF);
    for(int i = 0; i <= N; ++i) DP[i][i] = 0;

    for(int d = 1; d <= N; ++d) {
        for(int i = 1; i <= N-1; ++i) {
            int j = i + d;
            if (j > N) break;
            for(int k = i; k <= j; ++k) {
                // dp[i][j] = dp[i][k] + dp[k+1][j] + areaSum
                if (DP[i][k] + DP[k+1][j] + pSum[j] - pSum[i - 1] < DP[i][j]) {
                    _D("%d ~ %d = %d ~ %d + %d ~ %d = %d\n", i, j, i, k, k + 1, j, DP[i][k] + DP[k+1][j] + pSum[j] - pSum[i - 1]);
                }
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k+1][j] + pSum[j] - pSum[i - 1]);
            }
        }
    }

    printf("%d\n", DP[1][N]);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}