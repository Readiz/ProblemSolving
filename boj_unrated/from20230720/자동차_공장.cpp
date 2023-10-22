#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int gN;
struct Node {
    int parent;
    int oVal;
    // 트리를 펴자.. 오일러 경로 테크닉.
    // i번쨰 노드에 진입 / 나갈떄의 index
    int in, out;
    vector<int> childs;
} n[500'010];

struct Fenwick {
    ll d[500'010];
    
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
    void set(int idx, ll val) {
        ll cur = get(idx);
        ll diff = val - cur;
        update(idx, diff);
    }
} f;

int gidx = 0;
void dfs(int idx) {
    ++gidx;
    n[idx].in = gidx;
    f.set(gidx, n[idx].oVal);
    for(auto& item:n[idx].childs) {
        dfs(item);
    }
    n[idx].out = gidx;
}

int main() {
    int M; scanf("%d%d", &gN, &M);
    // 1번이 사장
    ll tmp;
    scanf("%lld", &tmp);
    n[1].oVal = tmp;
    for(int i = 2; i <= gN; ++i) {
        int p; scanf("%lld %d", &tmp, &p);
        n[i].oVal = tmp; // original value
        n[i].parent = p;
        n[p].childs.push_back(i);
    }

    dfs(1); // nlogn, 모든 트리 탐색 됨
    // for(int i = 1; i <= gN; ++i) {
    //     printf("%3d", i);
    // }
    // printf("\n");
    // for(int i = 1; i <= gN; ++i) {
    //     printf("%3d", n[i].in);
    // }
    // printf("\n");
    // for(int i = 1; i <= gN; ++i) {
    //     printf("%3d", n[i].out);
    // }
    // printf("\n");
    // for(int i = 1; i <= gN; ++i) {
    //     printf("%3lld", f.get(n[i].in));
    // }
    // printf("\n");

    // 쿼리 처리
    for(int i = 0; i < M; ++i) {
        char buf[2];
        scanf("%s", buf);
        if (buf[0] == 'u') {
            int c; scanf("%d", &c);
            printf("%lld\n", f.get(n[c].in));
        } else {
            int a, b; scanf("%d %d", &a, &b);
            // printf("[d] query %d += %d\n", a, b);
            f.update(n[a].in + 1, b);
            f.update(n[a].out + 1, -b);
        }
    }
    
    return 0;
}