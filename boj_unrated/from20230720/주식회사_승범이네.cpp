#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int gN;
struct Node {
    int parent;
    // 트리를 펴자.. 오일러 경로 테크닉.
    // i번쨰 노드에 진입 / 나갈떄의 index
    int in, out;
    vector<int> childs;
} n[100'010];

struct Fenwick {
    ll d[100'010];
    
    void update(int idx, ll val) {
        for(; idx <= gN; idx += idx & -idx) {
            d[idx] += val;
        }
    }
    ll get(int idx) {
        ll res = 0;
        for(; idx > 0; idx -= idx & -idx) {
            res += d[idx];
        }
        return res;
    }
} f;

int gidx = 0;
void dfs(int idx) {
    ++gidx;
    n[idx].in = gidx;
    for(auto& item:n[idx].childs) {
        dfs(item);
    }
    n[idx].out = gidx;
}

int main() {
    int M; scanf("%d%d", &gN, &M);
    // 1번이 사장
    int p; scanf("%d", &p);
    for(int i = 2; i <= gN; ++i) {
        scanf("%d", &p);
        n[i].parent = p;
        n[p].childs.push_back(i);
    }

    dfs(1); // n, 모든 트리 탐색 됨

    // 쿼리 처리
    for(int i = 0; i < M; ++i) {
        char buf[2];
        scanf("%s", buf);
        if (buf[0] == '2') {
            int c; scanf("%d", &c);
            printf("%lld\n", f.get(n[c].in));
        } else {
            int a, b; scanf("%d %d", &a, &b);
            // printf("[d] query %d += %d\n", a, b);
            f.update(n[a].in, b);
            f.update(n[a].out + 1, -b);
        }
    }
    
    return 0;
}