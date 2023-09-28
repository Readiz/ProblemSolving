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

void check(ll N) {
    map<ll, int> M;
    for(ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            if (M.find(i) == M.end()) {
                M[i] = 1;
            } else {
                M[i]++;
            }
            N /= i;
            --i; continue;
        }
    }
    _D("[d] %lld -> ", N);
    for(auto& item: M) {
        _D("(%lld, %d) ", item.first, item.second);
    }
    _D("\n");
}

ll N, Q;
void solve() {
    scanf("%lld %lld", &N, &Q);
    ll oN = N;

    for(int q = 0; q < Q; ++q) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            ll x; scanf("%lld", &x);
            N *= x;
            check(N);
        } else {
            N = oN;
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}