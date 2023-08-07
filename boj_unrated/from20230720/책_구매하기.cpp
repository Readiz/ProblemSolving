#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;

int N, M;
int A[101], B[101];

int cost[210][210];
int capa[210][210];
int flow[210][210];
int inQ[210];
int pre[210];
int dist[210];
vector<int> adj[210];

// 1 ~ 100 : 서점
// 101 ~ 200 : 사람
// S: 201
// T: 202

constexpr int S = 201;
constexpr int T = 202;
constexpr int INF = 987654321;

int main() {
    scanf("%d %d", &N, &M); // N명, 서점수 M개
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]); // i번째 사람이 원하는 책의 수
    for(int i = 1; i <= M; ++i) scanf("%d", &B[i]); // 서점이 가지고 있는 책의 수

    // S -> 서점 -> 사람 -> T
    for(int i = 1; i <= M; ++i) {
        // 책: flow 대상
        // 각 서점으로는 책의 수만큼 flow 가능 -> 용량
        capa[S][i] = B[i];
        adj[S].push_back(i);
        adj[i].push_back(S);

        for(int j = 1; j <= N; ++j) {
            // 서점 i가 j에게 보내는데 드는 비용
            int tmp; scanf("%d", &tmp);
            cost[i][j+100] = tmp;
            cost[j+100][i] = -tmp; // 역방향 간선의 cost는 음수!

            capa[i][j+100] = INF;
            adj[i].push_back(j+100);
            adj[j+100].push_back(i);
        }
    }
    for(int j = 1; j <= N; ++j) {
        capa[j+100][T] = A[j];
        adj[j+100].push_back(T);
        adj[T].push_back(j+100);
    }

    // MCMF
    int ans = 0;
    int overallamount = 0;
    while(true) {
        fill(dist, dist+210, INF);
        fill(pre, pre+210, -1);
        fill(inQ, inQ+210, 0); //for spfa

        dist[S] = 0;
        inQ[S] = 1;
        queue<int> q;
        q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(auto& t: adj[cur]) {
                int residual = capa[cur][t] - flow[cur][t];
                int newDist = dist[cur] + cost[cur][t];
                if (residual > 0 && newDist < dist[t]) {
                    // 용량이 남아있고, 거리가 줄어들면..
                    dist[t] = newDist;
                    pre[t] = cur;
                    if (inQ[t] == 0) {
                        inQ[t] = 1;
                        q.push(t);
                    }
                }
            }
        }
        if (dist[T] == INF) break; // 거리업데이트가 더이상 안되면 종료

        int amount = INF;
        for(int p = T; p != S; p = pre[p]) {
            amount = min(amount, capa[pre[p]][p] - flow[pre[p]][p]); // 현재 경로에 추가로 흐를 수 있는 유량을 구한다.
        }
        for(int p = T; p != S; p = pre[p]) {
            ans += cost[pre[p]][p] * amount;
            flow[pre[p]][p] += amount;
            flow[p][pre[p]] -= amount;
        }
        overallamount += amount;
    }

    printf("%d\n", ans);
    _D("overall: %d\n", overallamount);
    

    return 0;
}