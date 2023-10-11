

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
vector<Point> rbomb;
int N, M, K;
int main() {
    for (int i = 1; i <= 2'000'000; ++i) {
        f[i] = f[i - 1] * i * 1LL % MOD;
        finv[i] = fpow(f[i], MOD-2);
    }

    scanf("%d %d %d", &N, &M, &K);
    rbomb.resize(K);
    for(int i = 0; i < K; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        rbomb[i] = {a, b};
    }
    sort(rbomb.begin(), rbomb.end());

    vector<vector<Point>> g;
    for(auto& c: rbomb) {
        bool found = false;
        for(auto& gc: g) {
            if (gc[0].x <= c.x && gc[0].y <= c.y) {
                gc.push_back(c);
                found = true;
                break;
            }
        }
        if (!found) {
            vector<Point> newG;
            newG.push_back(c);
            g.push_back(newG);
        }
    }
    // printf("[gsize] %d\n", g.size());
    
    ll ans = 0;
    for(auto& bomb: g) { // 현재 경로를 보자..
        Point last = {0, 0};
        ll curAns = 1;
        for(int i = 0; i < bomb.size(); ++i) {
            int dx = abs(bomb[i].x - last.x);
            int dy = abs(bomb[i].y - last.y);
            curAns *= nCk(dx + dy, dx);
            curAns %= MOD;
            last.x = bomb[i].x;
            last.y = bomb[i].y;
        }

        int dx = abs(N - last.x);
        int dy = abs(M - last.y);
        curAns *= nCk(dx + dy, dx);
        curAns %= MOD;
        // printf("Valid Path detected! added: %lld\n", curAns);
        ans += curAns;
        ans %= MOD;
    }

    printf("%lld\n", (nCk(N+M, N) - ans + MOD) % MOD);

    return 0;
}