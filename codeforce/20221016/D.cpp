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

int getlog(int v) {
    int ans = 0;
    while ((v > 1) && (v % 2 == 0)) {
        ++ans;
        v >>= 1;
    }
    return ans;
}

int N;
void solve() {
    scanf("%d", &N);
    _D("N: %d\n", N);
    int cnt2 = 0;
    bool visited[200001] = {false, };
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        // _D("val: %d\n", t);
        while (t > 0 && (t & 1) == 0) {
            ++cnt2;
            t >>= 1;
            // _D("CNT++\n");
        }
    }
    _D("CNT2: %d / Target: %d\n", cnt2, N);
    int ans = 0;
    int p = 1;
    while(p <= N) {
        if ((p << 1) <= N) p <<= 1;
        else break;
    }
    _D("Checkign start p: %d...\n", p);
    while (p > 1) {
        _D("p: %d\n", p);
        int pp = p;
        while (pp <= N) {
            if (!visited[pp]) {
                visited[pp] = true;
                // _D("checking pp %d -> %d...\n", pp, getlog(pp));
                if (getlog(pp) + cnt2 <= N) {
                    cnt2 += getlog(pp);
                    ++ans;
                    _D("-> mult %d!  cur cnt2: %d\n", pp, cnt2);
                }
            }
            pp += p;
        }
        p >>= 1;
    }
    if (cnt2 >= N) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
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
