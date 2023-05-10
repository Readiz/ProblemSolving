#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
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
    int zero = 0;
    int neg = 0;
    int pos = 0;
    int min = 0x7FFFFFFF;
    ll sum = 0;
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            ++zero;
        } else if (t > 0) {
            ++pos;
        } else {
            ++neg;
        }
        if (min > abs(t)) min = abs(t);
        sum += abs(t);
    }
    if (zero == 0 && neg % 2 == 1) {
        sum -= min << 1;
    }
    printf("%lld\n", sum);
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
