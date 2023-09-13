#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dist[500];
int inQ[500];
int q[1000000], qf, qr;
int N, M, S, D;
int forbid[500][500];
// pre path가 여러개 있을 수 있으므로 vector로 관리되어야 한다.
vector<int> pre[500];
vector<pair<int,int>> adj[500];

void dfs(int c) {
    if (c == S) return;
    for(auto& p: pre[c]) {
        if (forbid[p][c]) continue;
        forbid[p][c] = 1;
        dfs(p);
    }
}

void solve() {
    scanf("%d %d", &S, &D); // Source, Dest
    for(int i = 0; i < N; ++i) {
        pre[i].clear();
        adj[i].clear();
    }

    for(int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b, c});
    }
    /////////////////////////////////////////////////////////////////////////////////
    // 최단 경로 찾기 using SPFA
    memset(inQ, 0x00, sizeof(int) * N);
    memset(dist, 0x3A, sizeof(int) * N);

    dist[S] = 0;
    inQ[S] = 1;
    qf = qr = 0;
    q[qr++] = S;
    int shortest = 0x3A3A3A3A;

    while(qf != qr) {
        auto& cur = q[qf++];
        inQ[cur] = 0;
        for(auto& e: adj[cur]) {
            int newDist = dist[cur] + e.second;
            if (dist[e.first] > newDist) { // 더 나은 거리를 발견했으면 업데이트
                dist[e.first] = newDist;
                if (inQ[e.first] == 0) {
                    inQ[e.first] = 1;
                    q[qr++] = e.first;
                }
            }
        }
    }
    shortest = dist[D];
    if (shortest == 0x3A3A3A3A) {
        printf("-1\n");
        return;
    }
    /////////////////////////////////////////////////////////////////////////////////
    // 경로 삭제
    memset(inQ, 0x00, sizeof(int) * (N));
    memset(dist, 0x3A, sizeof(int) * (N));
    memset(forbid, 0x00, sizeof(int) * 500 * 500);
    dist[S] = 0;
    inQ[S] = 1;
    qf = qr = 0;
    q[qr++] = S;

    while(qf != qr) {
        auto& cur = q[qf++];
        inQ[cur] = 0;
        for(auto& e: adj[cur]) {
            int newDist = dist[cur] + e.second;
            if (dist[e.first] > newDist) { // 더 나은 거리를 발견했으면 업데이트
                dist[e.first] = newDist;
                pre[e.first].clear();
                pre[e.first].push_back(cur);

                if (inQ[e.first] == 0) {
                    inQ[e.first] = 1;
                    q[qr++] = e.first;
                }
            } else if (dist[e.first] == newDist) {
                pre[e.first].push_back(cur);
            }
        }
    }
    if (dist[D] == shortest) {
        dfs(D); // delete using DFS
    }
    
    /////////////////////////////////////////////////////////////////////////////////
    // "거의" 최단경로 찾기
    memset(inQ, 0x00, sizeof(int) * (N));
    memset(dist, 0x3A, sizeof(int) * (N));
    dist[S] = 0;
    inQ[S] = 1;
    qf = qr = 0;
    q[qr++] = S;

    while(qf != qr) {
        auto& cur = q[qf++];
        inQ[cur] = 0;
        for(auto& e: adj[cur]) {
            if (forbid[cur][e.first]) continue;
            int newDist = dist[cur] + e.second;
            if (dist[e.first] > newDist) { // 더 나은 거리를 발견했으면 업데이트
                dist[e.first] = newDist;
                if (inQ[e.first] == 0) {
                    inQ[e.first] = 1;
                    q[qr++] = e.first;
                }
            }
        }
    }

    if (dist[D] == 0x3A3A3A3A) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[D]);
    }
}
int main() {
    while(true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        solve();
    }

    return 0;
}