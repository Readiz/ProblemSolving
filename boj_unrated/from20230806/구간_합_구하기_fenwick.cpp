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

int N;

struct Fenwick {
    ll d[1'000'010];

    ll get(int idx) {
        ll ret = 0;
        for(; idx > 0; idx -= idx & -idx) {
            ret += d[idx];
        }
        return ret;
    }
    void update(int idx, ll v) {
        for(; idx <= N; idx += idx & -idx) {
            d[idx] += v;
        }
    }
    void set(int idx, ll v) {
        ll cur = get(idx) - get(idx - 1);
        ll diff = v - cur;
        update(idx, diff);
    }
} f;

int main() {
    int M, K; scanf("%d%d%d", &N, &M, &K);
    for(int i = 1; i <= N; ++i) {
        ll cur; scanf("%lld", &cur);
        f.update(i, cur);
    }

    for(int q = 0; q < M + K; ++q) {
        ll cmd, a, b; scanf("%lld %lld %lld", &cmd, &a, &b);
        if (cmd == 1) {
            f.set(a, b);
        } else {
            printf("%lld\n", f.get(b) - f.get(a - 1));
        }
    }

    return 0;
}