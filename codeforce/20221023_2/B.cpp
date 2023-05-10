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
char buf[200001];
void solve() {
    scanf("%d", &N);
    scanf("%s", buf);
    if (N == 1) {
        printf("0\n");
        return;
    }
    bool isFirst = true;
    char last = buf[N-1];
    int ans = 0;
    for(int i = N - 2; i >= 0; --i) {
        char c = buf[i];
        if (c == last) continue;
        if (isFirst) {
            isFirst = false;
            last = c;
        } else {
            ++ans;
            last = c;
        }
    }
    if (isFirst) {
        printf("0\n");
        return;
    }
    if (buf[0] == '1') {
        ++ans;
    }
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
