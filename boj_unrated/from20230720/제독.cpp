#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
    int s, t;
    int cost;
    int flow;
    int capa;
    Edge* rev;

    int getResidual() {
        return capa - flow;
    }
} epool[100000];
int epoolSz;

constexpr int QMAX = 100000;
int Q[QMAX];
int qf, qr;

int INF = 0x3A3A3A3A;
int V, E;
vector<Edge*> adj[2010];
int dist[2010];
int inQ[2010];
Edge* pre[2010];
void solve() {
    // S -> 1 -> V -> T 경로 찾기: 유량 = 2
    // 정점 분할도 사용, 1, V 제외하고는 1번씩만 들려야 함
    epoolSz = 0;
    for(int i = 1; i <= V; ++i) {
        adj[i*2].clear();
        adj[i*2+1].clear();
        assert(i*2+1 < 2010);
    }
    for(int i = 1; i <= V; ++i) {
        int c = 1;
        if (i == 1 || i == V) {
            c = 2;
        }
        epool[epoolSz++] = Edge{
            i*2, i*2+1,
            0, 0, c,
            0
        };
        epool[epoolSz++] = Edge{ // rev
            i*2+1, i*2,
            0, 0, 0,
            0
        };
        adj[i*2].push_back(&epool[epoolSz - 2]);
        adj[i*2+1].push_back(&epool[epoolSz - 1]);
        adj[i*2].back()->rev = adj[i*2+1].back();
        adj[i*2+1].back()->rev = adj[i*2].back();
        assert(i*2+1 < 2010);
    }
    int S = 2, T = V * 2 + 1;
    for(int i = 0; i < E; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int s = a * 2 + 1, t = b * 2;
        epool[epoolSz++] = Edge{
            s, t,
            c, 0, 1,
            0
        };
        epool[epoolSz++] = Edge{
            t, s,
            -c, 0, 0,
            0
        };
        adj[s].push_back(&epool[epoolSz - 2]);
        adj[t].push_back(&epool[epoolSz - 1]);
        adj[s].back()->rev = adj[t].back();
        adj[t].back()->rev = adj[s].back();
        assert(s < 2010);
        assert(t < 2010);
    }


    int sumCost = 0;
    int dFlow = 0;
    while(true) {
        // 유량을 하나 흘려 본다
        memset(dist, 0x3A, sizeof(int) * 2010);
        memset(inQ, 0x00, sizeof(int) * 2010);
        memset(pre, 0x00, sizeof(Edge*) * 2010);
        inQ[S] = 1;
        dist[S] = 0;
        qf = qr = 0;
        Q[qr++] = S;

        while(qf != qr) {
            auto& cur = Q[qf++]; qf %= QMAX;
            inQ[cur] = 0;
            for(auto& edge: adj[cur]) {
                if (edge->getResidual()) {
                    int newDist = dist[cur] + edge->cost;
                    if (newDist < dist[edge->t]) {
                        dist[edge->t] = newDist;
                        pre[edge->t] = edge;
                        if (inQ[edge->t] == 0) {
                            inQ[edge->t] = 1;
                            Q[qr++] = edge->t;
                            qr %= QMAX;
                        }
                    }
                }
            }
        }
        // 이시점에 유량이 업데이트 되어야 함
        // 되지 않으면 종료
        if (dist[T] == INF) break;
        int cdist = 0;
        for(Edge* p = pre[T]; p != 0; p = pre[p->s]) {
            p->flow += 1;
            p->rev->flow -= 1;
            cdist += p->cost;
        }
        dFlow += 1;
        sumCost += cdist;
        // printf("[d] flow add, dist add: %d\n", cdist);
        assert(dFlow <= 2);
    }
    // printf("[d] %d -> should be 2\n", dFlow);
    printf("%d\n", sumCost);
}

int main() {
    // freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &V, &E) != EOF) {
        solve();
    }
    return 0;
}