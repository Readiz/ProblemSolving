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

ll N, K, X;
void solve() {
    scanf("%lld%lld%lld", &N, &K, &X);
    ll MIN = K * (K+1) / 2;
    ll MAX = K * (N+(N-K+1)) / 2;
    _D("[d] %lld ~ %lld\n", MIN, MAX);
    if (X >= MIN && X <= MAX) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}