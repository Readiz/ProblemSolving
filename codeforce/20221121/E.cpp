#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
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
    vector<int> A;
    FOR(i,0,N) {
        int c;
        scanf("%d", &c);
        A.push_back(c);
    }
    ll csum = 0;
    ll overallsum = 0;
    for(int i = N-1; i >= 0; --i) {
        if (A[i] == 0) {
            csum++;
        } else {
            overallsum += csum;
        }
    }
    ll val1 = overallsum;
    overallsum = 0; csum = 0;
    int flippedpos = -1;
    FOR(i,0,N) {
        if (A[i] == 0) {
            A[i] = 1;
            flippedpos = i;
            break;
        }
    }
    for(int i = N-1; i >= 0; --i) {
        if (A[i] == 0) {
            csum++;
        } else {
            overallsum += csum;
        }
    }
    ll val2 = overallsum;
    overallsum = 0; csum = 0;

    if (flippedpos != -1) A[flippedpos] = 0;
    for(int i = N-1; i >= 0; --i) {
        if (A[i] == 1) {
            A[i] = 0;
            break;
        }
    }

    for(int i = N-1; i >= 0; --i) {
        if (A[i] == 0) {
            csum++;
        } else {
            overallsum += csum;
        }
    }
    ll val3 = overallsum;

    // _D("%lld %lld %lld\n", val1, val2, val3);
    if (val1 >= val2 && val1 >= val3) {
        printf("%lld\n", val1);
    } else if (val2 >= val1 && val2 >= val3) {
        printf("%lld\n", val2);
    } else {
        printf("%lld\n", val3);
    }
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
