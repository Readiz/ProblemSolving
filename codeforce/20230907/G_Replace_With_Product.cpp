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
void solve() {
    scanf("%d", &N);
    vector<ll> v(N+1);
    vector<ll> pSum(N+1);
    FOR(i,1,N+1) {
        scanf("%lld", &v[i]);
    }
    for(int i = 1; i <= N; ++i) {
        pSum[i] = pSum[i - 1] + v[i];
    }
    int l = -1, r = -1;
    for(int i = 1; i <= N; ++i) {
        if (v[i] != 1) {
            l = i;
            break;
        }
    }
    for(int i = N; i >= 1; --i) {
        if (v[i] != 1) {
            r = i;
            break;
        }
    }
    if (l == -1 && r == -1) {
        printf("1 1\n");
        return;
    }
    _D("start: %d, %d\n", l, r);
    ll INF = 0x7FFFFFFF;
    ll curProduct = v[l];
    for(int i = l + 1; i <= r; ++i) {
        if (v[i] != 1) {
            curProduct *= v[i];
            curProduct = min(curProduct, INF);
            ll curSum = pSum[i] - pSum[l - 1];
            _D("p: %lld s: %lld\n", curProduct, curSum);
            if (curProduct >= curSum) continue;

            // 곱하면 손해다
            curProduct = v[i];
            l = i;
        }
    }
    printf("%d %d\n", l, r);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}