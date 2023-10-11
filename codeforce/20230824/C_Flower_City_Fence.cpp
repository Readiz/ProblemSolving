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
    vector<int> v(N+1);
    vector<int> e(N+1);
    FOR(i,1,N+1) {
        scanf("%d", &v[i]);
    }
    if (v[1] != N) {
        printf("NO\n");
        return;
    }
    for(int x = 1; x <= N; ++x) {
        int y = v[x];
        e[y] = max(e[y], x);
    }
    // _D("[EEE] ");
    // for(int x = 1; x <= N; ++x) {
    //     _D("%d ", e[x]);
    // }
    // _D("\n");
    for(int x = 1; x <= N; ++x) {
        if (e[x] == 0) continue;
        if (e[x] != v[x]) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}