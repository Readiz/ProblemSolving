
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1'000'000'007;
ll f[2'000'001] = {1, 1, };
ll finv[2'000'001] = {1, 1, };
ll fpow(ll a, ll p) {
    ll res = 1LL;
    while (p) {
        if (p & 1LL) res = res * a % MOD;
        a = a * a % MOD;
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
    ll r = f[n] * finv[n-k] % MOD;
    r = r * finv[k] % MOD;
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
        f[i] = f[i - 1] * i * 1LL % MOD;
        finv[i] = fpow(f[i], MOD-2);
    }

    scanf("%d %d %d", &N, &M, &K);
    p.resize(K + 1);
    for(int i = 0; i < K; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        p[i] = {a, b};
    }
    p[K] = {N, M};

    // Bitmasking DP를 해보자.
    ll DP[1<<21] = {0, };
    for(;;) {
        // Checking Condition to go

        // check N

        // check bomb cnt

        // add? sub?

    }

    return 0;
}