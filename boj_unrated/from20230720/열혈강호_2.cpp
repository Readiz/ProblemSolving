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
constexpr int D = 2002;
constexpr int T = 2001;
int capa[2003][2003];
int flow[2003][2003];
int pre[2003];
vector<int> adj[2003];
int main() {
    scanf("%d %d", &N, &M);
    capa[S][D] = N + N;
    adj[S].push_back(D);
    adj[D].push_back(S);
    for(int w = 1001; w <= 1000 + M; ++w) {
        capa[w][T] = 1;
        adj[w].push_back(T);
        adj[T].push_back(w);
    }
    for(int i = 1; i <= N; ++i) {
        int num; scanf("%d", &num);
        capa[D][i] = 2;
        adj[D].push_back(i);
        adj[i].push_back(D);
        for(int k = 0; k < num; ++k) {
            int w; scanf("%d", &w);
            w += 1000;
            capa[i][w] = 1;
            adj[i].push_back(w);
            adj[w].push_back(i);
        }
    }
    int ans = 0;
    while(true) {
        fill(pre, pre+2003, -1);
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