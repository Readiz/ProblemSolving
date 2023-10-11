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

ll n, x, y;
void solve() {
    scanf("%lld%lld%lld", &n, &x, &y);
    if (x == y) {
        printf("0\n");
        return;
    }
    ll g = __gcd(x, y);
    ll lcm = g * (x / g) * (y /g);
    // _D("gcd: %lld lcm: %lld\n", g, lcm);
    ll lcmcnt = n / lcm;
    ll xcnt = n / x - lcmcnt; // N, N-1, ... xcnt 수의 합
    ll ycnt = n / y - lcmcnt; // 1 ~ ycnt 수의 합
    ll yval = ycnt * (ycnt + 1) / 2;
    ll xval = n * xcnt - (xcnt * (xcnt - 1) / 2);
    // _D("xcnt: %lld / ycnt: %lld\n", xcnt, ycnt);
    printf("%lld\n", xval - yval);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}