#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
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
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int N;
ll A[200001];
void solve() {
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%lld\n", &A[i]);
    }
    sort(A, A+N);
    if (A[0] * A[1] > A[N-1] * A[N-2]) {
        printf("%lld\n", A[0] * A[1]);
    } else {
        printf("%lld\n", A[N-1] * A[N-2]);
    }
    // int i;
    // for(i = 1; i < N; ++i) {
    //     if (A[i - 1] < 0 && A[i] >= 0) {
    //         break;
    //     }
    // }
    // if (i - 1 == N) { // all 음수
    //     printf("%lld\n")
    // }
    // ll max1 = arr[0] * arr[1];
    // ll max2 = arr[arr.size() - 1] * arr[arr.size() - 2];
    // printf("%lld\n", max(max1, max2));
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
