#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("F_input.txt", "rt", stdin); }
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


ll N, S, D;
ll getS(vector<ll>& A, int k) {
    ll us = 0;
    for(int i = 0; i < k + 1; ++i) {
        if (i < N) {
            us += A[i];
        }
    }
    ll s = us * (D / (k + 1));
    for(int i = 0; i < D % (k + 1); ++i) {
        if (i < N) {
            s += A[i];
        }
    }
    return s;
}
void solve() {
    scanf("%lld %lld %lld", &N, &S, &D);
    vector<ll> A;
    FOR(i,0,N) {
        ll c;
        scanf("%lld", &c);
        A.push_back(c);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    ll tsum = 0;
    FOR(i,0,N) {
        if (i < D) {
            tsum += A[i];
        }
    }

    if (A[0] * D < S) {
        printf("Impossible\n");
        return;
    }
    if (tsum >= S) {
        printf("Infinity\n");
        return;
    }

    int l = 0; int r = D;
    int k;
    while(l < r) {
        k = (l + r) / 2;
        // _D("%d~%d~%d\n", l, k, r);
        // _D("%lld vs %lld\n", getS(A, k), S);
        if (getS(A, k) < S) {
            r = k;
        } else {
            l = k + 1;
        }
    }
    printf("%d\n", l - 1);
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
