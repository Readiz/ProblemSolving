#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif
int N;
struct SegNode {
    int val;
    int lazy;
    SegNode* l;
    SegNode* r;
};

SegNode* newNode() {
    SegNode* n = new SegNode;
    n->val = 0;
    n->lazy = 0;
    n->l = 0;
    n->r = 0;
    return n;
}

struct LazySeg {
    SegNode* root;

    void init() {
        root = newNode();
    }

    void push(SegNode* x, int s, int e) {
        if (x == 0 || x->lazy == 0) return;
        x->val += x->lazy;
        if (s != e) {
            if (x->l == 0) x->l = newNode();
            if (x->r == 0) x->r = newNode();
            x->l->lazy += x->lazy;
            x->r->lazy += x->lazy;
        }
        x->lazy = 0;
    }

    void updateRange(SegNode* x, int s, int e, int l, int r, int v) {
        push(x, s, e);
        if (x == 0) return;
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            x->lazy += v;
            push(x, s, e);
            return;
        }
        int m = (s+e)>>1;
        if (x->l == 0) x->l = newNode();
        if (x->r == 0) x->r = newNode();
        updateRange(x->l,s,m,l,r,v);
        updateRange(x->r,m+1,e,l,r,v);
        x->val = max(x->l->val, x->r->val);
    }
    void updateRange(int l, int r, int v) {
        updateRange(root, 1, N, l, r, v);
    }
    
    int getRange(SegNode* x, int s, int e, int l, int r) {
        push(x, s, e);
        if (x == 0) return 0;
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return x->val;
        int m = (s+e)>>1;
        return max(getRange(x->l,s,m,l,r), getRange(x->r,m+1,e,l,r));
    }
    int getRange() {
        return getRange(root, 1, N, 1, N);
    }
} lazySeg;

char buf[3];
void solve() {
    lazySeg.init();
    N = 1'000'000'010;
    int Q; scanf("%d", &Q);
    int cnt = 0;
    FOR(i,0,Q) {
        int l, r; scanf("%s %d %d", buf, &l, &r);
        if (buf[0] == '+') {
            lazySeg.updateRange(l, r, 1);
            ++cnt;
        } else {
            lazySeg.updateRange(l, r, -1);
            --cnt;
        }
        int cur = lazySeg.getRange();
        // _D("CUR: %d / cnt: %d\n", cur, cnt);
        if (cur == cnt) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}

int main() {
    solve();
    return 0;
}