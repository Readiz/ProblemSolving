#include <stdio.h>

typedef long long ll;

constexpr int MOD = 1'000'000'007;
ll fastpow(ll v, ll p) {
    ll ans = 1;
    while(p) {
        if (p & 1) ans *= v;
        v *= v;
        p >>= 1;
        v %= MOD;
        ans %= MOD;
    }
    return ans;
}

int main() {
    int M; scanf("%d", &M);
    ll ans = 0;
    for(int i = 0; i < M; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b); // N, S
        ans += b * fastpow(a, MOD - 2);
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}