#include <bits/stdc++.h>
using namespace std;

struct Node {
    int p;
    vector<int> childs;
    bool isEA;
} n[1'000'001];

vector<int> v[1'000'001]; // v[s] = t;
int visited[1'000'001];

int ans;
void dfs(int v) {
    if (visited[v] == 2) return;
    visited[v] = 2;

    // printf("DFS: %d\n", v);

    for(auto& t: n[v].childs) {
        dfs(t);
    }
    
    bool isAllEA = true;
    for(auto& t: n[v].childs) {
        if (n[t].isEA) continue;
        isAllEA = false;
    }

    if (isAllEA == false) {
        ++ans;
        n[v].isEA = true;
    }
}

int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i) {
        int s, t; scanf("%d %d", &s, &t);
        v[s].push_back(t);
        v[t].push_back(s);
    }
    int root = 1;
    visited[root] = 1;
    n[root].p = 0;
    queue<int> q;
    q.push(root);

    while (q.size()) {
        int c = q.front(); q.pop();
        for(auto& t: v[c]) {
            if (visited[t]) continue;
            visited[t] = 1;
            n[t].p = c;
            n[c].childs.push_back(t);
            q.push(t);
        }
    }

    dfs(root);

    printf("%d\n", ans);

    return 0;
}