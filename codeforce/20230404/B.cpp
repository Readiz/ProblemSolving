#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("B_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

ll N, xx1, yy1, xx2, yy2;
void solve() {
    scanf("%lld %lld %lld %lld %lld", &N, &xx1, &yy1, &xx2, &yy2);
    // if (N == 2) {
    //     printf("0\n");
    //     return;
    // }
    ll hN = N >> 1;
    if (xx1 > hN) xx1 = N - xx1 + 1;
    if (xx2 > hN) xx2 = N - xx2 + 1;
    if (yy1 > hN) yy1 = N - yy1 + 1;
    if (yy2 > hN) yy2 = N - yy2 + 1;
    ll min1 = (xx1 < yy1) ? xx1 : yy1;
    ll min2 = (xx2 < yy2) ? xx2 : yy2;
    ll res = abs(min1 - min2);

    printf("%d\n", res);
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
