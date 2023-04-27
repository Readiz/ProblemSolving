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

int N, r, c;
ll fibs[47];
void solve() {
    scanf("%d %d %d", &N, &r, &c);
    // N: 홀수 - 답은 (1,1), (1,2)
    // N: 짝수 - 답은 (1,1), (2,1) 뿐
    _D("%d %d\n", r, c);
    // 좌표를 검사하는데, fib 수보다 작은 수를 검사한다.
    // hflip 먼저다.
    bool hflip = true;
    int fibIdx = N;
    for(;fibIdx > 0; --fibIdx) {
        if (hflip) {
            if (c > fibs[fibIdx]) {
                c = fibs[fibIdx + 1] - c + 1;
            }
        } else {
            if (r > fibs[fibIdx]) {
                r = fibs[fibIdx + 1] - r + 1;
            }
        }
        _D("[%d] %d %d [%d]\n", fibs[fibIdx], r, c, hflip);
        if (r < 0 || c < 0) {
            printf("NO\n");
            return;
        }
        hflip = !hflip;
    }

    if (r == 1 && c == 1) printf("YES\n");
    else if (N % 2 == 1 && r == 1 && c == 2) printf("YES\n");
    else if (N % 2 == 0 && r == 2 && c == 1) printf("YES\n");
    else printf("NO\n");

}

void init() {
    fibs[1] = fibs[0] = 1;
    for(int i = 2; i <= 46; ++i) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    init();
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
