#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)<(b)); ++i)
#ifdef READIZ_DEBUG
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
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    int N;
    int A[1001] = {0, };
    scanf("%d", &N);
    vector<int> v;
    FOR(i,1,N+1) {
        int t;
        scanf("%d", &t);
        if (A[t] == 0) v.push_back(t);
        A[t] = i;
    }
    int max = -1;
    FOR(i,0,v.size()) FOR(j,i,v.size()) {
        if (gcd(v[i], v[j]) == 1) {
            if (max < A[v[i]] + A[v[j]]) {
                max = A[v[i]] + A[v[j]];
            }
        }
    }
    printf("%d\n", max);
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
