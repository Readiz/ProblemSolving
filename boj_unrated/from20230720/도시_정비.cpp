#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;

vector<int> gph[1'000'001];

int gN;
// Bottom-Up SegTree
struct SegTree {
    int d[2'000'002];

    void update(int idx, int v) {
        idx += gN - 1;
        d[idx] = v;
        for(idx >>= 1; idx > 0; idx >>= 1) {
            d[idx] = max(d[idx<<1], d[idx<<1|1]);
        }
    }
    int query(int l, int r) {
        l += gN - 1; r += gN - 1;
        int res = 0;
        for(; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, d[l++]);
            if (~r & 1) res = max(res, d[r--]);
        }
        return res;
    }
} seg;

struct N {
    int v;
    int p;
    int in, out;
    vector<int> children;
} n[1'000'001];

int visited[1'000'001];
int gIdx;
void make_tree(int idx) {
    visited[idx] = 1;
    n[idx].in = ++gIdx;
    for(auto& item: gph[idx]) {
        if (visited[item]) continue;
        visited[item] = 1;
        
        n[idx].children.push_back(item);
        n[item].p = idx;
        make_tree(item);
    }
    n[idx].out = gIdx;
}
int main() {
    scanf("%d", &gN);
    
    for(int i = 1; i <= gN; ++i)
        scanf("%d", &n[i].v);
    
    for(int i = 1; i < gN; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        gph[u].push_back(v);
        gph[v].push_back(u);
    }
    make_tree(478539234 % gN + 1);
    // make_tree(1);
    for(int i = 1; i <= gN; ++i) {
        seg.update(n[i].in, n[i].v);
        _D("[d] %d: in: %d / out: %d / v: %d\n", i, n[i].in, n[i].out, n[i].v);
    }

    // 다 끊어본다.
    int gMax = 0;
    for(int i = 1; i <= gN; ++i) {
        int leftEnd = n[i].in - 1;
        int rightStart = n[i].out + 1;
        int pVal = max(seg.query(1, leftEnd), seg.query(rightStart, gN));
        int cValSum = 0;
        for(auto& item: n[i].children) {
            cValSum += seg.query(n[item].in, n[item].out);
        }
        gMax = max(gMax, pVal + cValSum);
        _D("remove %d... val: %d + %d\n", i, pVal, cValSum);
    }
    printf("%d\n", gMax);
    return 0;
}