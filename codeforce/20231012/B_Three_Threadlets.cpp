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

int N;
void solve() {
    multiset<ll> S;
    for(int i = 0; i < 3; ++i) {
        ll t; scanf("%lld", &t);
        S.insert(t);
    }
    for(int k = 0; k < 3; ++k) {
        ll small = *S.begin();
        ll large = *S.rbegin();
        if (large > small) {
            S.erase(--S.end());
            ll a = small;
            ll b = large - small;
            S.insert(a);
            S.insert(b);
        }
    }
    ll cur = 0;
    for(auto& item: S) {
        if (cur == 0) {
            cur = item;
            continue;
        }
        if (cur == item) continue;
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}