#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int A[100'001];
struct F {
    ll f[100'001];
    
    void update(int idx, int v) {
        for(; idx <= 100000; idx += idx & -idx) {
            f[idx] += v;
        }
    }
    ll get(int idx) {
        ll r = 0;
        for(; idx > 0; idx -= idx & -idx) {
            r += f[idx];
        }
        return r;
    }

} f;

struct D { // 1번 명령 저장
    int p, v;
} d[100'001];

struct Q {
    int d, l, r, n;
    bool operator<(const struct Q& t) const {
        if (d != t.d) return d < t.d;
        return n < t.n;
    }
} q[100'000]; // d까지 적용 되었을 때 Q

ll ans[100'000];

int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        int tmp; scanf("%d", &tmp);
        f.update(i, tmp);
        A[i] = tmp;
    }

    scanf("%d", &N);
    int dp = 1; int qp = 0;
    int a, b, c;
    for(int i = 0; i < N; ++i) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d %d", &a, &b);
            d[dp++] = D{a, b};
        } else {
            scanf("%d %d %d", &a, &b, &c);
            q[qp] = Q{a, b, c, qp};
            qp++;
        }
    }
    sort(q, q + qp);
    int dc = 0;
    for(int i = 0; i < qp; ++i) {
        int c = q[i].d;
        while (dc < c) {
            ++dc;
            f.update(d[dc].p, d[dc].v - A[d[dc].p]);
            A[d[dc].p] = d[dc].v;
        }
        ans[q[i].n] = f.get(q[i].r) - f.get(q[i].l - 1);
    }

    for(int i = 0; i < qp; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}