#include <bits/stdc++.h>
using namespace std;

struct UF {
    int d[1001];
    void init() {
        for(int i = 1; i <= 1000; ++i) d[i] = i;
    }
    int parent(int v) {
        if (v == d[v]) return v;
        return d[v] = parent(d[v]);
    }
    void merge(int a, int b) {
        a = parent(a);
        b = parent(b);
        
        d[a] = b;
    }
} uf;

struct Item {
    int first, second;
    int dist;
    bool operator<(const struct Item& t) const {
        if (dist != t.dist) return dist > t.dist;
        return first < t.first;
    }
};

int main() {
    uf.init();

    int N, M; scanf("%d %d", &N, &M);
    priority_queue<Item> v;
    for(int i = 0; i < M; ++i) {
        int a, b, d; scanf("%d %d %d", &a, &b, &d);
        v.push({a, b, d});
    }

    long long ans = 0;

    while(v.size()) {
        auto cur = v.top(); v.pop();
        if (uf.parent(cur.first) != uf.parent(cur.second)) {
            uf.merge(cur.first, cur.second);
            ans += cur.dist;
        }
    }


    printf("%lld\n", ans);

    return 0;
}