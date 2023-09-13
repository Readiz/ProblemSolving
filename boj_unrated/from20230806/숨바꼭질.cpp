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

int N, M;
vector<int> adj[20001];
int dist[20001];
int inQ[20001];
int visited[200001];
int q[1000000];
int qr, qf;
int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    inQ[1] = 1;
    qr = qf = 0;
    q[qr++] = 1;
    visited[1] = 1;
    while(qf != qr) {
        auto& cur = q[qf++];
        inQ[cur] = 0;

        for(auto& t: adj[cur]) {
            if (visited[t]) continue;
            visited[t] = 1;
            if (dist[t] < dist[cur] + 1) {
                dist[t] = dist[cur] + 1;
                if (inQ[t] == 0) {
                    q[qr++] = t;
                }
            }
        }
    }

    int maxDist = 0;
    int maxIdx = -1;
    for(int i = 2; i <= N; ++i) {
        if (maxDist < dist[i]) {
            maxDist = dist[i];
            maxIdx = i;
        }
    }
    int ans3 = 0;
    for(int i = 2; i <= N; ++i) {
        if (maxDist == dist[i]) ans3++;
    }

    printf("%d %d %d\n", maxIdx, maxDist, ans3);
    return 0;
}