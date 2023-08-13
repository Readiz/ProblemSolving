#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];

struct Node {
    int pidx;
} n[100001];

int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    n[1].pidx = -1;

    while(q.size()) {
        int c = q.front(); q.pop();
        for(int t: adj[c]) {
            if (n[t].pidx != 0) continue;
            n[t].pidx = c;
            q.push(t);
        }
    }
    for(int i = 2; i <= N; ++i) {
        printf("%d\n", n[i].pidx);
    }

    return 0;
}