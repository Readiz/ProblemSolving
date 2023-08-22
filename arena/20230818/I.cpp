#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[2001];
int cnt, cntMin;
int visited[2001];
int visitedCnt;
void dfs(int v) {
    if (visited[v] == visitedCnt) return;
    visited[v] = visitedCnt;

    int cur = 0;
    for(auto& e: adj[v]) {
        if (visited[e] == visitedCnt) continue;
        ++cur;
        dfs(e);
    }
    if (cur > cnt) cnt = cur;
}
int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cntMin = 987654321;

    for(int i = 1; i <= N; ++i) {
        ++visitedCnt;
        cnt = 0;
        dfs(i);
        if (cnt < cntMin) cntMin = cnt;
    }

    printf("%d\n", cntMin);
    return 0;
}