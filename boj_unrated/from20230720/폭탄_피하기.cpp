
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

    int cases = 1 << K; // 총 K개의 폭탄으로 생각 (MAX)

    ll ans = 0;
    for(int c = 0; c < cases; ++c) {
        int lx = 0, ly = 0;
        bool hasValidPath = true;
        vector<Point> path;
        for(int b = 1, i = 0; i < K; b <<= 1, ++i) {
            if (b & c) {
                if (lx <= p[i].x && ly <= p[i].y) {
                    lx = p[i].x, ly = p[i].y;
                    path.push_back(Point{lx, ly});
                } else {
                    hasValidPath = false;
                    break;
                }
            }
        }
        if(!hasValidPath) continue;
        int bCnt = path.size();
        path.push_back(Point{N, M});
        ll lans = 1;

        

        if (bCnt & 1) {

        } else {

        }
    }

    return 0;
}