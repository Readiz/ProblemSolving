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
struct Edge {
    int capa;
    int flow;
    int cost;
    int next;
    Edge* back;
};
Edge* pre[803];
vector<Edge*> adj[803];

int getempid(int i) {
    return i;
}
int getjobid(int j) {
    return j + 400;
}
void connect(int i, int j, int cost, int amount) {
    Edge* forward = new Edge({amount, 0, cost, j});
    Edge* backward = new Edge({0, 0, -cost, i});
    forward->back = backward;
    backward->back = forward;
    adj[i].push_back(forward);
    adj[j].push_back(backward);
}

int dist[803];
int inQ[803];

constexpr int S = 0;
constexpr int T = 801;
constexpr int INF = 987654321;

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) {
        int jobnum; scanf("%d", &jobnum);
        for(int cnt = 0; cnt < jobnum; ++cnt) {
            int jobid, cost; scanf("%d %d", &jobid, &cost);
            connect(getempid(i), getjobid(jobid), cost, 1);
        }
    }

    for(int i = 1; i <= N; ++i) {
        connect(S, getempid(i), 0, 1);
    }
    for(int i = 1; i <= M; ++i) {
        connect(getjobid(i), T, 0, 1);
    }

    int overallAmount = 0;
    int overallCost = 0;
    while(true) {
        fill(pre, pre+803, (Edge*)0);
        fill(dist, dist+803, INF);
        fill(inQ, inQ+803, 0);
        
        queue<int> q; q.push(S);
        inQ[S] = 1;
        dist[S] = 0;

        while(q.size()) {
            int cur = q.front(); q.pop();
            inQ[cur] = 0;

            for(auto& e: adj[cur]) {
                int residual = e->capa - e->flow;
                int ndist = dist[cur] + e->cost;
                if (ndist < dist[e->next] && residual > 0) {
                    pre[e->next] = e;
                    dist[e->next] = ndist;
                    if (inQ[e->next] == 0) {
                        inQ[e->next] = 1;
                        q.push(e->next);
                    }
                }
            }
        }
        if(dist[T] == INF) break; // 더이상 거리가 업데이트 되지 않으면 종료
        for(int p = T; p != S; p = pre[p]->back->next) {
            pre[p]->flow += 1; // 이분매칭이므로 항상 1임
            pre[p]->back->flow -= 1;
            overallCost += pre[p]->cost; // 이분매칭으로 추가로 곱할게 없음
        }
        overallAmount += 1;
    }

    printf("%d\n%d\n", overallAmount, overallCost);

    return 0;
}