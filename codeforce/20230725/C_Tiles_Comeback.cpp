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

    vector<int> cnt;
    cnt.resize(N+1);
    fill(cnt.begin(), cnt.end(), 0);

    vector<int> C;
    C.resize(N);

    vector<vector<int>> P;
    P.resize(N + 1);

    FOR(i,0,N) {
        scanf("%d", &C[i]);
        ++cnt[C[i]];
        P[C[i]].push_back(i);
    }
    int lc = C[0]; int rc = C[N-1];
    if (lc == rc) {
        if (cnt[lc] >= K) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        if (P[lc].size() >= K && P[rc].size() >= K) {
            if (P[lc][K-1] < P[rc][P[rc].size() - K]) printf("YES\n");
            else printf("NO\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}