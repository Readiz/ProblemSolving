#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
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

int N;
int A[2000];
void solve() {
    scanf("%d", &N);
    int largeIdx = -1;
    int largeNum = -1;
    FOR(i,0,N) {
        scanf("%d", &A[i]);
        if (i != 0 && A[i] > largeNum) {
            largeNum = A[i];
            largeIdx = i;
        }
    }
    if (N == 1) {
        printf("%d\n", A[0]);
        return;
    }
    if (largeIdx == N - 1) {
        int i, t = largeIdx;
        for(i = largeIdx; i >= 0; --i) {
            if (A[i] > A[0]) {
                t = i;
                continue;
            }
            break;
        }
        for(int k = largeIdx; k >= t; --k) {
            printf("%d ", A[k]);
        }
        for(int k = 0; k < t; ++k) {
            printf("%d ", A[k]);
        }
        printf("\n");
        return;
    }
    int i;
    int t = largeIdx - 1;
    for(i = largeIdx - 2; i >= 0; --i) {
        if (A[i] > A[0]) {
            t = i;
            continue;
        }
        break;
    }
    // i 까지는 감소함
    for(int i = largeIdx; i < N; ++i) {
        printf("%d ", A[i]);
    }
    for(int k = largeIdx - 1; k >= t; --k) {
        printf("%d ", A[k]);
    }
    for(int k = 0; k < t; ++k) {
        printf("%d ", A[k]);
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
