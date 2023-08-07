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
int getempid(int i) {
    return i;
}
int getjobid(int i) {
    return i + 1000;
}
struct Edge {
    int capa;
    int flow;
    int next;
    Edge* back;
};
vector<Edge*> adj[2010];
Edge* pre[2010];
constexpr int S = 0;
constexpr int T = 2005;
constexpr int D = 2003;
constexpr int INF = 987654321;

void connect(int i, int j, int capa) {
    Edge* forward = new Edge({capa, 0, j});
    Edge* backward = new Edge({0, 0, i});
    forward->back = backward;
    backward->back = forward;
    adj[i].push_back(forward);
    adj[j].push_back(backward);
}

// S -> JOB -> T
// S -> D -> JOB -> T
int main() {
    scanf("%d %d %d", &N, &M, &K);

    connect(S, D, K);
    for(int i = 1; i <= N; ++i) {
        connect(S, getempid(i), 1);
        connect(D, getempid(i), K);
    }
    for(int i = 1; i <= M; ++i) {
        connect(getjobid(i), T, 1);
    }
    for(int i = 1; i <= N; ++i) {
        int cnt; scanf("%d", &cnt);
        for(int k = 0; k < cnt; ++k) {
            int j; scanf("%d", &j);
            connect(getempid(i), getjobid(j), 1);
        }
    }
    int ans = 0;
    while(true) {
        fill(pre, pre+2010, (Edge*)0);
        queue<int> q; q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            for(auto& e: adj[cur]) {
                int residual = e->capa - e->flow;
                if (residual > 0 && pre[e->next] == 0) {
                    pre[e->next] = e;
                    if (e->next == T) break;
                    q.push(e->next);
                }
            }
            if(pre[T] != 0) break;
        }
        if (pre[T] == 0) break; // no augpath
        for(int p = T; p != S; p = pre[p]->back->next) {
            pre[p]->flow += 1;
            pre[p]->back->flow -= 1;
        }
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}