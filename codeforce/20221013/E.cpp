#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int N, Q;
ll A[200001];
ll K[200001];
// ll dp[200001];
ll S[200001];

ll MAX(ll a, ll b) {
    return (a > b) ? a : b;
}
void solve() {
    scanf("%d %d", &N, &Q);
    FOR(i,1,N+1) {
        scanf("%d", &A[i]);
    }
    FOR(i,0,Q) {
        scanf("%d", &K[i]);
    }
    vector<ll> dp;
    dp.push_back(0);
    FOR(i,1,N+1) {
        dp.push_back(MAX(dp[i-1], A[i]));
        S[i] = A[i] + S[i - 1];
    }
    FOR(q,0,Q) {
        auto it = upper_bound(dp.begin(), dp.end(), K[q]);
        // _D("IDX: %d -> %lld\n", it - dp.begin(), S[it - dp.begin() - 1]);
        printf("%lld ", S[it - dp.begin() - 1]);
    }
    printf("\n");
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
