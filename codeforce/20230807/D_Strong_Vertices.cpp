#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

int N;
void solve() {
    scanf("%d", &N);
    vector<ll> A, B, C;
    A.resize(N); B.resize(N); C.resize(N);
    FOR(i,0,N) scanf("%lld", &A[i]);
    FOR(i,0,N) scanf("%lld", &B[i]);
    ll maxval = -999999999999;
    FOR(i,0,N) {
        C[i] = A[i] - B[i];
        if (C[i] > maxval) maxval = C[i];
    }
    int cnt = 0;
    FOR(i,0,N) {
        if (C[i] == maxval) ++cnt;
    }
    printf("%d\n", cnt);
    FOR(i,0,N) {
        if (C[i] == maxval) printf("%d ", i + 1);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}