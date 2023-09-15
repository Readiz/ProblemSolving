#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int main() {
    int N, M, S, E;
    scanf("%d%d%d%d", &N, &M, &S, &E);
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int block = 1; block <= N; ++block) {
        if (block == S || block == E) {
            printf("-1\n");
            continue;
        }
        int dist[1001];
        int inQ[1001] = {0, };
        int visited[1001] = {0, };
        memset(dist, 0x3A, sizeof(int) * 1001);
        dist[S] = 1;
        inQ[S] = 1;
        queue<int> q; q.push(S);

        while(q.size()) {
            auto v = q.front(); q.pop();
            inQ[v] = 0;
            
            for(auto& t: adj[v]) {
                if (t == block) continue;
                if (inQ[t]) continue;
                if (visited[t]) continue;
                visited[t] = true;
                int newDist = dist[v] + 1;
                if (newDist < dist[t]) {
                    q.push(t);
                    dist[t] = newDist;
                }
            }
        }

        if (dist[E] != 0x3A3A3A3A) {
            printf("%d\n", dist[E]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}