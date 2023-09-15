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

int N, S, E, M;
ll cost[50][50];
ll benefit[50];
vector<int> adj[50];
int q[1000000];
int qf, qr;
int main() {
    scanf("%d%d%d%d", &N, &S, &E, &M);
    for(int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        cost[a][b] = c;
        adj[a].push_back(b);
    }
    for(int i = 0; i < N; ++i) {
        scanf("%lld", &benefit[i]);
        for(int j = 0; j < N; ++j) {
            cost[j][i] -= benefit[i];
        }
    }
    int visited[50] = {0,};
    int inQ[50] = {0, };
    ll d[50];
    memset(d, 0x3A, sizeof(ll) * 50);

    d[S] = -benefit[S];
    inQ[S] = 1;
    visited[S]++;
    q[qr++] = S;
    bool hasCycle = false;
    while(qf != qr) {
        auto& cur = q[qf++];
        inQ[cur] = 0;

        for(auto& t: adj[cur]) {
            int newD = d[cur] + cost[cur][t];
            if (newD < d[t]) {
                d[t] = newD;
                inQ[t] = 1;
                q[qr++] = t;

                ++visited[t];
                if (visited[t] >= N) {
                    // TODO
                    hasCycle = true;
                    break;
                }
            }
        }
    }

    if (d[E] == 0x3A3A3A3A3A3A3A3ALL) {
        printf("gg\n");
        return 0;
    }
    if (hasCycle) {
        printf("Gee\n");
        return 0;
    }
    printf("%lld\n", -d[E]);

    return 0;
}