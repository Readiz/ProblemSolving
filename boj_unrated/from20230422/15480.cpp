#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_DEPTH = 30;

struct Node {
    int parent[30];
    int depth;

    void init(int p);
};
Node n[100001];

vector<int> adj[100001];
bool visited[100001];

void Node::init(int p) {
    depth = n[p].depth + 1;
    // 2^k = 2^(k-1) + 2^(k-1)
    parent[0] = p;
    for(int i = 1; i < MAX_DEPTH; ++i) {
        parent[i] = n[parent[i-1]].parent[i-1];
    }
}

int solve(int a, int b) {
    int da = n[a].depth;
    int db = n[b].depth;
    if (da < db) a^=b^=a^=b, da^=db^=da^=db;
    int diff = da - db;
    for(int i = 0; i < MAX_DEPTH; ++i) {
        if (diff & (1 << i)) {
            a = n[a].parent[i];
        }
    }
    if (a == b) return a;
    for(int i = MAX_DEPTH - 1; i >= 0; --i) {
        int na = n[a].parent[i];
        int nb = n[b].parent[i];
        if (na != nb) {
            a = na;
            b = nb;
        }
    }
    return n[a].parent[0];
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> next;
    next.push(1);
    visited[1] = true;
    while(next.size()) {
        int p = next.front(); next.pop();
        for(auto& c: adj[p]) {
            if (visited[c]) continue;
            visited[c] = true;
            n[c].init(p);
            next.push(c);
        }
    }

    int M;
    scanf("%d", &M);
    for(int q = 0; q < M; ++q) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int v1 = solve(a, b);
        int v2 = solve(b, c);
        int v3 = solve(c, a);
        int ans = v1;
        if (n[v2].depth > n[v1].depth) ans = v2;
        if (n[v3].depth > n[ans].depth) ans = v3;
        printf("%d\n", ans);
    }

    return 0;
}