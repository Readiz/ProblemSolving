#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

typedef long long ll;
typedef unsigned long long ull;

constexpr int INF = 300000;
int gN;

struct Data {
    int in;
    int idx;
    bool operator<(const Data& t) const {
        // 진입 정점번호가 작은 녀석을 리턴한다.
        if (in == 0) return false; // 0인 경우는 반대로 뒤집기..
        if (t.in == 0) return true;
        return in < t.in;
    }
};

// Bottom-Up SegTree
struct SegTree {
    Data d[200'020]; // *2
    void build() {
        for(int i = gN - 1; i > 0; --i) {
            d[i] = min(d[i<<1], d[i<<1|1]);
        }
    }
    void update(int idx, Data v) {
        idx += gN - 1;
        d[idx] = v;
        for(idx >>= 1; idx > 0; idx >>= 1) {
            d[idx] = min(d[idx<<1], d[idx<<1|1]);
        }
    }
    Data query(int l, int r) {
        _D("[seg] query: %d ~ %d\n", l, r);
        l += gN - 1, r += gN - 1;
        Data ret = {0, 0};
        for(; l <= r; l>>=1, r>>=1) {
            if ( l & 1) ret = min(ret, d[l++]);
            if (~r & 1) ret = min(ret, d[r--]);
        }
        return ret;
    }
} seg;

struct Node {
    int parent;
    vector<int> edges;
    vector<int> childs;

    int in, out, top;
    int depth;
    int size;
} n[100'010];

int visited[100'010];
// 1번 정ㅈ머이 root인 트리구조로 바꿔준다.
void make_tree(int idx) {
    visited[idx] = 1;
    for(auto& item: n[idx].edges) {
        if (visited[item] == 0) {
            visited[item] = 1;
            n[idx].childs.push_back(item);
            n[item].parent = idx;
            make_tree(item);
        }
    }
}

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
    scanf("%d", &gN);
    
    for(int i = 2; i <= gN; ++i) { // 트리 간선: N-1개
        int u, v; scanf("%d%d", &u, &v);
        n[u].edges.push_back(v);
        n[v].edges.push_back(u);
    }
    
    // 가상의 root를 1로 하는 tree 생성.
    n[1].top = 1; // 맨 첫번째.. 간선. top 설정 필요
    make_tree(1);
    dfs1(1);
    dfs2(1);
    // for(int i = 1; i <= gN; ++i) {
    //     seg.d[i + gN - 1] = MINF;
    // }
    // for(int i = 2; i <= gN; ++i) {
    //     seg.d[n[i].in + gN - 1] = 1;
    // }
    // seg.build();
    for(int i = 1; i <= gN; ++i) {
        _D("[%d] depth: %d / in(%d) ~ out(%d) / parent: %d / top: %d\n",
         i, n[i].depth, n[i].in, n[i].out, n[i].parent, n[i].top);
    }

    _D("[seg] ---\n");
    for(int i = 1; i < 2*gN; ++i) {
        _D("%3d", seg.d[i].in);
    }
    _D("\n---\n");
    int Q; scanf("%d", &Q);
    for(int i = 0; i < Q; ++i) {
        int cmd, a; scanf("%d%d", &cmd, &a);
        if (cmd == 1) {
            Data tmp = seg.query(n[a].in, n[a].in);
            if (tmp.in == 0) {
                seg.update(n[a].in, {n[a].in, a});
            } else {
                seg.update(n[a].in, {0, 0});
            }
            _D("[seg] ---\n");
            for(int i = 1; i < 2*gN; ++i) {
                _D("%3d", seg.d[i].in);
            }
            _D("\n---\n");
        } else {
            // hld query.. lca 떠올리자.
            int l = a;
            Data ret = {0, 0};
            // 루트를 포함하는 chain이 될 떄까지 반복
            while(n[l].top != 1) {
                int start = n[l].top;
                Data tmp = seg.query(n[start].in, n[l].in);
                if (tmp.in != 0) ret = tmp;
                l = n[start].parent; // 언젠간 chain이 같아진다.
            }
            // 여기까지 왔으면 root chain 임
            Data tmp = seg.query(1, n[l].in);
            if (tmp.in != 0) ret = tmp;
            _D("  rret: %d, %d\n", ret.in, ret.idx);
            if (ret.in == 0) printf("-1\n");
            else printf("%d\n", ret.idx);
        }
    }
    return 0;
}