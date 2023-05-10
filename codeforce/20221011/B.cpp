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

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        int n;
        scanf("%d", &n);
        if (n == 2) printf("2 1\n");
        else if (n == 3) printf("-1\n");
        else if (n & 1) {
            printf("%d %d ", n, n - 1);
            for(int i = 1; i <= n - 2; ++i) {
                printf("%d ", i);
            }
            printf("\n");
        }
        else {
            printf("%d %d ", n - 1, n);
            for(int i = n - 2; i >= 1; --i) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
MAIN_END
