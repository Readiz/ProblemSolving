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

ll N, X;
void solve() {
    scanf("%lld%lld", &N, &X);
    multiset<ll> vals;
    FOR(i,0,N) {
        ll s; scanf("%lld", &s);
        vals.insert(s);
    }

    ll l = 1; ll r = 20'000'000'000'000;
    ll ans = -1;
    for(ll m = (l+r)/2; l <= r; m = (l+r)/2) {
        ll cArea = 0;
        // 높이 m으로 채워보자
        auto eit = vals.lower_bound(m);
        for(auto it = vals.begin(); it != eit; ++it) {
            cArea += m - *it;
            if (cArea > X) break;
        }
        if (cArea <= X) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}