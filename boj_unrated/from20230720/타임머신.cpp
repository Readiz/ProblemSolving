// SPFA 연습

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ll dist[501][501];
constexpr ll INF = 987654321;
int main() {
    int N, M; scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int m = 0; m < M; ++m) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (dist[a][b] > c) dist[a][b] = c;
    }

    vector<ll> d;
    vector<ll> cnt;
    vector<ll> inQ;
    d.resize(N+1);
    cnt.resize(N+1);
    inQ.resize(N+1);
    fill(d.begin(), d.end(), INF);
    fill(cnt.begin(), cnt.end(), 0);
    fill(inQ.begin(), inQ.end(), 0);

    // 출발점: 1번지점
    d[1] = 0;
    queue<int> q;
    q.push(1);

    while(q.size()) {
        int v = q.front(); q.pop();
        inQ[v] = 0;
        cnt[v]++;
        if (cnt[v] >= N) {
            // 음수 cycle
            printf("-1\n");
            return 0;
        }

        for(int i = 1; i <= N; ++i) {
            if (d[i] > d[v] + dist[v][i]) {
                d[i] = d[v] + dist[v][i];
                if (inQ[i] == 0) { // SPFA 핵심! 넣는 조건 유의.
                    q.push(i);
                    inQ[i] = 1;
                }
            }
        }
    }

    for(int i = 2; i <= N; ++i) {
        if (d[i] < INF)
            printf("%lld\n", d[i]);
        else printf("-1\n");
    }

    return 0;
}