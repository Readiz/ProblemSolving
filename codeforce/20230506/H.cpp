#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("H_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int cntbit(int v) {
    int cntres = 0;
    while(v > 0) {
        v &= v - 1;
        ++cntres;
    }
    return cntres;
}

int N, K;
int A[200'001];
ll DP[200'001][64];
ll MOD = 1'000'000'007;
void solve() {
    scanf("%d %d", &N, &K);

    _D("N: %d, K: %d\n", N, K);
    for(R int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        for(R int j = 0; j < 64; ++j) {
            DP[i][j] = 0;
        }
    }

    for(R int i = 1; i <= N; ++i) {
        DP[i][A[i]] += 1;
        for(int j = 0; j < 64; ++j) { // prev value
            DP[i][j] += DP[i-1][j]; // 새로운 값을 쓰지 않는 경우
            DP[i][j] %= MOD;

            int nv = j & A[i];
            DP[i][nv] += DP[i-1][j];
            DP[i][nv] %= MOD;
        }
    }

    ll ans = 0;
    for(int j = 0; j < 64; ++j) {
        if (cntbit(j) == K) {
            ans += DP[N][j];
            ans %= MOD;
            _D("DP[%d][%d] = %d\n", N, j, DP[N][j]);
        }
    }
    printf("%lld\n", ans);
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
