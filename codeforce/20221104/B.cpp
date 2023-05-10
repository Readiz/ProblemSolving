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

int N;
void solve() {
    scanf("%d", &N);
    _D("N: %d\n", N);
    string debug = "";
    FOR(i,0,N) {
        debug += "BAN";
    }
    _D("%s  / %d\n", debug.c_str(), debug.size());

    // 범위: 1 ~ 3 * N
    if (N % 2 == 0) {
        // 짝수
        printf("%d\n", N / 2);
        for(int n = 1; n < 3 * N; n += 6) {
            printf("%d %d\n", n, n + 4);

            char t = debug[n-1];
            debug[n-1] = debug[n+3];
            debug[n+3] = t;
        }
    } else {
        printf("%d\n", N / 2 + 1);
        printf("1 3\n");
        char t = debug[0];
        debug[0] = debug[2];
        debug[2] = t;

        for(int n = 4; n < 3 * N; n += 6) {
            printf("%d %d\n", n, n + 4);
            char t = debug[n-1];
            debug[n-1] = debug[n+3];
            debug[n+3] = t;
        }
    }
    _D("%s\n", debug.c_str());
    FOR(i,0,debug.size() - 2) {
        if (debug[i] == 'B' && debug[i+1] == 'A' && debug[i+2] == 'N') {
            _D("ERRRR!!!!!!!!!!! BAN FOUND!\n");
            return;
        }
    }
    _D("NO BAN! PASSED.\n");
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
