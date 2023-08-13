#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int s, e;
    ll weight;
    
    bool operator<(const Edge& t) const{
        if (weight != t.weight) return weight > t.weight;
        if (s != t.s) return s < t.s;
        return e < t.e;
    }
};

struct UnionFind {
    int parents[100001];
    UnionFind() {
        for(int i = 0; i <= 100000; ++i) parents[i] = i;
    }
    int findRoot(int v) {
        if (v == parents[v]) return v;
        return parents[v] = findRoot(parents[v]);
    }
    void merge(int a, int b) {
        if (findRoot(a) == findRoot(b)) return;
        parents[findRoot(b)] = findRoot(a);
    }
} uf;

int main() {
    int V, E; scanf("%d %d", &V, &E);
    
    priority_queue<Edge> PQ;
    for(int i = 0; i < E; ++i) {
        int a, b; ll c;
        scanf("%d %d %lld", &a, &b, &c);
        PQ.push(Edge{a, b, c});
    }
    ll sum = 0;

    for(;PQ.size();) {
        Edge cur = PQ.top(); PQ.pop();

        if (uf.findRoot(cur.s) != uf.findRoot(cur.e)) {
            // Cycle이 없는 경우이므로 간선을 선택한다.
            uf.merge(cur.s, cur.e);
            sum += cur.weight;
        }
    }

    printf("%lld\n", sum);

    return 0;
}