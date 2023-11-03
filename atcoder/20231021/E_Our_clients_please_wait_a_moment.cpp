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

int N, A, B, C;
constexpr int MAX_V = 1000;
ll distA[MAX_V][MAX_V];
ll distB[MAX_V][MAX_V];
ll INF = 0x3A3A3A3A3A3A3A3A;
void solve() {
    scanf("%d %d %d %d", &N, &A, &B, &C);
    FOR(i,0,N) {
        FOR(j, 0, N) {
            ll d; scanf("%lld", &d);
            if (i == j) {
                distA[i][j] = 0;
                distB[i][j] = 0;
            } else {
                distA[i][j] = d * A;
                distB[i][j] = d * B + C;
            }
        }
    }

    ll a[MAX_V]; int inQ[MAX_V];
    fill(a, a + MAX_V, INF);
    fill(inQ, inQ + MAX_V, 0);
    a[0] = 0;
    inQ[0] = 1;

    queue<int> q;
    q.push(0);

    while(q.size()) {
        auto cur = q.front(); q.pop();
        inQ[cur] = 0;

        for(int t = 0; t < N; ++t) {
            if (t == cur) continue;
            ll newDist = a[cur] + distA[cur][t];
            if (newDist < a[t]) {
                a[t] = newDist;
                if (inQ[t] == 0) {
                    q.push(t);
                    inQ[t] = 1;
                }
            }
        }
    }

    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if (distB[i][j] > distB[i][k] + distB[k][j]) {
                    distB[i][j] = distB[i][k] + distB[k][j];
                }
            }
        }
    }

    ll ans = distB[0][N - 1];
    for(int i = 1; i < N; ++i) {
        ans = min(a[i] + distB[i][N-1], ans);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();

    return 0;
}