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
// Bottom-Up SegTree
struct SegTree {
    int d[400'020]; // *2
    void build() {
        for(int i = N - 1; i > 0; --i) {
            d[i] = d[i<<1] & d[i<<1|1];
        }
    }
    int query(int l, int r) {
        // _D("[seg] query: %d ~ %d\n", l, r);
        l += N, r += N;
        int ret = 0xFFFFFFFF;
        for(; l <= r; l>>=1, r>>=1) {
            if ( l & 1) ret &= d[l++];
            if (~r & 1) ret &= d[r--];
        }
        return ret;
    }
} seg;

void solve() {
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%d", &seg.d[i + N]);
    }
    seg.build();
    int Q; scanf("%d", &Q);
    for(int q = 0; q < Q; ++q) {
        int l, k; scanf("%d %d", &l, &k);
        --l;
        int left = l, right = N - 1;
        int ans = -1;
        for(int mid = (left + right) / 2; left <= right; mid = (left + right) / 2) {
            if (seg.query(l, mid) >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (ans == -1) printf("-1 ");
        else printf("%d ", ans + 1);
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