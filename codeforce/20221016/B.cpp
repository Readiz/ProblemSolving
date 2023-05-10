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

int N, Q;
ll Se, So;
int Ce, Co;
void solve() {
    scanf("%d %d", &N, &Q);
    _D("TC: N - %d\n", N);
    Se = 0;
    So = 0;
    Ce = 0;
    Co = 0;
    FOR(i,0,N) {
        ll t;
        scanf("%lld", &t);
        if (t & 1) {
            So += t;
            ++Co;
        } else {
            Se += t;
            ++Ce;
        }
    }
    FOR(q,0,Q) {
        ll t, x;
        scanf("%lld %lld", &t, &x);
        //_D("INPUT: %d, %d\n", t, x);
        if (t == 0) { // even
            if (x & 1) { // even + odd -> even 사라짐!
                So += Se + Ce * x;
                Co += Ce;
                Se = 0;
                Ce = 0;
            } else {
                Se += Ce * x;
            }
        } else { // odd
            if (x & 1) { // odd + odd -> odd 사라짐!
                Se += So + Co * x;
                Ce += Co;
                So = 0;
                Co = 0;
            } else { // odd + even -> odd
                So += Co * x;
            }
        }
        printf("%lld\n", So + Se);
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
