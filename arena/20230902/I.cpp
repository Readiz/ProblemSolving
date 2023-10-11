

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
    p.resize(K + 2);
    p[0] = {0, 0};
    for(int i = 1; i <= K; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        p[i] = {a, b};
    }
    p[K + 1] = {N, M};

    ll DP[K + 2][K + 2]; // i 에서 j까지 가는 경로의 수.
    bool isRightBefore[K+2][K+2] = {false,};
    for(int i = 0; i < K + 2; ++i) {
        for(int j = 0; j < K + 2; ++j) {
            DP[i][j] = -1;
        }
    }

    // 초기값: 정점 a, b를 잡아서 사이에 아무것도 없다는게 confirm 되면 채운다.
    for(int a = 0; a < K + 2; ++a) {
        for(int b = 0; b < K + 2; ++b) {
            if (a == b) {
                DP[a][b] = 0;
                continue;
            }
            if (p[a].x > p[b].x || p[a].y > p[b].y) continue;

            bool valid = true;
            for(int k = 0; k < K + 2; ++k) {
                if (k == a || k == b) continue;
                if (p[k].x >= p[a].x && p[k].y >= p[a].y &&
                    p[k].x <= p[b].x && p[k].y <= p[b].y) {
                        valid = false;
                        break;
                }
            }
            // 사이에 아무도 없음
            if (valid == true) {
                int dx = abs(p[a].x - p[b].x);
                int dy = abs(p[a].y - p[b].y);
                DP[a][b] = nCk(dx + dy, dx) % MOD;
                // printf("[d] DP[%d][%d] is added\n", a, b);
                isRightBefore[a][b] = true;
            }
        }
    }

    while(DP[0][K+1] == -1) { // 유효한 값이 올때까지 계속해서 업뎃한다..
        for(int a = 0; a < K + 2; ++a) {
            for(int b = 0; b < K + 2; ++b) {
                if (DP[a][b] != -1) continue;
                if (p[a].x > p[b].x || p[a].y > p[b].y) continue;

                bool valid = true;
                ll cur = 0; // 밟는 경우의 수
                for(int k = 0; k < K + 2; ++k) {
                    if (k == a || k == b) continue;
                    if (isRightBefore[k][b]) {
                        if (DP[a][k] == -1 || DP[k][b] == -1) {
                            valid = false;
                            break;
                        }
                        int dxak = abs(p[a].x - p[k].x);
                        int dyak = abs(p[a].y - p[k].y);
                        int dxkb = abs(p[b].x - p[k].x);
                        int dykb = abs(p[b].y - p[k].y);
                        ll RDPAK = nCk(dxak + dyak, dxak) - DP[a][k];
                        RDPAK %= MOD;
                        ll RDPKB = nCk(dxkb + dykb, dxkb) - DP[k][b];
                        RDPKB %= MOD;

                        // 1. 안밟 * 밟
                        cur += DP[a][k] * RDPKB;
                        cur %= MOD;
                        // 2. 밟 * 안밟
                        cur += DP[k][b] * RDPAK;
                        cur %= MOD;
                        // 3. 밟 * 밟
                        cur -= DP[a][k] * DP[k][b];
                        cur += MOD;
                        cur %= MOD;
                    }
                }
                // 사이에 아무도 없음
                if (valid == true) {
                    int dx = abs(p[a].x - p[b].x);
                    int dy = abs(p[a].y - p[b].y);
                    DP[a][b] = nCk(dx + dy, dx) - cur;
                    DP[a][b] += MOD;
                    DP[a][b] %= MOD;
                    // DP[a][b] = cur;
                    // printf("[d2] DP[%d][%d] is added\n", a, b);
                }
            }
        }
    }

    printf("%lld\n", DP[0][K+1]);


    return 0;
}