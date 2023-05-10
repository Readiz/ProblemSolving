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
char buf[200005];
void solve() {
    scanf("%d", &N);
    scanf("%s", buf);
    int ls[200005] = {0, }; // 부분합
    int rs[200005] = {0, };
    set<char> S1, S2;
    FOR(i,0,N) {
        S1.insert(buf[i]);
        ls[i] = S1.size();
    }
    FOR(i,0,N) {
        int j = N - i - 1;
        S2.insert(buf[j]);
        rs[j] = S2.size();
    }
    int max = -1;
    FOR(i,0,N-1) {
        if (max < ls[i] + rs[i + 1]) {
            max = ls[i] + rs[i + 1];
        }
    }
    printf("%d\n", max);
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
