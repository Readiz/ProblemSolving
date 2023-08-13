#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> pdd;
struct Edge {
    int s, e;
    double weight;
    bool operator<(const Edge& t) const {
        return weight < t.weight;
    }
};

struct UnionFind {
    int parents[100];
    UnionFind() {
        for(int i = 0; i < 100; ++i) parents[i] = i;
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
    int N; scanf("%d", &N);
    vector<pdd> v;
    for(int i = 0; i < N; ++i) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        v.push_back({x, y});
    }
    vector<Edge> edges;
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v.size(); ++j) {
            if (i == j) continue;
            double dist = (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second);
            dist = sqrt(dist);
            edges.push_back({i, j, dist});
        }
    }
    sort(edges.begin(), edges.end());

    double distSum = 0;
    // 크루스칼
    for(auto& edge: edges) {
        if (uf.findRoot(edge.s) != uf.findRoot(edge.e)) {
            // 사이클 X, 포함
            uf.merge(edge.s, edge.e);
            distSum += edge.weight;
        }
    }
    
    printf("%lf\n", distSum);

    return 0;
}