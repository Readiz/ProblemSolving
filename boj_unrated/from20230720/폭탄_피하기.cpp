#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr unsigned int MOD = 1'000'000'007;
constexpr ull IMOD = 0xFFFFFFFFFFFFFFFF / MOD + 1;
inline ll reduce(ll n) {
    ull x = ull((__uint128_t(n) * IMOD) >> 64);
    unsigned int r = n - x * MOD;
    return MOD <= r ? r + MOD : r;
}
ll f[2'000'001] = {1, 1, };
ll finv[2'000'001] = {1, 1, };
ll fpow(ll a, ll p) {
    ll res = 1LL;
    while (p) {
        if (p & 1LL) res = reduce(res * a);
        a = reduce(a * a);
        p >>= 1LL;
    }
    return res;
}
// with large N & small K
// ll nCk(ll n, ll k) {
//     ll numerator = 1; // n * (n-1) * ... * (n-k+1)
//     for (int i=0; i<k; i++, n--) {
//         numerator = numerator * n % MOD;
//     }
//     // numerator / denominator mod p.
//     return numerator * finv[k] % MOD;
// }

ll nCk(ll n, ll k) {
    if (n == k || k == 0) return 1;
    ll r = reduce(f[n] * finv[n-k]);
    r = reduce(r * finv[k]);
    return r;
}
struct Point {
    int x, y;
    bool operator< (const Point& t) const {
        if (x + y != t.x + t.y) return x + y < t.x + t.y;
        if (y != t.y) return y < t.y;
        return x < t.x;
    }    
};
vector<Point> p;
int N, M, K;
int main() {
    for (int i = 1; i <= 2'000'000; ++i) {
        f[i] = reduce(f[i - 1] * i);
        finv[i] = fpow(f[i], MOD-2);
    }

    scanf("%d %d %d", &N, &M, &K);
    p.resize(K + 1);
    for(int i = 0; i < K; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        p[i] = {a, b};
    }
    p[K] = {N, M};
    sort(p.begin(), p.end());

    int cases = 1 << K; // 총 K개의 폭탄으로 생각 (MAX)
    ll ans = 0;
    for(int c = 0; c < cases; ++c) {
        int lx = 0, ly = 0;
        int bCnt = 0;
        ll lans = 1;
        bool hasValidPath = true;
        for(int b = 1, i = 0; i < K; b <<= 1, ++i) {
            if (b & c) {
                if (lx <= p[i].x && ly <= p[i].y) {
                    lans *= nCk(p[i].x - lx + p[i].y - ly, p[i].x - lx);
                    lans = reduce(lans);
                    lx = p[i].x, ly = p[i].y;
                    ++bCnt;
                } else {
                    hasValidPath = false;
                    break;
                }
            }
        }
        if(!hasValidPath) continue;
        lans *= nCk(N - lx + M - ly, N - lx);
        lans %= MOD;
        
        if (bCnt & 1) {
            // 폭탄 수가 홀수면 뺀다
            ans -= lans;
            while (ans < 0) ans += MOD;
            // printf("[d] subed: %lld\n", lans);
        } else {
            // 폭탄 수가 짝수면 더한다
            ans += lans;
            ans = reduce(ans);
            // printf("[d] added: %lld\n", lans);
        }
    }

    printf("%lld\n", ans);

    return 0;
}