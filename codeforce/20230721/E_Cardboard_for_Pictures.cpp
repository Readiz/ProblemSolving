#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

ll N, C;

typedef __float128 mdouble;

void solve2(mdouble a, mdouble b, mdouble c4) {
    mdouble d = b*b - a*c4;
    mdouble e = sqrt(d);
    mdouble ans1 = (-b + e) / (2.0*a), ans2 = (-b - e) / (2.0*a);
    if (ans1 > 0) {
        printf("%lld\n", (ll)ans1);
    } else {
        printf("%lld\n", (ll)ans2);

    }
}

void solve() {
    scanf("%lld %lld", &N, &C);
    ll s1 = 0; ll s2 = 0;
    FOR(i,0,N) {
        ll tmp; scanf("%lld", &tmp);
        s1 += tmp;
        s2 += tmp * tmp;
    }
    ll a = N;
    ll b = s1;
    ll c = s2 - C;
    solve2(a, b, c);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}