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
int A[200010];
int oA[200010];
void solve() {
    scanf("%d", &N);
    FOR(i,0,N-1) {
        scanf("%d", &A[i]);
        oA[i] = A[i];
    }
    int minval = A[0];
    int minpos = 0;
    for(int i = 1; i < N-1; ++i) {
        if (minval >= A[i]) {
            minval = A[i];
            minpos = i;
            continue;
        }
        break;
    }
    _D("MINPOS: %d\n", minpos);
    for(int j = N - 1; j > 0; --j) { // 사이즈 업
        A[j] = A[j - 1];
        if (j-1 == minpos) {
            A[j-1] = 0;
            break;
        }
    }
    for(int i = 0; i < N - 1; ++i) {
        int v = max(A[i], A[i + 1]);
        if (v != oA[i]) {
            A[i] = A[i + 1];
        }
    }
    for(int i = 0; i < N; ++i) {
        printf("%d ", A[i]);
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
