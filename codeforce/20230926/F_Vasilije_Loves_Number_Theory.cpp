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
    ll oN = N;
    _D("[d] %lld -> ", N);
    map<ll, ll> M;
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
    if (M.find(N) == M.end()) {
        M[N] = 1;
    } else {
        M[N]++;
    }
    ll multi = 1;
    for(auto& item: M) {
        _D("(%lld, %lld) ", item.first, item.second);
        multi *= item.second + 1;
    }
    _D("\n");
    if (oN == 1) printf("YES\n");
    else {
        _D("[multi] %lld\n", multi);
        if (oN % multi == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
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
    printf("\n");
    _D("-----------\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}