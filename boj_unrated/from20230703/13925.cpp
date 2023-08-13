#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

enum cmd {
    SUM = 1,
    PRODUCT = 2,
    OVERRITE = 3
};

ll bucket[320][320];
ll bucketSum[320];
vector<pair<cmd, ll>> bucketLazy[320];


constexpr ll MOD = 1'000'000'007LL;

void handleLazy(int b) {
    for(int i = 0; i < 320; ++i) {
        for(auto& item: bucketLazy[b]) {
            if (item.first == SUM) {
                bucket[b][i] += item.second;
                bucket[b][i] %= MOD;
            } else if (item.first == PRODUCT) {
                bucket[b][i] *= item.second;
                bucket[b][i] %= MOD;
            } else {
                bucket[b][i] = item.second;
            }
        }
    }
    bucketLazy[b].clear();
}

void updateRange(int l, int r, ll v, int cmd) {
    --l; --r;
    int sb = l / 320;
    int eb = r / 320;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(int i = l; i <= r; ++i) {
            if (cmd == 1) {
                bucketSum[sb] += v;
                assert(bucketSum[i] >= 0);
                bucketSum[sb] %= MOD;
                bucket[sb][i % 320] += v;
                bucket[sb][i % 320] %= MOD;
            } else if (cmd == 2) {
                bucketSum[sb] += bucket[sb][i % 320] * (v - 1);
                assert(bucketSum[i] >= 0);
                bucketSum[sb] %= MOD;
                bucket[sb][i % 320] *= v;
                bucket[sb][i % 320] %= MOD;
            } else {
                bucketSum[sb] += v - bucket[sb][i % 320];
                assert(bucketSum[i] >= 0);
                bucketSum[sb] %= MOD;
                bucket[sb][i % 320] = v;
                bucket[sb][i % 320] %= MOD;
            }
        }
    } else {
        // 1. sb
        for(int i = l % 320; i < 320; ++i) {
            if (cmd == 1) {
                bucketSum[sb] += v;
                assert(bucketSum[i] >= 0);
                bucketSum[sb] %= MOD;
                bucket[sb][i] += v;
                bucket[sb][i] %= MOD;
            } else if (cmd == 2) {
                bucketSum[sb] += bucket[sb][i] * (v - 1);
                assert(bucketSum[i] >= 0);
                bucketSum[sb] %= MOD;
                bucket[sb][i] *= v;
                bucket[sb][i] %= MOD;
            } else {
                bucketSum[sb] += v - bucket[sb][i];
                assert(bucketSum[i] >= 0);
                bucketSum[sb] %= MOD;
                bucket[sb][i] = v;
                bucket[sb][i] %= MOD;
            }
        }
        // 2. lazy
        for(int i = sb + 1; i < eb; ++i) {
            if (cmd == 1) {
                bucketLazy[i].push_back({SUM, v});
                bucketSum[i] += v * 320LL;
                assert(bucketSum[i] >= 0);
                bucketSum[i] %= MOD;
            } else if (cmd == 2) {
                bucketLazy[i].push_back({PRODUCT, v});
                bucketSum[i] *= v;
                if (bucketSum[i] < 0) {
                    printf("%lld / %lld\n", bucket[i], v);
                }
                assert(bucketSum[i] >= 0);
                bucketSum[i] %= MOD;
            } else {
                bucketLazy[i].clear();
                bucketLazy[i].push_back({OVERRITE, v});
                bucketSum[i] = 320LL * v;
                assert(bucketSum[i] >= 0);
                bucketSum[i] %= MOD;
            }
        }
        // 3. eb
        for(int i = 0; i <= r % 320; ++i) {
            if (cmd == 1) {
                bucketSum[eb] += v;
                assert(bucketSum[i] >= 0);
                bucketSum[eb] %= MOD;
                bucket[eb][i] += v;
                bucket[eb][i] %= MOD;
            } else if (cmd == 2) {
                bucketSum[eb] += bucket[eb][i] * (v - 1);
                assert(bucketSum[i] >= 0);
                bucketSum[eb] %= MOD;
                bucket[eb][i] *= v;
                bucket[eb][i] %= MOD;
            } else {
                bucketSum[eb] += v - bucket[eb][i];
                assert(bucketSum[i] >= 0);
                bucketSum[eb] %= MOD;
                bucket[eb][i] = v;
                bucket[eb][i] %= MOD;
            }
        }
    }
}


ll getRange(int l, int r) {
    --l, --r;
    int sb = l / 320;
    int eb = r / 320;
    ll res = 0;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(int i = l; i <= r; ++i) {
            res += bucket[sb][i % 320];
            res %= MOD;
        }
    } else {
        // 1. sb
        for(int i = l % 320; i < 320; ++i) {
            res += bucket[sb][i];
            res %= MOD;
        }
        // 2. lazy
        for(int i = sb + 1; i < eb; ++i) {
            res += bucketSum[i];
            res %= MOD;
        }
        // 3. eb
        for(int i = 0; i <= r % 320; ++i) {
            res += bucket[eb][i];
            res %= MOD;
        }
    }
    return res;
}
int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%lld", &bucket[i / 320][i % 320]);
        bucketSum[i / 320] += bucket[i / 320][i % 320];
        bucketSum[i / 320] %= MOD;
    }
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int cmd; scanf("%d", &cmd);
        if (cmd != 4) {
            int x, y, v;
            scanf("%d %d %d", &x, &y, &v);
            updateRange(x, y, v, cmd);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", getRange(l, r));
        }
    }

    return 0;
}