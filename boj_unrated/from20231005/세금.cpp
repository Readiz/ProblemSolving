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

struct PQItem {
    int dist;
    int idx;
    int cnt;

    bool operator<(const PQItem& t) const {
        if (dist != t.dist) return dist > t.dist;
        return idx < t.idx;
    }
};

// ax + b -> a를 이어진 도로 수로 두고, b가 초기 비용이라 두면 됨. x는 처음에 0..
ll x;
struct Path {
    ll a, b;
    bool operator<(const Path& t) const {
        return a * x + b < t.a * x + t.b;
    }
};

int dist[1001][1001];
vector<Path> paths;

void dp() {
    priority_queue<PQItem> pq;
    memset(dist, 0x3A, sizeof(int) * 1001 * 1001);
    
    dist[S][0] = 0;

    // 벨만포드 DP
    // 1. 사이클이 있어도 상관없다.
    // 2. 최단거리는 최대 N번 이동 내에 존재한다. (M 수와 관계 X)
    for(int cnt = 1; cnt <= N; ++cnt) {
        for(int s = 1; s <= N; ++s) {
            if (dist[s][cnt - 1] == 0x3A3A3A3A) continue;
            if (s == D) continue;
            for(auto& e: adj[s]) {
                int t = e.t;
                int w = e.weight;
                if (dist[t][cnt] > dist[s][cnt - 1] + w) {
                    dist[t][cnt] = dist[s][cnt - 1] + w;
                }
            }
        }
    }
    for(int i = 0; i <= N; ++i) {
        if (dist[D][i] != 0x3A3A3A3A) {
            paths.push_back({i, dist[D][i]});
        }
    }
}

void solve() {
    scanf("%d %d %d %d %d", &N, &M, &K, &S, &D);
    FOR(i,0,M) {
        int a, b, w; scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back(Edge{b, w});
        adj[b].push_back(Edge{a, w});
    }
    dp();

    // for(auto& item: paths) {
    //     _D("%lld * x + %lld\n", item.a, item.b);
    // }
    x = 0;
    sort(paths.begin(), paths.end());
    printf("%lld\n", paths[0].b);

    FOR(i,0,K) {
        int p; scanf("%d", &p);
        x += p;
        sort(paths.begin(), paths.end());
        printf("%lld\n", paths[0].a * x + paths[0].b);
    }
}

int main() {
    solve();
    return 0;
}