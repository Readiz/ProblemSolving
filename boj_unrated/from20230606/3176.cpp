#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

struct Edge {
    int t;
    int dist;
};

vector<Edge> edges[100001]; // edges[s] = {t, dist};
int visited[100001];

struct Node {
    int p[18];
    int mindist[18];
    int maxdist[18];
    int depth;
} n[100001];

int pseudo_rand() {
    static int seed = 55;
    seed = 214013 * seed + 2531011;
    return (seed >> 16) & 0x7FFF;
}
int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i < N; ++i) {
        int s, t, dist;
        scanf("%d %d %d", &s, &t, &dist);
        edges[s].push_back({t, dist});
        edges[t].push_back({s, dist});
    }

    int root = 1; //(pseudo_rand() % N) + 1;
    n[root].depth = 0;
    for(int k = 0; k <= 17; ++k) {
        n[root].mindist[k] = 987654321;
        n[root].maxdist[k] = -1;
    }
    queue<int> q;
    q.push(root);
    visited[root] = 1;

    while(q.size()) {
        int s = q.front(); q.pop();
        for(auto& t: edges[s]) {
            if (visited[t.t]) continue;
            visited[t.t] = 1;
            n[t.t].p[0] = s;
            n[t.t].mindist[0] = t.dist;
            n[t.t].maxdist[0] = t.dist;
            for(int k = 1; k <= 17; ++k) {
                // 2^k = 2^k-1 + 2^k-1
                n[t.t].p[k] = n[n[t.t].p[k-1]].p[k-1];
                n[t.t].mindist[k] = min(n[t.t].mindist[k-1], n[n[t.t].p[k-1]].mindist[k-1]);
                n[t.t].maxdist[k] = max(n[t.t].maxdist[k-1], n[n[t.t].p[k-1]].maxdist[k-1]);
            }
            n[t.t].depth = n[s].depth + 1;
            q.push(t.t);
        }
    }

    // Query start
    int M; scanf("%d", &M);
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b); // a != b
        if (n[a].depth < n[b].depth) a ^= b ^= a ^= b;
        // 깊이를 맞춰준다.
        int diffdepth = n[a].depth - n[b].depth;
        _D("DIFF: %d\n", diffdepth);
        int minDist = 987654321;
        int maxDist = -1;
        for(int k = 0; k <= 17; ++k) {
            if (diffdepth & (1 << k)) {
                minDist = min(minDist, n[a].mindist[k]);
                maxDist = max(maxDist, n[a].maxdist[k]);
                a = n[a].p[k];
            }
        }
        _D("CUR MIN: %d / MAX: %d\n", minDist, maxDist);
        for(int k = 17; k >= 0; --k) {
            int na = n[a].p[k];
            int nb = n[b].p[k];
            if (na != nb) {
                minDist = min(minDist, n[a].mindist[k]);
                minDist = min(minDist, n[b].mindist[k]);
                maxDist = max(maxDist, n[a].maxdist[k]);
                maxDist = max(maxDist, n[b].maxdist[k]);
                _D("CUR MIN: %d / MAX: %d\n", minDist, maxDist);
                a = na;
                b = nb;
            }
        }
        while(a != b) {
            minDist = min(minDist, n[a].mindist[0]);
            minDist = min(minDist, n[b].mindist[0]);
            maxDist = max(maxDist, n[a].maxdist[0]);
            maxDist = max(maxDist, n[b].maxdist[0]);
            _D("A MIN : %d / MAX: %d\n", n[a].mindist[0], n[a].maxdist[0]);
            _D("B MIN : %d / MAX: %d\n", n[b].mindist[0], n[b].maxdist[0]);
            a = n[a].p[0];
            b = n[b].p[0];
        }
        printf("%d %d\n", minDist, maxDist);
    }

    return 0;
}