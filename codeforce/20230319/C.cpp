#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
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
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int N;
char buf[2010];
void solve() {
    scanf("%d", &N);
    scanf("%s", buf);
    set<char> odd;
    set<char> even;
    FOR(i,0,N) {
        char& c = buf[i];
        if (odd.find(c) == odd.end() && even.find(c) == even.end()) {
            if (i % 2 == 0) {
                even.insert(c);
                _D("%c -> even\n", c);
            } else {
                odd.insert(c);
                _D("%c -> odd\n", c);
            }
            continue;
        } else if (odd.find(c) != odd.end()) {
            if (i % 2 == 1) continue;
        } else {
            if (i % 2 == 0) continue;
        }
        _D("%c -> not matched.\n", c);
        printf("NO\n");
        return;
    }
    printf("YES\n");
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
