#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A[100001];
ll cnt[1'000'001];
struct Q {
    int l, r, n;
    bool operator<(const struct Q& t) const {
        if (r / 320 != t.r / 320) return r / 320 < t.r / 320;
        return l < t.l;
    }
} q[100000];
ll ans[100000];

ll add(int idx) {
    ll diff = 0;
    diff -= cnt[A[idx]] * cnt[A[idx]] * A[idx];
    cnt[A[idx]]++;
    diff += cnt[A[idx]] * cnt[A[idx]] * A[idx];
    return diff;
}
ll erase(int idx) {
    ll diff = 0;
    diff -= cnt[A[idx]] * cnt[A[idx]] * A[idx];
    cnt[A[idx]]--;
    diff += cnt[A[idx]] * cnt[A[idx]] * A[idx];
    return diff;
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    for(int i = 0; i < M; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        q[i] = Q{l, r, i};
    }
    sort(q, q + M);

    int l = q[0].l; int r = q[0].r;
    ll s = 0;
    for (int i = l; i <= r; ++i) {
        s -= cnt[A[i]] * cnt[A[i]] * A[i];
        ++cnt[A[i]];
        s += cnt[A[i]] * cnt[A[i]] * A[i];
    }
    ans[q[0].n] = s;
    for(int i = 1; i < M; ++i) {
        int cl = q[i].l; int cr = q[i].r;
        while(cl < l) s += add(--l);
        while(r < cr) s += add(++r);
        while(cl > l) s += erase(l++);
        while(r > cr) s += erase(r--);
        ans[q[i].n] = s;
    }
    for(int i = 0; i < M; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}


// 3은 2개, 1은 4개. Ks가 개수
// 2 * 2 * 3 / 4 * 4 * 1 = 16 + 12 = 28   -> 숫자개수 * 숫자개수 * 숫자
