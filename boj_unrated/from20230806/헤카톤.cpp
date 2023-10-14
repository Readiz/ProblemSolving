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

int N, M, R;
vector<int> A;
vector<int> B;
bool boolB[101];
vector<pair<int,int>> uv;

int S = 0;
int T = 201;
struct Edge {
    int s, t;
    int capa, flow;
    Edge* rev;
    int getResidual() {
        return capa - flow;
    }
} epool[100000];
int Q[100000];
int qf, qr;
int esz;
constexpr int INF = 0x3A3A3A3A;
bool solve(int possibleAns) {
    // printf("[d] pA: %d\n", possibleAns);
    // 1. flow graph 생성 (input data 기반)
    vector<Edge*> adj[202];
    esz = 0;
    for(int i = 1; i <= N; ++i) {
        // S -> A
        epool[esz++] = Edge{
            S, i,
            A[i], 0,
        };
        epool[esz++] = Edge{ // rev
            i, S,
            0, 0
        };
        epool[esz - 2].rev = &epool[esz - 1];
        epool[esz - 1].rev = &epool[esz - 2];
        adj[S].push_back(&epool[esz - 2]);
        adj[i].push_back(&epool[esz - 1]);

        // A -> B
        epool[esz++] = Edge{
            i, i + 100,
            INF, 0,
        };
        epool[esz++] = Edge{ // rev
            i + 100, i,
            0, 0
        };
        epool[esz - 2].rev = &epool[esz - 1];
        epool[esz - 1].rev = &epool[esz - 2];
        adj[i].push_back(&epool[esz - 2]);
        adj[i+100].push_back(&epool[esz - 1]);

        // B -> T
        if (boolB[i]) {
            epool[esz++] = Edge{
                i + 100, T,
                possibleAns, 0,
            };
            epool[esz++] = Edge{ // rev
                T, i + 100,
                0, 0
            };
            epool[esz - 2].rev = &epool[esz - 1];
            epool[esz - 1].rev = &epool[esz - 2];
            adj[i + 100].push_back(&epool[esz - 2]);
            adj[T].push_back(&epool[esz - 1]);
        }
    }

    // uv
    for(auto& item: uv) {
        int u = item.first; int v = item.second;
        epool[esz++] = Edge{
            u, v + 100,
            INF, 0,
        };
        epool[esz++] = Edge{ // rev
            v + 100, u,
            0, 0
        };
        epool[esz - 2].rev = &epool[esz - 1];
        epool[esz - 1].rev = &epool[esz - 2];
        adj[u].push_back(&epool[esz - 2]);
        adj[v+100].push_back(&epool[esz - 1]);
    }

    // 2. flow 그래프 풀이
    Edge* pre[202];
    int sumFlow = 0;
    while(true) {
        memset(pre, 0, sizeof(Edge*) * 202);
        qf = qr = 0;
        Q[qr++] = S;
        while(qf != qr) {
            auto& cur = Q[qf++];
            for(auto& edge: adj[cur]) {
                if (edge->getResidual() > 0 && pre[edge->t] == 0) {
                    pre[edge->t] = edge;
                    if (edge->t == T) break;
                    Q[qr++] = edge->t;
                }
            }
            if (pre[T] != 0) break;
        }
        if (pre[T] == 0) break; // 더이상 경로 X

        // amount min 구하기
        int amount = INF;
        for(Edge* p = pre[T]; p != 0; p = pre[p->s]) {
            amount = min(amount, p->getResidual());
            if (p->s == S) break;
        }
        // 흘리기
        for(Edge* p = pre[T]; p != 0; p = pre[p->s]) {
            p->flow += amount;
            p->rev->flow -= amount;
            if (p->s == S) break;
        }
        // printf("[d] flow += %d (last: %d -> %d)\n", amount, pre[T]->s, pre[T]->t);
        sumFlow += amount;
    }
    // printf("[d] sumFlow = %d\n", sumFlow); // 약점에 배치된 용사 수
    // 현재 flow의 합이 넘어온 pAns 값 * 이동 정점과 같다면 다 이동한 것
    if (sumFlow == possibleAns * R) return true;
    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    A.push_back(0); // dummy
    for(int i = 1; i <= N; ++i) {
        int v; scanf("%d", &v);
        A.push_back(v);
    }
    for(int i = 0; i < M; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        uv.push_back({u, v});
    }
    scanf("%d", &R);
    for(int i = 0; i < R; ++i) {
        int v; scanf("%d", &v);
        B.push_back(v);
        boolB[v] = 1;
    }
    int l = 0, r = 10'000'000; // max: 100 * 100000
    int ans = -1;
    for(int m = (l+r)/2; l <= r; m = (l+r)/2) {
        // printf("%d~%d~%d\n", l, m, r);
        if (solve(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1; // 더 줄여본다
        }
    }
    printf("%d\n", ans);
    return 0;
}