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
#include <stdlib.h>
using namespace std;

int N;
void solve() {
    scanf("%d", &N);
    if (N == 3) {
        printf("2 3 1\n");
        return;
    }
    deque<int> q = {1};
    for(int i = N; i > 1; --i) {
        if (i % 2 == 0) q.push_front(i);
        else q.push_back(i);
    }
    printf("%d", q[0]);
    FOR(i,1,q.size()) {
        printf(" %d", q[i]);
    }
    printf("\n");
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
