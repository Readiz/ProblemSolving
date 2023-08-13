#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif


int A[300'001];
int cnt[10'001];

constexpr int BSIZE = 550; // sqrt(300000)

struct Q {
    int l, r, n;
    bool operator<(const struct Q& t) const {
        if (r / BSIZE == t.r / BSIZE) return l < t.l;
        return r / BSIZE < t.r / BSIZE;
    }
} q[10'000];

int ans[10'000];

int main() {
    int N, C; scanf("%d %d", &N, &C);
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        q[i] = Q{a, b, i};
    }
    sort(q, q + N);

    int l = q[0].l; int r = q[0].r;
    for(int i = l; i <= r; ++i) {
        cnt[A[i]]++;
    }
    for(int c = 1; c <= C; ++c) {
        if (cnt[c] > (r - l + 1) / 2) {
            ans[q[0].n] = c;
            break;
        }
    }

    for(int i = 1; i < N; ++i) {
        int cl = q[i].l; int cr = q[i].r;
        _D("Checking query %d, %d ~ %d / %d\n", i, cl, cr, q[i].n);
        while(cl < l) cnt[A[--l]]++;
        while(l < cl) cnt[A[l++]]--;
        while(cr < r) cnt[A[r--]]--;
        while(r < cr) cnt[A[++r]]++;

        for(int c = 1; c <= C; ++c) {
            _D("color %d: %d\n", c, cnt[c]);
            if (cnt[c] > (r - l + 1) / 2) {
                ans[q[i].n] = c;
                break;
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        if (ans[i] == 0) {
            printf("no\n");
        } else {
            printf("yes %d\n", ans[i]);
        }
    }


    return 0;
}