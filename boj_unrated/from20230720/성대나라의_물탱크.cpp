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

struct Fenwick {
    ll data[200'010];
    
    void update(int idx, ll diff) {
        for(; idx <= gN; idx += idx & -idx) {
            data[idx] += diff;
        }
    }
    ll get(int idx) {
        ll res = 0;
        for(; idx > 0; idx -= idx & -idx) {
            res += data[idx];
        }
        return res;
    }
} f;

struct Node {
    int parent;
    vector<int> edges;
    vector<int> childs;

    int in, out, top;
    int depth;
    int size;
} n[200'010];

int visited[200'010];
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
    int C; scanf("%d %d", &gN, &C); // C: 수도
    
    for(int i = 2; i <= gN; ++i) { // 트리 간선: N-1개
        int u, v; scanf("%d%d", &u, &v);
        n[u].edges.push_back(v);
        n[v].edges.push_back(u);
    }
    
    // 가상의 root를 1로 하는 tree 생성.
    n[C].top = C; // 맨 첫번째.. 간선. top 설정 필요
    n[C].depth = 1;
    make_tree(C);
    dfs1(C);
    dfs2(C);
    for(int i = 1; i <= gN; ++i) {
        _D("[%d] depth: %d / in(%d) ~ out(%d) / parent: %d / top: %d\n",
         i, n[i].depth, n[i].in, n[i].out, n[i].parent, n[i].top);
    }

    int Q; scanf("%d", &Q);
    for(int i = 0; i < Q; ++i) {
        int cmd, a; scanf("%d%d", &cmd, &a);
        if (cmd == 1) {
            // 물채우기
            // hld query.. lca 떠올리자.
            int l = a;
            // 루트를 포함하는 chain이 될 떄까지 반복
            while(n[l].top != C) {
                int start = n[l].top;
                // 현재 chain 업데이트
                f.update(n[start].in, 1);
                f.update(n[l].in + 1, -1);
                l = n[start].parent; // 언젠간 chain이 같아진다.
            }
            // 여기까지 왔으면 root chain 임
            f.update(n[C].in, 1);
            f.update(n[l].in + 1, -1);
        } else {
            // 출력하기
            ll res = f.get(n[a].in) * (ll)n[a].depth;
            printf("%lld\n", res);
        }
    }
    return 0;
}