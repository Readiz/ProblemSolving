#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    long long f[1'000'001];
    void update(int idx, int v) {
        for(; idx <= 1'000'000; idx += idx & -idx) {
            f[idx] += v;
        }
    }
    long long get(int idx) {
        long long r = 0;
        for(; idx > 0; idx -= idx & -idx) {
            r += f[idx];
        }
        return r;
    }
} f;

int find(long long t) {
    int l = 1, r = 1'000'000;
    int ans = 1'000'000;
    while (l <= r) {
        int m = (l + r) >> 1;
        long long v = f.get(m);
        if (v >= t) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int main() {
    int Q; scanf("%d", &Q);
    for(int i = 0; i < Q; ++i) {
        int query; scanf("%d", &query);
        if (query == 2) {
            int a, b; scanf("%d %d", &a, &b);
            f.update(a, b);
        } else {
            long long t; scanf("%lld", &t);
            int ans = find(t);
            printf("%d\n", ans);
            f.update(ans, -1);
        }
    }

    return 0;
}