#include <bits/stdc++.h>
using namespace std;

int visited[32001];
vector<int> edges[100001];
void dfs(int v) {
    if (visited[v]) return;
    visited[v] = 1;

    for(int t: edges[v]) {
        dfs(t);
    }
    printf("%d ", v);
}
int main() {
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[b].push_back(a);
    }
    for(int i = 1; i <= N; ++i) {
        dfs(i);
    }
    printf("\n");
    return 0;
}