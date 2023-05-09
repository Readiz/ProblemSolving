#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
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

int N;
void solve() {
    scanf("%d", &N);
    int last = -1;
    int clen = 0;
    int maxlen = 0;
    FOR(i,0,N) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp != last) {
            if (tmp == 1 && clen > maxlen) maxlen = clen;
            clen = 1;
        } else {
            clen++;
        }
        last = tmp;
    }
    if (last == 0) {
        if (clen > maxlen) maxlen = clen;
    }
    printf("%d\n", maxlen);
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
