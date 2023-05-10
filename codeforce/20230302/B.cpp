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

int N, K;
char buf[300000];
void solve() {
    scanf("%d %d %s", &N, &K, buf);
    map<int, int> M;
    for(int i = 0; i < 52; ++i) M[i] = 0;
    FOR(i,0,N) {
        if (buf[i] >= 'a' && buf[i] <= 'z') {
            M[buf[i] - 'a']++;
        } else {
            M[buf[i] - 'A' + 26]++;
        }
    }
    int margin = 0;
    int ans = 0;
    for(int i = 0; i < 26; ++i) {
        margin += (abs(M[i] - M[i + 26]) / 2);
        ans += min(M[i], M[i + 26]);
    }
    // _D("ANS: %d, MARGIN: %d, K: %d\n", ans, margin, K);
    ans += min(margin, K);
    printf("%d\n", ans);
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
