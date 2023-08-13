#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

constexpr int BSIZE = 320;
int A[100'001];
int cnt[1'000'000];

struct Q {
    int l;
    int r;
    int num;
    bool operator<(const struct Q& t) const {
        if (t.r / BSIZE == r / BSIZE) return l < t.l;
        return r / BSIZE < t.r / BSIZE;
    }
} q[100'000];
int ans[100'000];

int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i+1]);
    }

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int l, r; scanf("%d %d", &l, &r);
        q[i] = {l, r, i};
    }
    sort(q, q + N);

    int ll = q[0].l; int rr = q[0].r;
    int diff = 0;
    for(int i = ll; i <= rr; ++i) {
        if (cnt[A[i]] == 0) {
            cnt[A[i]] = 1;
            ++diff;
        }
    }
    ans[q[0].num] = diff;

    for(int i = 1; i < N; ++i) {
        int cl = q[i].l; int cr = q[i].r;
        while (ll < cl) {
            --cnt[A[ll]];
            if (cnt[A[ll]] == 0) {
                _D("A[%d] = %d deleted.\n", ll, A[ll]);
                --diff;
            }
            ++ll;
        }
        while (ll > cl) {
            if (cnt[A[ll]] == 0) {
                _D("A[%d] = %d added.\n", ll, A[ll]);
                cnt[A[ll]] = 1;
                ++diff;
            }
            --ll;
        }
        while (cr < rr) {
            if (cnt[A[rr]] == 1) {
                _D("A[%d] = %d deleted.\n", rr, A[rr]);
                cnt[A[rr]] = 0;
                --diff;
            }
            --rr;
        }
        while (cr > rr) {
            if (cnt[A[rr]] == 0) {
                _D("A[%d] = %d added.\n", rr, A[rr]);
                cnt[A[rr]] = 1;
                ++diff;
            }
            ++rr;
        }
        ans[q[i].num] = diff;
    }
    for(int i = 0; i < N; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}