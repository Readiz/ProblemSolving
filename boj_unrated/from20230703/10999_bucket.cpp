#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll bucket[1'000][1'000];
ll bucketSum[1'000];
ll bucketLazy[1'000];

void updateRange(int l, int r, ll diff) {
    --l; --r;
    int sb = l / 1000;
    int eb = r / 1000;

    if (sb == eb) {
        for(int i = l; i <= r; ++i) {
            bucket[sb][i % 1000] += diff;
            bucketSum[sb] += diff;
        }
    } else {
        // 1. sb
        for(int i = l % 1000; i < 1000; ++i) {
            bucket[sb][i] += diff;
            bucketSum[sb] += diff;
        }
        // 2. lazy
        for(int i = sb + 1; i < eb; ++i) {
            bucketLazy[i] += diff;
        }
        // 3. eb
        for(int i = 0; i <= r % 1000; ++i) {
            bucket[eb][i] += diff;
            bucketSum[eb] += diff;
        }
    }
}

ll getRange(int l, int r) {
    --l, --r;
    int sb = l / 1000;
    int eb = r / 1000;
    ll res = 0;

    if (sb == eb) {
        for(int i = l; i <= r; ++i) {
            res += bucket[sb][i % 1000] + bucketLazy[sb];
        }
    } else {
        // 1. sb
        for(int i = l % 1000; i < 1000; ++i) {
            res += bucket[sb][i] + bucketLazy[sb];
        }
        // 2. lazy
        for(int i = sb + 1; i < eb; ++i) {
            res += bucketLazy[i] * 1000 + bucketSum[i];
        }
        // 3. eb
        for(int i = 0; i <= r % 1000; ++i) {
            res += bucket[eb][i] + bucketLazy[eb];
        }
    }
    return res;
}
int main() {
    int N, M, K; scanf("%d %d %d", &N, &M, &K);

    for(int i = 0; i < N; ++i) {
        scanf("%lld", &bucket[i / 1000][i % 1000]);
        bucketSum[i / 1000] += bucket[i / 1000][i % 1000];
    }
    // O(10000 * 1000)
    for(int i = 0; i < M + K; ++i) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            int l, r; ll v;
            scanf("%d %d %lld", &l, &r, &v);
            updateRange(l, r, v);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", getRange(l, r));
        }
    }

    return 0;
}