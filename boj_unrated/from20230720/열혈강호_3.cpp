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

int N, M, K;

constexpr int S = 0;
constexpr int D1 = 3002;
constexpr int D2 = 3003;
constexpr int T = 3001;
int capa[3004][3004];
int flow[3004][3004];
int pre[3004];
vector<int> adj[3004];
int main() {
    scanf("%d %d %d", &N, &M, &K);
    capa[S][D1] = N;
    capa[S][D2] = K;
    adj[S].push_back(D1);
    adj[D1].push_back(S);
    adj[S].push_back(D2);
    adj[D2].push_back(S);
    for(int w = 2001; w <= 2000 + M; ++w) {
        capa[w][T] = 1;
        adj[w].push_back(T);
        adj[T].push_back(w);
    }
    for(int i = 1; i <= N; ++i) {
        int num; scanf("%d", &num);
        capa[D1][i] = 1;
        adj[D1].push_back(i);
        adj[i].push_back(D1);
        capa[D2][i+1000] = 1;
        adj[D2].push_back(i+1000);
        adj[i+1000].push_back(D2);
        for(int k = 0; k < num; ++k) {
            int w; scanf("%d", &w);
            w += 2000;
            capa[i][w] = 1;
            adj[i].push_back(w);
            adj[w].push_back(i);
            capa[i+1000][w] = 1;
            adj[i+1000].push_back(w);
            adj[w].push_back(i+1000);
        }
    }
    int ans = 0;
    while(true) {
        fill(pre, pre+3004, -1);
        queue<int> q;
        q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            for(auto& t: adj[cur]) {
                int residual = capa[cur][t] - flow[cur][t];
                if (residual > 0 && pre[t] == -1) {
                    pre[t] = cur;
                    if (t == T) break;
                    q.push(t);
                }
            }
            if (pre[T] != -1) break;
        }
        if (pre[T] == -1) break; // no augpath

        for(int p = T; p != S; p = pre[p]) {
            flow[pre[p]][p] += 1;
            flow[p][pre[p]] -= 1;
        }
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}