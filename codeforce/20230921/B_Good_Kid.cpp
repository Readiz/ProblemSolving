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
    vector<ll> v(N);
    FOR(i,0,N) {
        ll a; scanf("%lld", &a);
        v[i] = a;
    }
    ll maxProduct = 0;
    for(int i = 0; i < N; ++i) {
        v[i] += 1;
        ll curProduct = 1;
        for(int j = 0; j < N; ++j) {
            curProduct *= v[j];
        }
        if (curProduct > maxProduct) maxProduct = curProduct;
        v[i] -= 1;
    }
    printf("%lld\n", maxProduct);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}