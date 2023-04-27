#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)<(b)); ++i)
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
int B[200000];

bool dfs(int p) {
    //_D("DFS %d\n", p);
    if (p == N) {
        return true;
    }
    FOR(i,p+2,N+1) { // 최소 2개 이상..
        int len = i - p;
        // case 1 (앞)
        if (B[p] == len - 1) {
            // _D("[%d] ", B[p]);
            // FOR(k,p+1,i) {
            //     _D("%d ", B[k]);
            // }
            // _D("\n");
            if (dfs(i)) return true;
        }
        // case 2 (뒤)
        if (B[i - 1] == len - 1) {
            // FOR(k,p,i-1) {
            //     _D("%d ", B[k]);
            // }
            // _D("[%d] ", B[i - 1]);
            // _D("\n");
            if (dfs(i)) return true;
        }
    }
    return false;
}

void solve() {
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%d", &B[i]);
    }
    FOR(i,2,N+1) { // 최소 2개 이상..
        int len = i;
        // case 1 (앞)
        if (B[0] == len - 1) {
            // _D("[%d] ", B[0]);
            // FOR(k,1,i) {
            //     _D("%d ", B[k]);
            // }
            // _D("\n");
            if (dfs(i)) {
                printf("YES\n");
                return;
            }
        }
        // case 2 (뒤)
        if (B[i - 1] == len - 1) {
            // FOR(k,0,i-1) {
            //     _D("%d ", B[k]);
            // }
            // _D("[%d] ", B[i - 1]);
            // _D("\n");
            if (dfs(i)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
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
