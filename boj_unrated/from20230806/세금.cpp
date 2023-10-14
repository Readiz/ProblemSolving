#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

struct Edge {
    int t;
    int weight;
};

int N, M, K, S, D;
vector<Edge> adj[1001];
int visited[1001];
int visitedCnt;

ll dijkstra(int base) {
    priority_queue<pii> pq;
    int dist[1001] = {0, };
    memset(dist, 0x3A, sizeof(int) * 1001);
    
    dist[S] = 0;
    pq.push({0, S});
    ++visitedCnt;

    while(pq.size() > 0) {
        auto item = pq.top(); pq.pop();
        int cur = item.second;
        if (cur == D) break;

        if (visited[cur] == visitedCnt) continue;
        visited[cur] = visitedCnt;

        for(auto& e: adj[cur]) {
            if (dist[e.t] > dist[cur] + e.weight + base) {
                dist[e.t] = dist[cur] + e.weight + base;
                pq.push({-dist[e.t], e.t});
            }
        }
    }
    return dist[D];
}

void solve() {
    scanf("%d %d %d %d %d", &N, &M, &K, &S, &D);
    FOR(i,0,M) {
        int a, b, w; scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back(Edge{b, w});
        adj[b].push_back(Edge{a, w});
    }

    int base = 0;
    printf("%lld\n", dijkstra(base));

    FOR(i,0,K) {
        int p; scanf("%d", &p);
        base += p;
        printf("%lld\n", dijkstra(base));
    }
}

int main() {
    solve();
    return 0;
}