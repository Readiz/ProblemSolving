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

// lb

ull bd, bt; // big dam, big time
ull sd, st; // small dam, small time
ull h, s;
bool check(ll t) {
    ull t1 = t / bt;
    ull t1d = t1 * (bd - s);
    ull t2 = (t - t1 * bt) / st;
    ull t2d = t2 * (sd - s);
    if (h <= t1d + t2d) {
        return true;
    }
    return false;
}
void solve() {
    ull a, b, c, d;
    scanf("%llu %llu %llu %llu %llu %llu", &a, &b, &c, &d, &h, &s);
    if (b > d) {
        bt = b;
        bd = a + c;
        st = d;
        sd = c;
    } else {
        bt = d;
        bd = a + c;
        st = b;
        sd = a;
    }
    ull l = 0, r = 0xFFFFFFFFFFFFFFFF;
    while (l < r) {
        ull m = l + ((r - l) >> 1);
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    printf("%llu\n", l);
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    solve();
MAIN_END
