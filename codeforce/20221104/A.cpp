#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("A_input.txt", "rt", stdin); }
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

int N;
void solve() {
    scanf("%d", &N);
    vector<int> S1, S2;
    ll CS1 = 0, CS2 = 0;
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        if (t > 0) {
            S1.push_back(t);
            CS1 += t;
        }
        else {
            S2.push_back(-t);
            CS2 -= t;
        }
    }
    if (CS1 > CS2) {
        printf("%lld\n", CS1 - CS2);
    } else {
        printf("%lld\n", CS2 - CS1);
    }
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
