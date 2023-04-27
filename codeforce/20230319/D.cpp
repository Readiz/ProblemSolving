#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
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

int N, Q;
int a[200010];
ll s[200010];
void solve() {
    scanf("%d %d", &N, &Q);
    FOR(i,0,N) {
        scanf("%d\n", &a[i+1]);
    }
    FOR(i,1,N+1) {
        s[i] = s[i-1] + a[i];
    }
    // 원래 sum에서 range에 있는 것만 바뀌는 것
    // range sum의 짝 / 홀수가 변경되면 원래 짝 / 홀수가 바뀐다.
    _D("ORISUM: %d\n", s[N]);
    bool isOriginalOdd = (s[N] % 2) == 1;
    
    FOR(i,0,Q) {
        int l, r, k;
        scanf("%d %d %d\n", &l, &r, &k);
        _D("%d~%d -> %d\n", l, r, k);
        ll oriRangeSum = s[r] - s[l-1];
        ll newRangeSum = ((ll)r - (ll)l + 1) * (ll)k;
        ll diff = newRangeSum - oriRangeSum;
        if (diff < 0) diff *= -1;
        _D("%d -> %d, diff: %d\n", oriRangeSum, newRangeSum, diff);
        // 부호가 바뀌면 원본 변경
        if (diff % 2 == 1) isOriginalOdd = !isOriginalOdd;
        if (isOriginalOdd) printf("YES\n");
        else printf("NO\n");
        if (diff % 2 == 1) isOriginalOdd = !isOriginalOdd;
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
