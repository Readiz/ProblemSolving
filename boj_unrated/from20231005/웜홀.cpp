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
#define X first
#define Y second

int N, M, W;
ll dist[501][501];
constexpr ll INF = 0x3A3A3A3A3A3A3A3A;
int q[1000000];
int qf, qr;
ll d[501];
int inQ[501];
int cnt[501];

void solve() {
    scanf("%d %d %d", &N, &M, &W);
    memset(dist, 0x3A, sizeof(ll) * 501 * 501);
    for(int i = 1; i <= N; ++i) dist[i][i] = 0;
    for(int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (dist[a][b] > c) dist[a][b] = c;
        if (dist[b][a] > c) dist[b][a] = c;
    }
    for(int i = 0; i < W; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (dist[a][b] > -c) dist[a][b] = -c;
    }

    for(int S = 1; S <= N; ++S) {
        memset(d, 0x3A, sizeof(ll) * (N + 1));
        memset(inQ, 0, sizeof(int) * (N + 1));
        memset(cnt, 0, sizeof(int) * (N + 1));

        d[S] = 0;
        inQ[S] = 1;

        qf = qr = 0;
        q[qr++] = S;

        while(qf != qr) {
            auto& cur = q[qf++];
            inQ[cur] = 0;

            // Check Negative Loop here
            if (++cnt[cur] >= N) {
                // _D("[%d] cnt[%d] >= %d! d[%d] = %lld < 0 / YES!\n", S, cur, N, cur, d[cur]);
                break;
            }
            
            for(int t = 1; t <= N; ++t) {
                if (dist[cur][t] >= INF) continue;
                ll newDist = d[cur] + dist[cur][t];
                if (newDist < d[t]) {
                    d[t] = newDist;
                    if (inQ[t] == 0) {
                        q[qr++] = t;
                        inQ[t] = 1;
                    }
                }
            }
        }

        if (d[S] < 0) {
            //_D("d[%d] = %lld < 0, YES!\n", S, d[S]);
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}