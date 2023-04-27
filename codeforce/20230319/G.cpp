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

int N;
void solve() {
    scanf("%d", &N);
    vector<int> a;
    FOR(i,0,N) {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    ll sum = 1;
    if (a[0] != sum) {
        printf("NO\n");
        return;
    }
    FOR(i,1,N) {
        if (a[i] > sum) {
            _D("A[%d] = %d, sum: %d\n", i, a[i], sum);
            printf("NO\n");
            return;
        }
        sum += a[i];
    }
    printf("YES\n");
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
