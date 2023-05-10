#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
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
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;


int N;
ll A[2000];
ll SS[2000]; // partial sum
int S[2000];
ll tsum;
int sp;
int minth;
void dfs(int i) {
    if (i == N) {
        _D("Found All sum same!\n");
        int last = -1;
        int maxth = 0;
        FOR(p,0,sp) {
            int ct = S[p] - last;
            if (ct > maxth) maxth = ct;
            _D("%d ", S[p]);
            last = S[p];
        }
        if (maxth < minth) minth = maxth;
        _D("\n");
        _D("-> %d\n", maxth);
        return;
    }
    FOR(b,i,N) {
        ll csum = SS[b] - SS[i-1];
        if (csum == tsum) {
            S[sp++] = b;
            dfs(b+1);
            --sp;
        }
    }
}
void solve() {
    sp = 0;
    scanf("%d", &N);
    minth = N;
    FOR(i,0,N) {
        scanf("%d", &A[i]);
    }
    ll ss = 0;
    FOR(i,0,N) {
        ss += A[i];
        SS[i] = ss;
    }
    FOR(b,0,N) {
        tsum = SS[b];
        S[sp++] = b;
        _D("TSUM: %d, dfs start...\n", tsum);
        dfs(b+1);
        --sp;
    }
    _D("ANS: ");
    printf("%d\n", minth);
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
