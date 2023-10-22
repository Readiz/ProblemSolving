#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
struct SegNode {
    int val;
    int lazy;
};

struct LazySeg {
    SegNode tree[400'010];

    void push(int x, int s, int e) {
        if (tree[x].lazy == 0) return;
        tree[x].val = (e - s + 1) - tree[x].val;
        if (s != e) {
            tree[x<<1].lazy ^= tree[x].lazy;
            tree[x<<1|1].lazy ^= tree[x].lazy;
        }
        tree[x].lazy = 0;
    }

    void updateRange(int x, int s, int e, int l, int r, int v) {
        push(x, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[x].lazy ^= v;
            push(x, s, e);
            return;
        }
        int m = (s+e)>>1;
        updateRange(x<<1,s,m,l,r,v);
        updateRange(x<<1|1,m+1,e,l,r,v);
        tree[x].val = tree[x<<1].val + tree[x<<1|1].val;
    }
    void updateRange(int l, int r, int v) {
        updateRange(1, 1, N, l, r, v);
    }
    
    int getRange(int x, int s, int e, int l, int r) {
        push(x, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[x].val;
        int m = (s+e)>>1;
        return getRange(x<<1,s,m,l,r) + getRange(x<<1|1,m+1,e,l,r);
    }
    int getRange(int l, int r) {
        return getRange(1, 1, N, l, r);
    }
} lazySeg;

int main() {
    scanf("%d", &N);
    int Q; scanf("%d", &Q);
    for(int q = 0; q < Q; ++q) {
        int cmd, l, r; scanf("%d %d %d", &cmd, &l, &r);
        if (cmd == 0) {
            lazySeg.updateRange(l, r, 1);
        } else {
            printf("%d\n", lazySeg.getRange(l, r));
        }
    }
    return 0;
}