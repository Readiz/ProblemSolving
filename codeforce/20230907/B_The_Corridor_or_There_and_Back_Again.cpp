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
int room[500];
bool go(int t) {
    _D("checking %d...\n", t);
    int k = 0, c = 0;
    int dtime[500] = {0, };
    while(k <= t) {
        ++c; ++k;
        dtime[k] = room[k] + c;
    }
    --c;
    while(k >= 1) {
        if (dtime[k] < c) {
            _D("boom at %d! / time: %d / boom time: %d\n", k, c, dtime[k]);
            return false;
        }
        --k; ++c;
    }
    return true;
}
void solve() {
    scanf("%d", &N);
    memset(room, 0x3A, sizeof(int)*500);
    FOR(i,0,N) {
        int a, b; scanf("%d %d", &a, &b);
        room[a] = min(room[a], b);
    }
    int l = 1, r = 499, m = 250;
    int ans = -1;
    for(;l <= r; m = (l+r) / 2) {
        bool ret = go(m);
        if (ret) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}