# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

enum cmd {
    SUM = 1,
    PRODUCT = 2,
    OVERRITE = 3
};

constexpr int BMASK = 255;
ll bucket[400][256];
ll bucketSum[400];
pair<int, int> bucketLazy[400][50000];
int bucketLazySz[400];

constexpr unsigned int MOD = 1'000'000'007;
constexpr ull IMOD = 0xFFFFFFFFFFFFFFFF / MOD + 1;
inline ll reduce(ll n) {
    ull x = ull((__uint128_t(n) * IMOD) >> 64);
    unsigned int r = n - x * MOD;
    return MOD <= r ? r + MOD : r;
}
// #define reduce(x) ((x)%MOD)

inline void handleLazy(int b) {
    for(register int j = 0; j < bucketLazySz[b]; ++j) {
        auto& item = bucketLazy[b][j];
        auto& mb = bucket[b];
        int& v = item.second;
        if (item.first == SUM) {
            for(register int i = 0; i < 256; ++i) {
                mb[i] += v;
                if (mb[i] > MOD) mb[i] -= MOD;
            }
        } else if (item.first == PRODUCT) {
            for(register int i = 0; i < 256; ++i) {
                mb[i] = reduce(mb[i] * v);
            }
        } else {
            for(register int i = 0; i < 256; ++i) {
                mb[i] = v;
            }
        }
    }
    bucketLazySz[b] = 0;
}

inline void updateRange1(int l, int r, ll v) {
    --l; --r;
    int sb = l >> 8;
    int eb = r >> 8;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            bucketSum[sb] += v;
            if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
            bucket[sb][i & BMASK] += v;
            if (bucket[sb][i & BMASK] > MOD) bucket[sb][i & BMASK] -= MOD;
        }
    } else {
        // 1. sb
        if ((l&BMASK) != 0) {
            for(register int i = (l & BMASK); i < 256; ++i) {
                bucketSum[sb] += v;
                if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
                bucket[sb][i] += v;
                if (bucket[sb][i] > MOD) bucket[sb][i] -= MOD;
            }
        }
        // 2. lazy
        for(register int i = sb + ((l&BMASK) != 0); i < eb; ++i) {
            bucketLazy[i][bucketLazySz[i]++] = {SUM, v};
            bucketSum[i] = reduce(bucketSum[i] + v * 256);
        }
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            bucketSum[eb] += v;
            if (bucketSum[eb] > MOD) bucketSum[eb] -= MOD;
            bucket[eb][i] += v;
            if (bucket[eb][i] > MOD) bucket[eb][i] -= MOD;
        }
    }
}
inline void updateRange2(int l, int r, ll v) {
    --l; --r;
    int sb = l >> 8;
    int eb = r >> 8;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            bucketSum[sb] = reduce(bucketSum[sb] + bucket[sb][i & BMASK] * (v - 1));
            bucket[sb][i & BMASK] = reduce(bucket[sb][i & BMASK] * v);
        }
    } else {
        // 1. sb
        if ((l&BMASK) != 0) {
            for(register int i = (l & BMASK); i < 256; ++i) {
                bucketSum[sb] = reduce(bucketSum[sb] + bucket[sb][i] * (v - 1));
                bucket[sb][i] = reduce(bucket[sb][i] * v);
            }
        }
        // 2. lazy
        for(register int i = sb + ((l&BMASK) != 0); i < eb; ++i) {
            bucketLazy[i][bucketLazySz[i]++] = {PRODUCT, v};
            bucketSum[i] = reduce(bucketSum[i] * v);
        }
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            bucketSum[eb] = reduce(bucketSum[eb] + bucket[eb][i] * (v - 1));
            bucket[eb][i] = reduce(bucket[eb][i] * v);
        }
    }
}
inline void updateRange3(int l, int r, ll v) {
    --l; --r;
    int sb = l >> 8;
    int eb = r >> 8;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            ll diff = v - bucket[sb][i & BMASK];
            if (diff < 0) diff += MOD;
            bucketSum[sb] += diff;
            if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
            bucket[sb][i & BMASK] = v;
        }
    } else {
        // 1. sb
        if ((l&BMASK) != 0) {
            for(register int i = (l & BMASK); i < 256; ++i) {
                ll diff = v - bucket[sb][i];
                if (diff < 0) diff += MOD;
                bucketSum[sb] += diff;
                if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
                bucket[sb][i] = v;
            }
        }
        // 2. lazy
        for(register int i = sb + ((l&BMASK) != 0); i < eb; ++i) {
            bucketLazySz[i] = 0;
            bucketLazy[i][bucketLazySz[i]++] = {OVERRITE, v};
            bucketSum[i] = reduce(v * 256);
        }
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            ll diff = v - bucket[eb][i];
            if (diff < 0) diff += MOD;
            bucketSum[eb] += diff;
            if (bucketSum[eb] > MOD) bucketSum[eb] -= MOD;
            bucket[eb][i] = v;
        }
    }
}

inline ll getRange(int l, int r) {
    --l, --r;

    int sb = l >> 8;
    int eb = r >> 8;
    ll res = 0;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            res += bucket[sb][i & BMASK];
        }
        res = reduce(res);
    } else {
        // 1. sb
        for(register int i = (l & BMASK); i < 256; ++i) {
            res += bucket[sb][i];
        }
        res = reduce(res);
        // 2. lazy
        for(register int i = sb + 1; i < eb; ++i) {
            res += bucketSum[i];
        }
        res = reduce(res);
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            res += bucket[eb][i];
        }
        res = reduce(res);
    }
    return res;
}

int main() {
    int N, x, y, v, cmd;
    scanf("%d", &N);
    for(register int i = 0; i < N; ++i) {
        scanf("%d", &bucket[i >> 8][i & BMASK]);
        bucketSum[i >> 8] += bucket[i >> 8][i & BMASK];
        bucketSum[i >> 8] %= MOD;
    }
    scanf("%d", &N);
    for(register int i = 0; i < N; ++i) {
        scanf("%d %d %d", &cmd, &x, &y);
        if (cmd != 4) {
            scanf("%d", &v);
            switch (cmd) {
                case 1:
                updateRange1(x, y, v);
                break;
                case 2:
                updateRange2(x, y, v);
                break;
                case 3:
                updateRange3(x, y, v);
                break;
            }
        } else {
            if (x==y) {
                --x; x >>= 8;
                handleLazy(x);
                --y; y &= BMASK;
                printf("%lld\n", bucket[x][y]);
            } else {
                printf("%lld\n", getRange(x,y));
            }
        }
    }
    return 0;
}