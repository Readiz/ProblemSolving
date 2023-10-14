

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
Point bomb[21];
int N, M, K;
int main() {
    for (int i = 1; i <= 2'000'000; ++i) {
        f[i] = f[i - 1] * i * 1LL % MOD;
        finv[i] = fpow(f[i], MOD-2);
    }

    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < K; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        bomb[i] = {a, b};
    }
    sort(bomb, bomb + K);

    // 폭탄을 거쳐가는 경로의 수를 센다.
    ll ans = 0;
    int t = 1 << K; // 모든 경우의 수를 셀 것임
    for(int cur = 1; cur < t; ++cur) { // 폭탄을 적어도 1개 방문하는 경우의 수
        // 현재 cur에 켜진 비트들의 폭탄을 "모두" 방문하는 경로가 유효한가?
        // 유효하면 경우의 수를 계산
        Point last = {0, 0};
        bool valid = true;
        ll curAns = 1;
        for(int i = 0, b = 1; i < K; ++i, b <<= 1) {
            if (cur & b) {
                if (bomb[i].x >= last.x && bomb[i].y >= last.y) {
                    int dx = abs(bomb[i].x - last.x);
                    int dy = abs(bomb[i].y - last.y);
                    curAns *= nCk(dx + dy, dx);
                    curAns %= MOD;
                    last.x = bomb[i].x;
                    last.y = bomb[i].y;
                } else {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            int dx = abs(N - last.x);
            int dy = abs(M - last.y);
            curAns *= nCk(dx + dy, dx);
            curAns %= MOD;
            // printf("Valid Path detected! added: %lld\n", curAns);
            ans += curAns;
            ans %= MOD;
        }
    }

    printf("%lld\n", (nCk(N+M, N) - ans + MOD) % MOD);

    return 0;
}