#include <stdio.h>

typedef long long ll;

struct F {
    ll d[200'002]; // 1-indexed
    ll sum;
    void update(int idx, int diff) {
        ++idx;
        for(; idx <= 200'001; idx += idx & -idx) {
            d[idx] += diff;
        }
        sum += diff;
    }
    ll getLeft(int idx) {
        ++idx;
        ll res = 0;
        for(; idx > 0; idx &= (idx - 1)) {
            res += d[idx];
        }
        return res;
    }
    ll getRight(int idx) {
        return sum - getLeft(idx);
    }
} f, fcnt;

constexpr ll MOD = 1000000007;
int main() {
    int N; scanf("%d", &N);

    ll ans = 1;
    for (int i = 0; i < N; ++i) {
        ll v; scanf("%lld", &v);
        if (i == 0) {
            // do nothing
        } else {
            v %= MOD;
            ll leftSum = f.getLeft(v);
            ll leftCnt = fcnt.getLeft(v);
            ll rightSum = f.sum - leftSum;
            ll rightCnt = fcnt.sum - leftCnt;
            ll localans = (leftCnt * v) % MOD;
            localans += rightSum - leftSum;
            localans %= MOD;
            localans -= (rightCnt * v);
            localans %= MOD;
            if (localans < 0) localans += MOD;
            ans *= localans;
            ans %= MOD;
        }
        f.update(v, v);
        fcnt.update(v, 1);
    }
    printf("%lld\n", ans);

    return 0;
}