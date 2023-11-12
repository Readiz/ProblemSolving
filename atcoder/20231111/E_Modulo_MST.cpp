#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X first
#define Y second

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

struct Edge {
    ll s, e;
    ll weight;
    bool operator<(const Edge& t) const {
        return weight > t.weight;
    }
} edges[100000];

ll N, M, K;

struct UnionFind {
    ll parents[9];
    void init() {
        for(ll i = 1; i <= N; ++i) {
            parents[i] = i;
        }
    }
    ll findRoot(ll v) {
        if (v == parents[v]) return v;
        return parents[v] = findRoot(parents[v]);
    }
    void merge(ll a, ll b) {
        a = findRoot(a); b = findRoot(b);
        if (a == b) return;
        parents[b] = a;
    }
} uf;


void solve() {
    scanf("%lld %lld %lld", &N, &M, &K);

    for(ll i = 0; i < M; ++i) {
        ll s, e, w;
        scanf("%lld %lld %lld", &s, &e, &w);
        edges[i] = {s, e, w};
    }
    ll end = 1LL << M;
    ll ans = 0x7FFFFFFFFFFFFFFFLL;
    for(ll state = 1; state < end; ++state) {
        if (__builtin_popcountll(state) != N - 1) continue;
        uf.init();
        ll csum = 0;
        bool flag = true;
        for(ll cur = 1, i = 0; i < M; cur <<= 1, ++i) {
            if (cur & state) {
                // 포함되는 간선
                auto& c = edges[i];
                if (uf.findRoot(c.s) != uf.findRoot(c.e)) {
                    // no cycle
                    uf.merge(c.s, c.e);
                    csum += c.weight;
                    csum %= K;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && csum < ans) ans = csum;
    }
    printf("%lld\n", ans);
}

int main() {
    // int TC; scanf("%d", &TC);
    // while(TC--)
    solve();
    return 0;
}