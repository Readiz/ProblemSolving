#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr int INF = 0x3A3A3A3A;
int dist[201][201];
int nxt[201][201];
int main() {
    int N, M; scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            dist[i][j] = INF;
            nxt[i][j] = j;
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        dist[a][b] = c;
        dist[b][a] = c;
    }
    
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (i == j) printf("- ");
            else {
                printf("%d ", nxt[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}