#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)<(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("G_input.txt", "rt", stdin); }
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

void solve() {
    bool check[31] = {false, };
    bool checkpos[200010] = {false, };
    int N;
    vector<ull> A;
    scanf("%d", &N);
    FOR(i,0,N) {
        ull t;
        scanf("%llu", &t);
        A.push_back(t);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    vector<ull> res;
    for(int s = 30; s >= 0; --s) {
        if (check[s]) continue;
        ull c = 1ULL << s;
        FOR(i,0,A.size()) {
            if (checkpos[i]) continue;
            ull v = A[i];
            if (v & c) {
                res.push_back(v);
                checkpos[i] = true;
                int p = 0;
                while(v) {
                    if (v & 1) {
                        check[p] = true;
                        // _D("[%d] %d, c\n", A[i], p);
                    }
                    v >>= 1;
                    ++p;
                }
                break;
            }
        }
    }
    FOR(i,0,A.size()) {
        if (checkpos[i] != true) {
            res.push_back(A[i]);
        }
    }
    printf("%d", res[0]);
    FOR(i,1,res.size()) {
        printf(" %d", res[i]);
    }
    printf("\n");
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
