#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

typedef long long ll;
typedef unsigned long long ull;

constexpr int MINF = -300000; // 최대 거리: 200000, 하나라도 MINF가 있으면 음수가 될 수 있도록...
int gN;

// Bottom-Up SegTree
struct SegTree {
    ll d[400'040]; // *2
    void build() {
        for(int i = gN - 1; i > 0; --i) {
            d[i] = d[i<<1] + d[i<<1|1];
        }
    }
    void update(int idx, ll v) {
        idx += gN - 1;
        d[idx] = v;
        for(idx >>= 1; idx > 0; idx >>= 1) {
            d[idx] = d[idx<<1] + d[idx<<1|1];
        }
    }
    ll query(int l, int r) {
        _D("[seg] query: %d ~ %d\n", l, r);
        l += gN - 1, r += gN - 1;
        ll ret = 0;
        for(; l <= r; l>>=1, r>>=1) {
            if ( l & 1) ret += d[l++];
            if (~r & 1) ret += d[r--];
        }
        return ret;
    }
} seg;

struct Node {
    int parent;
    vector<int> childs;

    int in, out, top;
    int depth;
    int size;
} n[200'010];

// HLD 만들기
// Top을 활용하는 것이 일종의 HLD. 
// top에 해당하는 녀석이 오면 parent로 감
// 그러면, 다음 chain으로 접근하는 효과임
void dfs1(int idx) {
    n[idx].size = 1; // size 초기화
    for(int i = 0; i < n[idx].childs.size(); ++i) {
        auto& cur = n[idx].childs[i];
        n[cur].depth = n[idx].depth + 1;
        dfs1(cur); // 재귀적으로 size를 업데이트
        n[idx].size += n[cur].size;
        if (i == 0) continue;

        // 이 시점에서 이미 자식들의 size는 모두 업데이트가 되어 있으므로 비교 가능
        auto& firstItem = n[idx].childs[0]; // 무조건 존재함 (loop에 들어왔으니)
        if (n[cur].size > n[firstItem].size) {
            // 사이즈가 큰 쪽을 0번으로 유지한다.
            auto tmp = cur;
            cur = firstItem;
            firstItem = tmp;
        }
    }
}

int gidx = 0;
void dfs2(int idx) {
    n[idx].in = ++gidx;
    for(int i = 0; i < n[idx].childs.size(); ++i) {
        auto& cur = n[idx].childs[i];
        // top[i] = i == g[v][0] ? top[v] : i;
        n[cur].top = (i == 0) ? n[idx].top : cur; // 0번째: heavy-light 간선. 부모의 top으로 업데이트
        dfs2(cur);
    }
    n[idx].out = gidx;
}

int main() {
    int Q; scanf("%d%d", &gN, &Q);
    
    for(int i = 2; i <= gN; ++i) { // 트리 간선: N-1개
        int p; scanf("%d", &p);
        n[p].childs.push_back(i);
        n[i].parent = p;
    }
    
    // 가상의 root를 1로 하는 tree 생성.
    n[1].top = 1; // 맨 첫번째.. 간선. top 설정 필요
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= gN; ++i) {
        seg.d[i + gN - 1] = MINF;
    }
    for(int i = 2; i <= gN; ++i) {
        seg.d[n[i].in + gN - 1] = 1;
    }
    seg.build();
    for(int i = 1; i <= gN; ++i) {
        _D("[%d] depth: %d / in(%d) ~ out(%d) / parent: %d / top: %d\n",
         i, n[i].depth, n[i].in, n[i].out, n[i].parent, n[i].top);
    }

    _D("[seg] ---\n");
    for(int i = 1; i < 2*gN; ++i) {
        if (seg.d[i] > 0) _D("%3d", seg.d[i]);
        else _D("  -");
    }
    _D("\n---\n");
    for(int i = 0; i < Q; ++i) {
        int b, c, d; scanf("%d%d%d", &b, &c, &d);
        // hld query.. lca 떠올리자.
        int l = b, r = c;
        ll ret = 0;
        // 같은 chain이 될 때까지 반복
        while(n[l].top != n[r].top) {
            if (n[n[l].top].depth < n[n[r].top].depth) l ^= r ^= l ^= r;
            _D("[d] l: %d / r: %d\n", l, r);
            int start = n[l].top; // 왼쪽 chain (depth 더 깊은)의 시작으로 간다
            _D("   start top: %d / %d\n", start, n[r].top);
            ret += seg.query(n[start].in, n[l].in);
            _D("   ret: %lld\n", ret);
            l = n[start].parent; // 언젠간 chain이 같아진다.
        }
        // 같은 chain이 되었다.
        if (n[l].depth > n[r].depth) l ^= r ^= l ^= r;
        // depth 낮은게 더 낮은 vidx를 가짐
        ret += seg.query(n[l].in + 1, n[r].in); // +1: root의 진입 간선은 고려하지 않는다.
        _D("  rret: %lld\n", ret);
        if (ret < 0) {
            printf("NO\n");
            if (d == 1) {
                seg.update(n[c].in, MINF);
            }
        } else {
            printf("YES\n");
            if (d == 1) {
                seg.update(n[b].in, MINF);
            }
        }
    }
    _D("[seg] ---\n");
    for(int i = 1; i < 2*gN; ++i) {
        if (seg.d[i] > 0) _D("%3d", seg.d[i]);
        else _D("  -");
    }
    _D("\n---\n");
    return 0;
}