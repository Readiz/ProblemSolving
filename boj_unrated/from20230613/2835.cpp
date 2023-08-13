#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct F {
    ll sum[24 * 60 * 60 + 2];
    void update(int idx, int v) {
        for(; idx <= 24 * 60 * 60 + 1; idx += idx & -idx) {
            sum[idx] += v;
        }
    }
    ll get(int idx) {
        ll r = 0;
        for(; idx > 0; idx -= idx & -idx) {
            r += sum[idx];
        }
        return r;
    }
} f;
ll cacheSum[24 * 60 * 60 + 2];

int ttoi(char buf[]) {
    int hh = (buf[0] - '0') * 10 + (buf[1] - '0');
    int mm = (buf[3] - '0') * 10 + (buf[4] - '0');
    int ss = (buf[6] - '0') * 10 + (buf[7] - '0');
    return hh * 60 * 60 + mm * 60 + ss + 1;
}
constexpr int day = 24 * 60 * 60 + 1;
constexpr int SQRT = 300;

struct Q {
    int l, r, n;
    bool operator<(const struct Q& t) const {
        if (r / SQRT == t.r / SQRT) return l < t.l;
        return r / SQRT < t.r / SQRT;
    }
} q[200'000];
ll ans[100'000];
ll ansRange[100'000];

int main() {
    char buf[10];
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%s", buf);
        int v1 = ttoi(buf);
        scanf("%s", buf);
        scanf("%s", buf);
        int v2 = ttoi(buf);
        if (v2 - v1 < 0) {
            f.update(v1, 1);
            f.update(1, 1);
            f.update(v2 + 1, -1);
        } else {
            f.update(v1, 1);
            f.update(v2 + 1, -1);
        }
    }

    for(int i = 1; i < day; ++i) {
        cacheSum[i] = f.get(i);
    }

    scanf("%d", &N);
    int p = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%s", buf);
        int v1 = ttoi(buf);
        scanf("%s", buf);
        scanf("%s", buf);
        int v2 = ttoi(buf);

        if (v2 - v1 < 0) {
            q[p++] = Q{v1, day - 1, i};
            q[p++] = Q{1, v2, i};
        } else {
            q[p++] = Q{v1, v2, i};
        }
    }
    sort(q, q + p);

    ll s = 0, l = q[0].l, r = q[0].r;
    for(int i = q[0].l; i <= q[0].r; ++i) {
        s += cacheSum[i];
    }
    ans[q[0].n] += s;
    ansRange[q[0].n] += r - l + 1;

    for(int i = 1; i < p; ++i) {
        int cl = q[i].l, cr = q[i].r;
        while(cl < l) s += cacheSum[--l];
        while(l < cl) s -= cacheSum[l++];
        while(cr < r) s -= cacheSum[r--];
        while(r < cr) s += cacheSum[++r];
        ans[q[i].n] += s;
        ansRange[q[i].n] += r - l + 1;
    }
    for(int i = 0; i < N; ++i) {
        if (ansRange[i] == 0) {
            printf("0.0000000000\n");
        } else {
            printf("%.10lf\n", (double)ans[i] / ansRange[i]);
        }
    }

    return 0;
}