#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("A_input.txt", "rt", stdin); }
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

int N, T;
int A[101];
int B[101];
void solve() {
    scanf("%d %d", &N, &T);
    FOR(i,1,N+1) {
        scanf("%d", &A[i]);
        A[i] += i - 1;
    }
    FOR(i,1,N+1) {
        scanf("%d", &B[i]);
    }
    int MAX = -1;
    int MAXIDX = -1;
    FOR(i,1,N+1) {
        if (A[i] <= T) {
            if (MAX < B[i]) {
                MAX = B[i];
                MAXIDX = i;
            }
        }
    }
    printf("%d\n", MAXIDX);
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
