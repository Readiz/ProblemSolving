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

int N, K;
void solve() {
    scanf("%d %d", &N, &K);
    vector<pii> A;
    vector<int> O;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        A.push_back({tmp, i+1});
        O.push_back(tmp);
    }
    sort(A.begin(), A.end());

    int mmin = INT_MAX;
    int l, r;
    for (int i = 0; i < N - 1; i++) {
        int v = A[i].first ^ A[i+1].first;
        if (v < mmin) {
            mmin = v;
            l = A[i].second;
            r = A[i+1].second;
        }
    }

    int k = K - 1;
    for(; k >= 0; --k) {
        if ((1<<k) & O[r-1]) {
            break;
        }
    }
    ++k;
    unsigned int tmp = O[l-1];
    for(int tk = k; tk < 32; ++tk) {
        tmp |= (1U << tk);
    }
    tmp = ~tmp;
        
    int x = tmp;
    for(; k < K; ++k) {
        x |= (1 << k);
    }
    
    // _D("mmin: %d / %d / %d /%d \n", mmin, l, r, O[l-1] ^ O[r-1]);
    // int x = (1<<K) - 1;
    // x = x & mmin;
    if (l < r) printf("%d %d %d\n", l, r, x);
    else printf("%d %d %d\n", r, l, x);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}