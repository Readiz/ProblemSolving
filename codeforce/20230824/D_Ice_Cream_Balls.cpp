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

void solve() {
    ll N;
    scanf("%lld", &N);
    if (N == 1) {
        printf("2\n");
        return;
    }

    ll l = 1, r = 3000000000, m = (l+r) / 2;
    ll ans = -1;
    for(; l <= r; m = (l+r) / 2) {
        // _D("%lld ~ %lld ~ %lld\n", l, m, r);
        ll cur = m * (m - 1) / 2;
        // _D("NC2 = %lld\n", cur);
        if (cur <= N) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }
    ll K = N - (ans*(ans-1)/2);
    printf("%lld\n", ans + K);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}