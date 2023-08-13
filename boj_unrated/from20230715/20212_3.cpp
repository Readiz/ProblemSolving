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
    ll v;
    ll lazy;
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

// c에 [s, e] 만큼을 propogate 시킨다.
void push(Node* c, int s, int e) {
    if (c == 0) return;
    if (c->lazy == 0) return; // propogate 할 값 없음
    c->v += c->lazy * (e - s + 1);

    // leaf가 아니라면, lazy를 아래로 내린다.
    if (s != e) {
        if (c->l == 0) c->l = newNode();
        if (c->r == 0) c->r = newNode();

        c->l->lazy += c->lazy;
        c->r->lazy += c->lazy;
    }

    c->lazy = 0;
}


// s, e : 현재 보는 구간
// l, r : 쿼리 구간
void updateRange(Node* c, int s, int e, int l, int r, ll diff) {
    // lazy segtrees는 연산 전에 항상 push 한다.
    push(c, s, e);

    if (s > e || e < l || s > r) return; // 구간 미포함할 경우도 return
    // 구간을 모두 포함하는 경우 return
    if (l <= s && e <= r) {
        c->lazy += diff;
        push(c, s, e);
        return;
    }

    int m = s + ((e - s) >> 1);
    if (c->l == 0) c->l = newNode();
    if (c->r == 0) c->r = newNode();

    // 아래 구간이 leaf라면 sum이 업데이트 되었을 것
    updateRange(c->l, s, m, l, r, diff);
    updateRange(c->r, m + 1, e, l, r, diff);
    c->v = c->l->v + c->r->v;
}

ll getRange(Node* c, int s, int e, int l, int r) {
    if (c == 0) return 0;
    if (s > e || e < l || s > r) return 0; // 구간 미포함할 경우도 return
    push(c, s, e); // lazy propogate 먼저 시작!
    if (l <= s && e <= r) return c->v;
    int m = s + ((e - s) >> 1);
    return getRange(c->l, s, m, l, r) + getRange(c->r, m+1, e, l, r);
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