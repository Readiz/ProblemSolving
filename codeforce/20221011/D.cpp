#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
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

int M;
int P[262144];
int swapcnt;
void dfs(int l, int s) { // step size
    if (s == 1) {
        return;
    }
    s >>= 1;
    if (P[l] > P[l+s]) {
        FOR(i,l,l+s) {
            P[i] ^= P[i+s] ^= P[i] ^= P[i+s];
        }
        ++swapcnt;
    }
    dfs(l,s);
    dfs(l+s,s);
}
void solve() {
    swapcnt = 0;
    scanf("%d", &M);
    FOR(i,0,M) {
        scanf("%d", &P[i]);
    }
    dfs(0,M);
    int valid = true;
    FOR(i,1,M) {
        if (P[i-1] < P[i]) continue;
        valid = false; break;
    }
    if (valid) printf("%d\n", swapcnt);
    else printf("-1\n");
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
