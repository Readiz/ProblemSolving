#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dist[101][101];
void solve() {
    int N, M; scanf("%d %d", &N, &M);
    memset(dist, 0x3A, sizeof(int) * 101 * 101);
    for(int i = 1; i <= N; ++i) dist[i][i] = 0;
    for(int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int K; scanf("%d", &K);
    vector<int> dpos(K);
    for(auto& i: dpos) scanf("%d", &i);
    ll minVal = 0x3A3A3A3A3A3A3A3A;
    int minPos = -1;
    for(int i = 1; i <= N; ++i) {
        ll cur = 0;
        for(int k = 0; k < K; ++k) {
            cur += dist[i][dpos[k]];
        }
        if (cur < minVal) {
            minVal = cur;
            minPos = i;
        }
    }
    printf("%d\n", minPos);
}

int main() {
    int N; scanf("%d", &N);
    while(N--) solve();
    return 0;
}