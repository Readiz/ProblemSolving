#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll MOD = 1'000'000'009LL;

ll DP[1'000'010];
void solve() {
    int N; scanf("%d", &N);
    memset(DP, 0x00, sizeof(ll) * (N+1));
    DP[1] = 1; DP[2] = 2; DP[3] = 4;
    for(int j = 4; j <= N; ++j) {
        DP[j] += DP[j - 1];
        DP[j] += DP[j - 2];
        DP[j] += DP[j - 3];
        DP[j] %= MOD;
    }
    
    printf("%lld\n", DP[N]);
}
int main() {
    int TC; scanf("%d", &TC);
    while(TC--) solve();
    return 0;
}