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

int N, A, B;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited, finished, isCycle;
set<int> cycleNodes;
void denoteCycle(int node, int next) {
    isCycle[node] = true;
    cycleNodes.insert(node);
    if (node == next)
        return;
    
    denoteCycle(parent[node], next);
}

void dfs(int node, int from)
{
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); ++i) {
        int next = adj[node][i];
        if (next == from) continue;
        if (!visited[next]) {
            parent[next] = node;
            dfs(next, node);
        }
        else if (finished[next] == false) {
            denoteCycle(node, next);
        }
    }
    finished[node] = true;
}
int vcnt[200001];
int tvcnt;
pair<int,int> bfs(int s) {
    ++tvcnt;
    queue<pair<int,int>> q;
    q.push({s, 0});
    int len = 0;
    while(q.size()) {
        auto cur = q.front(); q.pop();
        int c = cur.first;
        if (vcnt[c] == tvcnt) continue;
        vcnt[c] = tvcnt;
        if (cycleNodes.find(c) != cycleNodes.end()) return cur;
        for(auto& t: adj[c]) {
            q.push({t, cur.second + 1});
        }
    }
    return {0, -1};
}
int bfs2(int s, int t) {
    ++tvcnt;
    queue<pair<int,int>> q;
    q.push({s, 0});
    int len = 0;
    while(q.size()) {
        auto cur = q.front(); q.pop();
        int c = cur.first;
        if (vcnt[c] == tvcnt) continue;
        vcnt[c] = tvcnt;
        if (cur.first == t) return cur.second;
        for(auto& te: adj[c]) {
            q.push({te, cur.second + 1});
        }
    }
    return -1;
}
void solve() {
    scanf("%d%d%d", &N, &A, &B);
    adj.clear();
    adj.resize(N+1);
    visited.clear(); visited.resize(N+1); 
    finished.clear(); finished.resize(N+1); 
    parent.clear(); parent.resize(N+1);
    isCycle.clear(); isCycle.resize(N+1);
    for(int i = 1; i <= N; ++i) {
        adj[i].clear();
        visited[i] = false;
        parent[i] = 0;
        finished[i] = false;
        isCycle[i] = false;
    }
    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (A == B) {
        printf("NO\n");
        return;
    }
    if (N == 3) {
        printf("YES\n");
        return;
    }
    cycleNodes.clear();
    dfs(1, 0);
    // for(auto& item: cycleNodes) {
    //     printf("%d ", item);
    // }
    // printf("\n");
    // 제일 빨리 시이클에 도달하는 경로 for A, B
    pair<int,int> BInfo = bfs(B);
    // printf("[d] B: to %d, len: %d\n", BInfo.first, BInfo.second);
    if (BInfo.second == 0) {
        printf("YES\n");
        return;
    }
    int lenA = bfs2(A, BInfo.first);
    // printf("for A, len: %d\n", lenA);
    if (lenA <= BInfo.second) {
        printf("NO\n");
        return;
    } else {
        printf("YES\n");
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}