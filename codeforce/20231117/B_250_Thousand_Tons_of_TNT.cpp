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
#define X first
#define Y second

int N;
void solve() {
    scanf("%d", &N);
    vector<ll> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%lld", &v[i]);
    vector<ll> pSum(N + 1);
    pSum[0] = 0;
    for(int i = 1; i <= N; ++i) {
        pSum[i] = pSum[i-1] + v[i];
    }

    int p = 1;
    ll ans = 0;
    for(; p * p <= N; ++p) {
        if (N % p == 0) {
            int k = N / p;
            _D("p: %d\n", p);
            _D("k: %d\n", k);
            ll low = 0x7FFFFFFFFFFFFFFF, high = 0;
            for(int i = k; i <= N; i += k) {
                ll cur = pSum[i] - pSum[i - k];
                if (cur < low) low = cur;
                if (cur > high) high = cur;
            }
            _D("h - l: %lld\n", high - low);
            if (ans < high - low) ans = high - low;
            {
                ll low = 0x7FFFFFFFFFFFFFFF, high = 0;
                int k = p;
                for(int i = k; i <= N; i += k) {
                    ll cur = pSum[i] - pSum[i - k];
                    if (cur < low) low = cur;
                    if (cur > high) high = cur;
                }
                _D("h - l: %lld\n", high - low);
                if (ans < high - low) ans = high - low;
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}