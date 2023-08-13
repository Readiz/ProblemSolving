#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int s, e;
    int weight;
    bool operator<(const Edge& t) const {
        return weight > t.weight;
    }
};

struct UnionFind {
    int parents[100'001];
    UnionFind() {
        for(int i = 0; i <= 100000; ++i) {
            parents[i] = i;
        }
    }
    int findRoot(int v) {
        if (v == parents[v]) return v;
        return parents[v] = findRoot(parents[v]);
    }
    void merge(int a, int b) {
        a = findRoot(a); b = findRoot(b);
        if (a == b) return;
        parents[b] = a;
    }
} uf;

int main() {
    int N, M; scanf("%d %d", &N, &M);
    priority_queue<Edge> PQ;
    for(int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        PQ.push({a,b,c});
    }
    long long ans = 0;
    priority_queue<int> weights;
    for(;PQ.size();) {
        Edge c = PQ.top(); PQ.pop();
        if (uf.findRoot(c.s) != uf.findRoot(c.e)) {
            // no cycle
            uf.merge(c.s, c.e);
            ans += c.weight;
            weights.push(c.weight);
        }
    }
    printf("%lld\n", ans - weights.top());
}