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
#define X first
#define Y second

int N, M;

struct Node {
    int depth;
    int inCnt;
    vector<int> edges;
} n[100010];

int dfs(int i) {
    if (n[i].edges.size() == 0) {
        // leaf
        return 0;
    }
    if (n[i].depth != 0) return n[i].depth;

    for(auto& t: n[i].edges) {
        int res = dfs(t);
        n[i].depth = max(n[i].depth, res + 1);
    }
    return n[i].depth;
}

void solve() {
    scanf("%d %d", &N, &M);
    // Simple Back and Forth
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        n[a].edges.push_back(b);
        ++n[b].inCnt; // 특정 정점으로 들어가는 간선 수 (indegree)
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        if (n[i].inCnt == 0) {
            ans = max(ans, dfs(i));
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}