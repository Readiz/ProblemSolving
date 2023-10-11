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

// ax + b -> a를 이어진 도로 수로 두고, b가 초기 비용이라 두면 됨. x는 처음에 0..
ll x;
struct Path {
    ll a, b;
    bool operator<(const Path& t) const {
        return a * x + b < t.a * x + t.b;
    }
};

int N, M, K, S, D;
vector<Edge> adj[1001];
int visited[1001];
vector<Path> paths;
void dfs(int cur, int cost, int cnt) {
    if (cur == D) {
        paths.push_back({cnt, cost});
        return;
    }

    for(auto& edge: adj[cur]) {
        if (visited[edge.t]) continue;
        visited[edge.t] = true;
        dfs(edge.t, cost + edge.weight, cnt + 1);
        visited[edge.t] = false;
    }
}
void solve() {
    scanf("%d %d %d %d %d", &N, &M, &K, &S, &D);
    FOR(i,0,M) {
        int a, b, w; scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back(Edge{b, w});
        adj[b].push_back(Edge{a, w});
    }

    visited[S] = true;
    dfs(S, 0, 0);

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