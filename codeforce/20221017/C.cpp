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
char buf[200001];
void solve() {
    bool check[200001] = {false,};
    scanf("%d", &N);
    scanf("%s", buf);
    vector<int> A;
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        A.push_back(t);
        _D("%d ", t);
    }
    _D("\n");
    int p = 0;
    ll sum = 0;
    int slast0 = - 1;
    for(; buf[p] != 0; ++p) {
        if (buf[p] == '1') {
            int max = A[p], maxIdx = p;
            int pp = p;
            if (slast0 >= 0) {
                if (A[slast0] >= max) {
                    maxIdx = slast0;
                    max = A[slast0];
                    slast0 = p;
                }
            }
            _D("Select %d! (idx: %d)\n", max, maxIdx);
            sum += max;
            check[maxIdx] = true;
        } else {
            slast0 = p;
        }
    }
    printf("%lld\n", sum);
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
