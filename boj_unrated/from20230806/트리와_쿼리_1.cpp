#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

typedef long long ll;
typedef unsigned long long ull;

int gN;

// Bottom-Up SegTree
struct SegTree {
    int d[200'020]; // *2
    void build() {
        for(int i = gN - 1; i > 0; --i) {
            d[i] = max(d[i<<1], d[i<<1|1]);
        }
    }
    void update(int idx, int v) {
        idx += gN - 1;
        d[idx] = v;
        for(idx >>= 1; idx > 0; idx >>= 1) {
            d[idx] = max(d[idx<<1], d[idx<<1|1]);
        }
    }
    int query(int l, int r) {
        _D("[seg] query: %d ~ %d\n", l, r);
        l += gN - 1, r += gN - 1;
        int ret = 0;
        for(; l <= r; l>>=1, r>>=1) {
            if ( l & 1) ret = max(ret, d[l++]);
            if (~r & 1) ret = max(ret, d[r--]);
        }
        return ret;
    }
} seg;

struct Edge {
    int t;
    int w;
    int eidx; // edge index
};

Edge edict[100'010];

struct Node {
    int parent;
    vector<Edge> childs;
    vector<Edge> edges; // 최초 input 받을 때

    int in, out, top;
    int depth;
    int size;
} n[100'010];

int visited[100'010];
void make_tree(int idx) {
    visited[idx] = 1;
    for(auto& item: n[idx].edges) {
        if (visited[item.t] == 0) {
            visited[item.t] = 1;
            edict[item.eidx] = item; // 양방향 edge 중 실제 사용된 edge (tree 만들 때)
            n[idx].childs.push_back(item);
            n[item.t].parent = idx;
            n[item.t].depth = n[idx].depth + 1;
            make_tree(item.t); // 재귀적으로 트리를 구성한다.
        }
    }
}

// HLD 만들기
// Top을 활용하는 것이 일종의 HLD. 
// top에 해당하는 녀석이 오면 parent로 감
// 그러면, 다음 chain으로 접근하는 효과임
void dfs1(int idx) {
    n[idx].size = 1; // size 초기화
    for(int i = 0; i < n[idx].childs.size(); ++i) {
        auto& cur = n[idx].childs[i];
        dfs1(cur.t); // 재귀적으로 size를 업데이트
        n[idx].size += n[cur.t].size;
        if (i == 0) continue;

        // 이 시점에서 이미 자식들의 size는 모두 업데이트가 되어 있으므로 비교 가능
        auto& firstItem = n[idx].childs[0]; // 무조건 존재함 (loop에 들어왔으니)
        if (n[cur.t].size > n[firstItem.t].size) {
            // 사이즈가 큰 쪽을 0번으로 유지한다.
            // swap(cur, firstItem);
            Edge tmp = cur;
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
        n[cur.t].top = (i == 0) ? n[idx].top : cur.t; // 0번째: heavy-light 간선. 부모의 top으로 업데이트
        dfs2(cur.t);
    }
    n[idx].out = gidx;
}

int main() {
    scanf("%d", &gN);
    
    for(int i = 1; i < gN; ++i) { // 트리 간선: N-1개
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        n[u].edges.push_back({v, w, i});
        n[v].edges.push_back({u, w, i});
    }
    
    // 가상의 root를 1로 하는 tree 생성.
    n[1].top = 1; // 맨 첫번째.. 간선. top 설정 필요
    make_tree(1); // O(N)
    dfs1(1);
    dfs2(1);

    for(int i = 1; i < gN; ++i) {
        _D("[e] -> %d / %d\n", edict[i].t, edict[i].w);
        seg.d[n[edict[i].t].in + gN - 1] = edict[i].w; // 들어가는 edge의 weight를 저장
    }
    seg.build();
    for(int i = 1; i <= gN; ++i) {
        _D("[%d] depth: %d / in(%d) ~ out(%d) / parent: %d / top: %d\n",
         i, n[i].depth, n[i].in, n[i].out, n[i].parent, n[i].top);
    }

    _D("[seg] ---\n");
    for(int i = 1; i < 2*gN; ++i) {
        _D("%3d", seg.d[i]);
    }
    _D("\n---\n");
    int M; scanf("%d", &M);
    for(int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if (a == 1) { // 비용 변경
            auto& e = edict[b];
            seg.update(n[e.t].in, c);
        } else {
            // hld query.. lca 떠올리자.
            int l = b, r = c;
            int ret = 0;
            // 같은 chain이 될 때까지 반복
            while(n[l].top != n[r].top) {
                if (n[n[l].top].depth < n[n[r].top].depth) l ^= r ^= l ^= r;
                _D("[d] l: %d / r: %d\n", l, r);
                int start = n[l].top; // 왼쪽 chain (depth 더 깊은)의 시작으로 간다
                _D("   start top: %d / %d\n", start, n[r].top);
                ret = max(ret, seg.query(n[start].in, n[l].in));
                _D("   ret: %d\n", ret);
                l = n[start].parent; // 언젠간 chain이 같아진다.
            }
            // 같은 chain이 되었다.
            if (n[l].depth > n[r].depth) l ^= r ^= l ^= r;
            // depth 낮은게 더 낮은 vidx를 가짐
            ret = max(ret, seg.query(n[l].in + 1, n[r].in)); // +1: root의 진입 간선은 고려하지 않는다.
            printf("%d\n", ret);
        }
    }
    _D("[seg] ---\n");
    for(int i = 1; i < 2*gN; ++i) {
        _D("%3d", seg.d[i]);
    }
    _D("\n---\n");
    return 0;
}