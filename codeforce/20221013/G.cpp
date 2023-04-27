#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
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
    bool check[32] = {false, };
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
    vector<ull> appendix;
    FOR(i,0,A.size()) {
        ull v = A[i];
        bool flag = false; // 한번이라도 새로운게 나왔으면 true
        int cp = 0;
        while (v) {
            if (v & 1) {
                if (check[cp] == false) {
                    check[cp] = true;
                    flag = true;
                }
            }
            ++cp;
            v >>= 1;
        }
        if (flag) {
            res.push_back(A[i]);
        } else {
            appendix.push_back(A[i]);
        }
    }
    FOR(i,0,res.size()) {
        printf("%d ", res[i]);
    }
    FOR(i,0,appendix.size()) {
        printf("%d ", appendix[i]);
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
