#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); ((i)<(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int A[100010], N, K;
void solve() {
    scanf("%d %d", &N, &K);
    ll cnt1 = 0;
    ll remain = 0;
    ll merges = 0;
    FOR(i,0,K) {
        scanf("%d", &A[i]);
        if (A[i] == 1) ++cnt1;
        else {
            remain += A[i] - 1;
            merges += A[i];
        }
    }
    sort(A,A+K);
    remain -= A[K - 1] - 1;
    merges -= A[K - 1];
    printf("%lld\n", remain + merges + cnt1);
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
