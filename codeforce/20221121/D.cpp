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

int N;
void solve() {
    bool isIncresingStart = false;
    scanf("%d", &N);
    int prev;
    scanf("%d", &prev);
    if (N == 1) {
        printf("YES\n");
        return;
    }
    bool flag = true;
    FOR(i,1,N) {
        int cur;
        scanf("%d", &cur);
        if (prev < cur) {
            isIncresingStart = true;
        }
        if (isIncresingStart && (prev > cur)) {
            flag = false;
        }
        prev = cur;
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
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
