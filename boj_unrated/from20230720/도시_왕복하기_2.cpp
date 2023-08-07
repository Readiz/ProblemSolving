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

int N, P;
constexpr int S = 1;
constexpr int T = 2;
constexpr int INF = 999999;

int capa[801][801];
int flow[801][801];
int pre[801];
vector<int> adj[801];
int main() {
    scanf("%d %d", &N, &P);
    int ans = 0;

    // 1. Graph Modeling
    for(int i = 3; i <= N; ++i) {
        // dummy vertex - 정점 분할
        adj[i].push_back(i+400);
        adj[i+400].push_back(i);
        capa[i][i+400] = 1;
    }

    for(int i = 0; i < P; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        adj[a+400].push_back(b);
        adj[b].push_back(a+400);
        capa[a+400][b] = INF;
        adj[b+400].push_back(a);
        adj[a].push_back(b+400);
        capa[b+400][a] = INF;
    }

    // 2. Maxflow
    while(true) {
        fill(pre, pre+801, -1);

        queue<int> q;
        q.push(S+400);
        while(q.size() > 0) {
            int cur = q.front(); q.pop();
            
            for(auto& t: adj[cur]) {
                int residual = capa[cur][t] - flow[cur][t];
                if (pre[t] == -1 && residual > 0) {
                    pre[t] = cur;
                    if (t == T) break; // 증가경로 찾았다!
                    q.push(t);
                }
            }
            if (pre[T] != -1) break; // complete path!
        }

        if (pre[T] == -1) break; // No augpath
        for(int p = T; p != S+400; p = pre[p]) {
            flow[pre[p]][p] += 1;
            flow[p][pre[p]] -= 1;
        }
        ans+=1;
    }

    printf("%d\n", ans);
    return 0;
}