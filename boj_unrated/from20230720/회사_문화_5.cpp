#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;

int N, M;
// Lazy Seg
struct SegTree {
    int tree[400'010];
    int delay[400'010]; // delay: 1 or -1, 1: 켜기, -1: 끄기

    // init은 필요 없다.
    // void init(int node, int s, int e);

    void push(int node, int s, int e) {
        if (delay[node] != 0) {
            if (delay[node] == 1) {
                tree[node] = (e - s + 1) * 1;
            } else {
                tree[node] = 0;
            }
            // leaf가 아니면
            if (s != e) {
                delay[node * 2] = delay[node];
                delay[node * 2 + 1] = delay[node];
            }
            delay[node] = 0;
        }
    }

    void updateRange(int node, int s, int e, int l, int r, int v) {
        // 항상 push 먼저
        push(node, s, e);
        if (l > e || r < s) return; // 구간이 하나도 안겹칠 때
        if (l <= s && e <= r) { // 담당하는 구간으로 들어왔을 때
            if (v == 1) {
                tree[node] = (e - s + 1) * 1;
            } else {
                tree[node] = 0;
            }
            // leaf가 아니면
            if (s != e) {
                delay[node * 2] = v;
                delay[node * 2 + 1] = v;
            }
            return;
        }
        // 구간이 안겹치면 더 내려간다.
        updateRange(node, s, (s+e)/2, l, r, v);
        updateRange(node, (s+e)+1, e, l, r, v);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }


} seg;

struct Node {
    int p;
    int sz;
    int in, out;
    int head; // 현재 chain의 우두머리
    vector<int> children;
} n[100'010];

// 목표: sz 계산해서 children[0]에 제일 무거운 녀석 놓기
void dfs1(int i) {
    n[i].sz = 1;
    for(auto& j: n[i].children) {
        dfs1(j); n[i].sz += n[j].sz;
        auto& first = n[i].children[0];
        if (j != first && n[j].sz > n[first].sz) first ^= j ^= first ^= j;
    }
}
// 목표: 변형된 자식 순서로 in, out, head 채우기
int gIdx;
void dfs2(int i) {
    n[i].in = ++gIdx;
    for(auto& j: n[i].children) {
        auto& first = n[i].children[0];
        n[j].head = (j == first) ? n[i].head : j; // j == first면 heavy-light에 속함
        dfs2(j);
    }
    n[i].out = gIdx;
}
int main() {
    scanf("%d", &N);
    int tmp; scanf("%d", &tmp);
    for(int i = 2; i <= N; ++i) {
        int j; scanf("%d", &j);
        n[i].p = j;
        n[j].children.push_back(i);
    }

    // make hld
    n[1].head = 1;
    dfs1(1);
    dfs2(1);

    for(int i = 1; i <= N; ++i) {
        _D("[d] n[%d] head: %d / in: %d / out: %d / sz: %d\n", i, n[i].head, n[i].in, n[i].out, n[i].sz);
    }
    
    int M; scanf("%d", &M);
    for(int q = 0; q < M; ++q) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            int i, w; scanf("%d %d", &i, &w);
            if (isReverse == false) {
                f.updateRange(n[i].in, n[i].out, w);
            } else {
                // hld travel...
                while(n[i].head != 1) {
                    f.updateRange(n[n[i].head].in, n[i].in, w);
                    i = n[n[i].head].p; // 다음 chain 이동
                }
                // i는 top chain
                f.updateRange(1, n[i].in, w);
            }
        } else if (cmd == 2) {
            int v; scanf("%d", &v);
            printf("%lld\n", f.get(n[v].in));
        } else {
            isReverse = !isReverse;
        }
    }

    return 0;
}