#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

ll N, K, Q;
void solve() {
    scanf("%lld %lld %lld", &N, &K, &Q);
    int conseq = 0;
    ll ans = 0;
    ll tmp;
    FOR(i,0,N) {
        scanf("%lld", &tmp);
        if (tmp <= Q) {
            conseq += 1;
        } else {
            if (conseq >= K) {
                ll s = conseq - K + 1;
                ans += (s * (s + 1)) >> 1;
            }
            conseq = 0;
        }
    }
    if (conseq >= K) {
        ll s = conseq - K + 1;
        ans += (s * (s + 1)) >> 1;
    }
    printf("%lld\n", ans);
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
