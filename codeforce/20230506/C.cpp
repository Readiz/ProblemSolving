#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
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

int N;
void solve() {
    scanf("%d", &N);
    int left = 0x7FFFFFFF;
    int right = 0x7FFFFFFF;
    int both = 0x7FFFFFFF;
    FOR(i,0,N) {
        int a, b;
        scanf("%d %d", &a, &b);
        // _D("%d %d\n", a, b);
        if (b == 11) {
            if (both > a) both = a;
            if (left > a) left = a;
            if (right > a) right = a;
        } else if (b == 10) {
            if (left > a) left = a;
        } else if (b == 1) {
            if (right > a) right = a;
        }
    }
    if (left == 0x7FFFFFFF || right == 0x7FFFFFFF) {
        printf("-1\n");
        return;
    }
    if (left + right < both) {
        printf("%d\n", left + right);
    } else {
        printf("%d\n", both);
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
