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
    set<int> odd, even;
    FOR(i,0,N) {
        int t; scanf("%d", &t);
        if (t & 1) odd.insert(t);
        else even.insert(t);
    }
    if (odd.size() == 0 || even.size() == 0) {
        printf("YES\n");
        return;
    }
    int smallestOdd = *odd.begin();
    int smallestEven = *even.begin();
    if (smallestEven > smallestOdd) {
        printf("YES\n");
    } else {
        printf("NO\n");
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
