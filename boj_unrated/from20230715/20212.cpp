// Dynamic Seg Tree 연습
#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

typedef long long ll;

struct Node {
    Node *l, *r;
    int s, e;
    int v;
} n[4'000'000]; // 충분히 할당
int nid;

Node* newNode() {
    return &n[nid++];
}

ll ans[50000];

struct Q {
    int type, i, j, k, d;
    bool operator<(const Q& t) const {
        if (k != t.k) {
            return k < t.k;
        } else {
            return type < t.type;
        }
    }
} q[50000];


// s, e : 현재 보는 구간
// l, r : 쿼리 구간
void updateRange(Node* c, int s, int e, int l, int r, int diff) {
    // 구간을 모두 포함하는 경우 return
    c->s = s;
    c->e = e;
    if (s > e || e < l || s > r) return; // 구간 미포함할 경우도 return
    if (l <= s && e <= r) {
        c->v += diff;
        _D("[UPD][%3d] %d ~ %d\n", c-n, s, e);
        _D("  + %d = %d\n", diff, c->v);
        return;
    }

    // 아래 case에 대해서 재귀적으로 내려간다.
    if (c->l == 0) {
        c->l = newNode();
    }
    if (c->r == 0) {
        c->r = newNode();
    }
    int m = s + ((e - s) >> 1);
    updateRange(c->l, s, m, l, r, diff);
    updateRange(c->r, m + 1, e, l, r, diff);
}

ll getRange(Node* c, int s, int e, int l, int r) {
    _D("[GET] %d ~ %d\n", l, r);
    ll res = 0;
    for(int i = 0; i < nid; ++i) {
        if (n[i].e < l || n[i].s > r) continue;
        if (n[i].s <= l) {
            if (r <= n[i].e) {
                _D("Checking %d ~ %d...\n", n[i].s, n[i].e);
                _D("Added! + %d, %d ~ %d\n", n[i].v, l, r);
                res += n[i].v * (r - l + 1);
            } else {
                _D("Checking %d ~ %d...\n", n[i].s, n[i].e);
                _D("Added! + %d, %d ~ %d\n", n[i].v, l, n[i].e);
                res += n[i].v * (n[i].e - l + 1);
            }
        } else {
            if (r <= n[i].e) {
                _D("Checking %d ~ %d...\n", n[i].s, n[i].e);
                _D("Added! + %d, %d ~ %d\n", n[i].v, n[i].s, r);
                res += n[i].v * (r - n[i].s + 1);
            } else {
                _D("Checking %d ~ %d...\n", n[i].s, n[i].e);
                _D("Added! + %d, %d ~ %d\n", n[i].v, n[i].s, n[i].e);
                res += n[i].v * (n[i].e - n[i].s + 1);
            }
        }
    }
    _D("RES: %lld\n", res);
    return res;
}
ll getRange2(Node* c, int s, int e, int l, int r) {
    // 구간을 모두 포함하는 경우 return
    _D("[GET] %d ~ %d\n", s, e);
    if (c == 0) return 0;
    if (s > e || e < l || s > r) return 0; // 구간 미포함할 경우도 return
    if (l <= s && e <= r) {
        _D("  * %d\n", c->v);
        return (ll)(e - s + 1) * c->v;
    }

    int m = s + (e - s) >> 1;
    return getRange2(c->l, s, m, l, r) + getRange2(c->r, m + 1, e, l, r);
}

int main() {
    int N; scanf("%d", &N);
    int kidx = 0;
    int aidx = 0;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", &q[i].type, &q[i].i, &q[i].j, &q[i].k);
        if (q[i].type == 1) {
            q[i].d = q[i].k;
            q[i].k = ++kidx;
        } else {
            q[i].d = aidx++;
        }
    }
    sort(q, q+N);

    Node* root = newNode();
    for(int i = 0; i < N; ++i) {
        // printf("%d %d %d %d\n", q[i].type, q[i].i, q[i].j, q[i].k);
        if (q[i].type == 1) {
            updateRange(root, 1, 1000000000, q[i].i, q[i].j, q[i].d);
        } else {
            ans[q[i].d] = getRange(root, 1, 1000000000, q[i].i, q[i].j);
        }
    }

    for(int i = 0; i < aidx; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}