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
int level[MAX_V];
int start[MAX_V];

// 함수 1. BFS
int makeLevelGraph() {
    fill(level, level + MAX_V, -1);
    // bfs
    queue<int> q;
    q.push(S);
    level[S] = 0;

    while(q.size()) {
        int cur = q.front(); q.pop();
        for(auto& e: E[cur]) {
            if (level[e.t] == -1 && e.getResidual() > 0) {
                level[e.t] = level[cur] + 1;
                q.push(e.t);
            }
        }
    }
    _D("T level: %d\n", level[T]);
    return (level[T] != -1);
}
// 함수2. DFS
int dfsFlow(int from, int cFlow) {
    assert(from >= 0 && from < MAX_V);
    if (from == T) return cFlow; // dfs 종료조건

    // &i : 탐색 캐시를 위한 테크닉
    for(int &i = start[from]; i < E[from].size(); ++i) {
        auto& e = E[from][i];
        if (level[e.t] == level[from] + 1 && e.getResidual() > 0) {
            int minFlow = min(cFlow, e.getResidual());
            int tmp = dfsFlow(e.t, minFlow);

            if (tmp > 0) {
                _D("flow added on %d ~ %d += %d!\n", from, e.t, tmp);
                e.flow += tmp;
                E[e.t][e.rev].flow -= tmp;
                _D("flow added on %d ~ %d -= %d!\n", e.t, E[e.t][e.rev].t, tmp);
                return tmp; // 경로 하나 찾으면 리턴. 어차피 dfs 반복함.
            }
        }
    }

    return 0; // 흘릴 유량이 없으면 0
}

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
    int totalFlow = 0;
    while(makeLevelGraph()) {
        fill(start, start + MAX_V, 0); // 탐색 cache
        while(true) {
            int curFlow = dfsFlow(S, INF);
            if (curFlow == 0) break;
            totalFlow += curFlow;
        }
    }

    _D("total flow: %d\n", totalFlow);

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
