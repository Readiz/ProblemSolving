#include <bits/stdc++.h>
using namespace std;

struct Node {
    int p;
    int dist;
    int depth;
} n[40001];

struct Edge {
    int t;
    int weight;
};

vector<Edge> v[40001]; // v[s] = {t, weight}
int visited[40001];

int pseudo_rand() {
    static int seed = 55;
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i) {
        int s, t, w; scanf("%d %d %d", &s, &t, &w);
        v[s].push_back({t, w});
        v[t].push_back({s, w});
    }
    int root = (pseudo_rand() % N) + 1;
    visited[root] = 1;
    n[root].p = 0;
    n[root].depth = 0;
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int c = q.front(); q.pop();
        for(auto& t: v[c]) {
            if (visited[t.t]) continue;
            visited[t.t] = 1;
            n[t.t].p = c;
            n[t.t].dist = t.weight;
            n[t.t].depth = n[c].depth + 1;
            q.push(t.t);
        }
    }

    int M; scanf("%d", &M);
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        int overallDist = 0;
        if (n[a].depth < n[b].depth) a ^= b ^= a ^= b;
        while(n[a].depth > n[b].depth) {
            overallDist += n[a].dist;
            a = n[a].p;
        }
        while(a != b) {
            overallDist += n[a].dist;
            overallDist += n[b].dist;
            a = n[a].p;
            b = n[b].p;
        }
        printf("%d\n", overallDist);
    }

    return 0;
}