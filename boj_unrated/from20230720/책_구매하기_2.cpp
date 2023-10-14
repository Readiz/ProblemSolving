#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
    int s, t;
    int capa, flow;
    Edge* rev;
    Edge() {}
    Edge(int s, int t, int capa, Edge* r): s(s), t(t), capa(capa), flow(0), rev(r) {}
    int getResidual() {
        return capa - flow;
    }
} epool[100000];
int esz = 0;

constexpr int INF = 0x3A3A3A3A;
struct FlowGraph {
    int S = 0, T = 201;
    vector<Edge*> adj[202];

    void addEdge(int s, int t, int capa) {
        // printf("[e] %d -> %d / %d\n", s, t, capa);
        Edge& n = epool[esz++] = Edge(s, t, capa, &epool[esz+1]);
        Edge& r = epool[esz++] = Edge(t, s, 0, &epool[esz-1]);
        adj[s].push_back(&n);
        adj[t].push_back(&r);
    }

    int maxFlow() {
        // printf("[d] esz: %d\n", esz);
        // for(int i = 0; i < esz; ++i) {
        //     printf("[e] %d -> %d / %d\n", epool[i].s, epool[i].t, epool[i].capa);
        // }
        int res = 0;
        while(true) {
            Edge* pre[202] = {0, };
            queue<int> q;
            q.push(S);

            while(q.size()) {
                int cur = q.front(); q.pop();
                for(auto& e: adj[cur]) {
                    // printf("[d] check %d -> %d... res: %d\n", e->s, e->t, e->getResidual());
                    if (e->getResidual() > 0 && pre[e->t] == 0) {
                        pre[e->t] = e;
                        q.push(e->t);
                    }
                }
                if (pre[T] != 0) break; // 경로 하나 발견
            }
            if (pre[T] == 0) break; // no augpath
            int amount = INF;
            for(Edge* p = pre[T]; p != 0; p = pre[p->s]) {
                amount = min(amount, p->getResidual());
                if (p->s == S) break;
            }
            for(Edge* p = pre[T]; p != 0; p = pre[p->s]) {
                p->flow += amount;
                p->rev->flow -= amount;
                if (p->s == S) break;
            }
            res += amount;
            // printf("[d] flow += %d\n", amount);
        }

        return res;
    }
} fg;

int main() {
    int N, M; scanf("%d%d", &N, &M);
    vector<int> A(N+1);
    vector<int> B(N+1);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]); // i번째 유저가 원하는 책의 수
        fg.addEdge(fg.S, i, A[i]);
    }
    for(int i = 1; i <= M; ++i) {
        scanf("%d", &B[i]); // i번째 서점이 갖고 있는 책의 수
        fg.addEdge(i + 100, fg.T, B[i]);
    }
    // S -> A -> B -> T
    // A: 1 ~ 100 (사람)
    // B: 101 ~ 200 (서점)
    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            // i번째 서점에서 j번째 사람이 사는 책의 수
            int c; scanf("%d", &c);
            if (c != 0) {
                fg.addEdge(j, i+100, c);
            }
        }
    }
    printf("%d\n", fg.maxFlow());

    return 0;
}