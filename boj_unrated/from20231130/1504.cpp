#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

uint dist[801][801];
int main() {
    int N, M; scanf("%d %d", &N, &M);
    memset(dist, 0x3F, sizeof(uint) * 801 * 801);
    for(int i = 1; i <= N; ++i) dist[i][i] = 0;
    for(int i = 0; i < M; ++i) {
        int a, b, d; scanf("%d %d %d", &a, &b, &d);
        dist[a][b] = d;
        dist[b][a] = d;
    }

    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j)
        if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
    
    int A, B; scanf("%d %d", &A, &B);

    uint dist1 = dist[1][A] + dist[A][B] + dist[B][N];
    uint dist2 = dist[1][B] + dist[B][A] + dist[A][N];

    uint ans = min(dist1, dist2);
    if (ans >= 0x3F3F3F3F) printf("-1\n");
    else printf("%u\n", ans);

    return 0;
}