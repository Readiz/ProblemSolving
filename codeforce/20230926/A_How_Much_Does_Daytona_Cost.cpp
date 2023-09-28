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

int N,K;
void solve() {
    scanf("%d%d", &N, &K);
    set<int> S;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        S.insert(tmp);
    }
    if (S.find(K) == S.end()) printf("NO\n");
    else printf("YES\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}