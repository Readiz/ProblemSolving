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

int N, A;
char buf[200010];
void solve() {
    scanf("%d %d", &N, &A);
    scanf("%s", buf);
    register int i;
    register int j;
    for(i = 0; i < N; ++i) {
        char cc = buf[i];
        int cv = cc - '0';
        if (cv >= A) {
            continue;
        }
        break;
    }
    for(j = 0; j < i; ++j) {
        printf("%c", buf[j]);
    }
    printf("%d", A);
    for(j = i; j < N; ++j) {
        printf("%c", buf[j]);
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
