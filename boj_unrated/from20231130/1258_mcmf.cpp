#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)

struct Edge {
    int t;
    int flow;
    int capa;
    int cost;
    int rev;

    int getResidual() {
        return capa - flow;
    }
};

int N;

const int MAX_V = 210;
vector<Edge> E[MAX_V];

int S, T;
const int INF = 987654321;
int cost[MAX_V][MAX_V];
int dist[MAX_V];
int pre[MAX_V];
int inQ[MAX_V];

int main() {
    scanf("%d", &N);

    FOR(i,1,N+1) FOR(j,1,N+1) {
        scanf("%d", &cost[i][j + 100]); // i 학생이 j문제 푸는데 걸리는 시간.
    }

    // Graph Modelling
    S = 208, T = 209;

    // 학생: 1 ~ 100
    // 문제: 101 ~ 200
    // 모든 유량은 1로 가능
    FOR(i,1,N+1) {
        E[S].push_back(Edge{i, 0, 1, 1, (int)E[i].size()});
        E[i].push_back(Edge{S, 0, 0, -1, (int)E[S].size() - 1});

        E[i+100].push_back(Edge{T, 0, 1, 1, (int)E[T].size()});
        E[T].push_back(Edge{i+100, 0, 0, -1, (int)E[i+100].size()-1});
    }

    FOR(i,1,N+1) FOR(j,101,N+101) {
        E[i].push_back(Edge{j, 0, 1, cost[i][j], (int)E[j].size()});
        E[j].push_back(Edge{i, 0, 0, -cost[i][j], (int)E[i].size()-1});
    }


    // min cost, max flow -> MCMF
    // 이거대로 계속 따라가면, flow를 최대로 유지하면서 cost가 제일 작은 flow가 구해진다.
    while(true) {
        fill(dist, dist + MAX_V, INF);
        fill(pre, pre + MAX_V, -1);
        fill(inQ, inQ + MAX_V, 0);
        
        dist[S] = 0;
        inQ[S] = 1;
        queue<int> q; q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(auto& e: E[cur]) {
                int newDist = dist[cur] + e.cost;
                if (e.getResidual() > 0 && newDist < dist[e.t]) {
                    dist[e.t] = newDist;
                    pre[e.t] = e.rev;
                    if (inQ[e.t] == 0) {
                        inQ[e.t] = 1;
                        q.push(e.t);
                    }
                }
            }
        }
        if (dist[T] == INF) break; // 거리가 업데이트 되지 않음 -> 최적임

        // 구해진 경로로 유량을 흘린다.
        // -> 어차피 1임
        for(int p = T; p != S; p = E[p][pre[p]].t) {
            auto& e = E[p][pre[p]];
            e.flow -= 1;
            E[e.t][e.rev].flow += 1;
            _D("%d -> %d added!\n", p, E[p][pre[p]].t);
            _D("%d -> %d subed!\n", e.t, E[e.t][e.rev].t);
        }
    }

    int ans = 0;
    // 학생 -> 문제 간선을 확인한다.
    FOR(i,1,N+1) {
        for(auto& e: E[i]) {
            if (e.t >= 101 && e.t <= 101 + N) {
                if (e.flow > 0) {
                    _D("%d -> %d is flow!\n", i, e.t);
                    ans += e.cost;
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
