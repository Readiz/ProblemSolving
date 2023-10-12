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

struct Range {
    int l, r;
    bool operator<(const Range& t) const {
        if (l != t.l) return t.l < l;
        return t.r < r;
    }
};

int N;
int v[200010];
void solve() {
    scanf("%d", &N);
    for(int i = N - 1; i >= 0; --i) {
        scanf("%d", &v[i]);
    }
    int dp[200010] = {0, };
    dp[0] = 1;
    for(int i = 1; i < N; ++i) {
        if (v[i] > i) {
            dp[i] = dp[i - 1] + 1;
            continue;
        }
        if (v[i] == i) {
            dp[i] = 0;
            continue;
        }
        int newl = i - v[i];
        int newr = i;
        dp[i] = min(dp[newl - 1], dp[i - 1] + 1);
    }
    // priority_queue<Range> pq;
    // for(int i = 1; i < N; ++i) {
    //     if (v[i] > i) continue;
    //     int newl = i - v[i];
    //     int newr = i;
    //     _D("now check %d ~ %d (val: %d ~ %d)\n", newl, newr, v[newl], v[newr]);
    //     priority_queue<Range> tmp;
    //     int old = 0;
    //     while(pq.size() && pq.top().r >= newl) {
    //         old += pq.top().r - pq.top().l + 1;
    //         tmp.push(pq.top()); pq.pop();
    //     }
    //     if (old < newr - newl + 1) {
    //         pq.push({newl, newr});
    //     } else {
    //         while(tmp.size()) {
    //             pq.push(tmp.top()); tmp.pop();
    //         }
    //     }
    // }
    // int covered = 0;
    // while(pq.size()) {
    //     covered += pq.top().r - pq.top().l + 1;
    //     pq.pop();
    // }
    //printf("%d\n", N - covered);
    printf("%d\n", dp[N - 1]);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}