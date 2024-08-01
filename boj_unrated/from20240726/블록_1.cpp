#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1999;

int ipow(int x, int p){
    int ret = 1, piv = x;
    while(p){
        if(p & 1) ret = ret * piv % MOD;
        piv = piv * piv % MOD;
        p >>= 1;
    }
    return ret;
}

vector<int> berlekamp_massey(vector<int> x) {
    vector<int> ls, cur;
    int lf, ld;
    for (int i = 0; i < x.size(); i++) {
        ll t = 0;
        for (int j = 0; j < cur.size(); j++) {
            t = (t + 1ll * x[i - j - 1] * cur[j]) % MOD;
        }
        if ((t - x[i]) % MOD == 0) continue;
        if (cur.empty()) {
            cur.resize(i + 1);
            lf = i;
            ld = (t - x[i]) % MOD;
            continue;
        }
        ll k = -(x[i] - t) * ipow(ld, MOD - 2) % MOD;
        vector<int> c(i - lf - 1);
        c.push_back(k);
        for (auto& j : ls) c.push_back(-j * k % MOD);
        if (c.size() < cur.size()) c.resize(cur.size());
        for (int j = 0; j < cur.size(); j++) {
            c[j] = (c[j] + cur[j]) % MOD;
        }
        if (i - lf + (int)ls.size() >= (int)cur.size()) {
            tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % MOD);
        }
        cur = c;
    }
    for (auto& i : cur) i = (i % MOD + MOD) % MOD;
    return cur;
}
int get_nth(vector<int> rec, vector<int> dp, ll n) {
    int m = rec.size();
    vector<int> s(m), t(m);
    s[0] = 1;
    if (m != 1) t[1] = 1;
    else t[0] = rec[0];
    auto mul = [&rec](vector<int> v, vector<int> w) {
        int m = v.size();
        vector<int> t(2 * m);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                t[j + k] += 1ll * v[j] * w[k] % MOD;
                if (t[j + k] >= MOD) t[j + k] -= MOD;
            }
        }
        for (int j = 2 * m - 1; j >= m; j--) {
            for (int k = 1; k <= m; k++) {
                t[j - k] += 1ll * t[j] * rec[k - 1] % MOD;
                if (t[j - k] >= MOD) t[j - k] -= MOD;
            }
        }
        t.resize(m);
        return t;
    };
    while (n) {
        if (n & 1) s = mul(s, t);
        t = mul(t, t);
        n >>= 1;
    }
    ll ret = 0;
    for (int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % MOD;
    return ret % MOD;
}
int guess_nth_term(vector<int> x, ll n) {
    if (n < x.size()) return x[n];
    vector<int> v = berlekamp_massey(x);
    if (v.empty()) return 0;
    return get_nth(v, x, n);
}

int pre[1010], dp[2010];
int N;
ll M; 

bool valid(int r, int c) {
    if (r >= 0 && r <= N && c >= 0 && c <= M) return true;
    return false;
}

int main() {
    scanf("%d %lld", &N, &M);
    // for(int i = 1; i <= N; ++i) dp[i][0] = 1;
    // for(int i = 1; i <= M; ++i) dp[0][i] = 1;
    pre[0] = 1;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= i; ++j) {
            pre[i] += pre[i - j];
            pre[i] %= MOD;
        }
    }

    dp[0] = 1;
    for(int c = 1; c <= 2 * N; ++c) {
        for(int r = 1; r <= min(N, c); ++r) {
            // 각 위치에 대해서 블럭들을 넣어본다.
            // 현재 위치: (r, c)
            if (r < N) dp[c] += dp[c - r], dp[c] %= MOD;
            else dp[c] += dp[c - r] * pre[r], dp[c] %= MOD;
        }
    }

    vector<int> v;
    for(int i = 0; i <= 2 * N; ++i) {
        v.push_back(dp[i]);
    }

    printf("%d\n", guess_nth_term(v, M));

    // printf("chk---\n");
    // for(int i = 11; i <= 100; ++i) {
    //     printf("[%d] %d vs %d\n", i, dp[N][i], guess_nth_term(v, i));
    // }

    return 0;
}