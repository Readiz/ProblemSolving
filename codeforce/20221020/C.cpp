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
void solve() {
    scanf("%d", &N);
    multiset<int> A;
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        A.insert(t);
        if (N == 1) {
            if (t <= 1) {
                printf("1\n");
                return;
            } else {
                printf("0\n");
                return;
            }
        }
    }
    multiset<int> oA = A; // original A;
    int k;
    for(k = A.size() + 1; k >= 0; --k) {
        if (k == 0) break;
        _D("k: %d ---\n", k);
        A = oA;
        bool flag = true;
        for(int p = k; p >= 1; --p) {
            auto it = A.upper_bound(p);
            if (it == A.begin()) {
                flag = false;
                break;
            }
            --it;
            _D("pop %d\n", *it);
            A.erase(it);
            int min = *A.begin();
            A.erase(A.begin());
            _D("bob %d -> %d\n", min, min + p);
            A.insert(p + min);
        }
        if (flag) break;
    }
    printf("%d\n", k);
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
