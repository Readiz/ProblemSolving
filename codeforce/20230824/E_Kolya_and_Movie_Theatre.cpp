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
    ll N, M, D;
    scanf("%lld %lld %lld", &N, &M, &D);
    vector<ll> v(N+1);
    int maxVal = 0;
    int maxIdx = -1;
    FOR(i,1,N+1) {
        scanf("%lld", &v[i]);
    }

    for(int i = 1; i <= N - M; ++i) {
        ll tmp = v[i] - D * i;
        if (tmp > maxVal) {
            maxVal = tmp;
            maxIdx = i;
        }
    }

    if (maxIdx == -1) {
        printf("0\n");
        return;
    }

    // ll ans = maxVal;

    // _D("Start: %lld\n", ans);
    // int dist = 1;
    // int last = maxIdx + 1;
    // for(int i = maxIdx + 1; i <= N; ++i, ++dist) {
    //     ll cval = v[i] - dist * D;
    //     if (cval > 0) {
    //         last = i;
    //     }
    // }
    // _D("Last: %d = %lld\n", last, v[last]);
    // for(int i = maxIdx + 1; i <= last; ++i, ++dist) {
    //     ll cval = v[i] - dist * D;
    //     if (v[i] > 0) {
    //         ans += cval;
    //     }
    // }

    // printf("%lld\n", ans);

    // _D("[D] ");
    // for(auto& i: v) {
    //     _D("%lld ", i);
    // }
    // _D("\n");

}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}