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
#define X first
#define Y second

ll MOD = 998244353; // 아마도 소수, modular inverse: p - 2 제곱
int N;

ll fastPow(ll a, ll p) {
    ll res = 1LL;
    while (p) {
        if (p & 1LL) res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1LL;
    }
    return res;
}

ll getInv(ll v) {
    return fastPow(v, MOD - 2);
}

ll P[300010];
ll ACC[300010];

void solve() {
    scanf("%d", &N);
    vector<ll> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%lld", &v[i]);

    P[0] = 1;
    ACC[0] = 1;

    ll INV = getInv(N);
    for(int i = 1; i <= N; ++i) {
        P[i] = ACC[i - 1] * INV;
        P[i] %= MOD;
        ACC[i] = ACC[i - 1] + P[i];
        ACC[i] %= MOD;
    }

    ll ans = 0;
    for(int i = 1; i <= N; ++i) {
        ans += v[i] * P[i];
        ans %= MOD;
    }
    
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}