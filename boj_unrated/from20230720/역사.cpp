#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dist[401][401];
int main() {
    memset(dist, 0x3A, sizeof(int)*401*401);
    int N, M; scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i) dist[i][i] = 0;
    for(int i = 0; i < M; ++i) {
        int a,b; scanf("%d%d", &a, &b);
        dist[a][b] = 1;
    }

    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int Q; scanf("%d", &Q);
    for(int i = 0; i < Q; ++i) {
        int a,b; scanf("%d%d", &a, &b);
        if (dist[a][b] == 0x3A3A3A3A && dist[b][a] == 0x3A3A3A3A) {
            printf("%d\n", 0);
        } else if (dist[a][b] != 0x3A3A3A3A) {
            printf("%d\n", -1);
        } else if (dist[b][a] != 0x3A3A3A3A) {
            printf("%d\n", 1);
        } else {
            assert(false);
        }
    }

    return 0;
}