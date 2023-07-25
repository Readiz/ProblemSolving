#include <stdio.h>

constexpr int INF = 98765431;
int d[101][101];
int prev[101][101];
int main() {
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            d[i][j] = INF;
            prev[i][j] = 0;
        }
    }
    for(int i = 1; i <= N; ++i) d[i][i] = 0;

    for(int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (d[a][b] > c) {
            d[a][b] = c;
            prev[a][b] = a;
        }
    }
    for(int k = 1; k <= N; ++k) 
        for(int i = 1; i <= N; ++i) 
            for(int j = 1; j <= N; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    prev[i][j] = prev[k][j];
                    // printf("[d] %d -> %d / %d -> %d -> %d is opt.\n", i, j, i, k, j);
                }
            }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (d[i][j] >= INF) printf("0 ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    int path[101];
    for(int s = 1; s <= N; ++s) {
        for(int e = 1; e <= N; ++e) {
            // s ~ e 사이의 경로를 개수 | 경로를 출력
            // printf("[%d~%d] ", s, e);
            if (s == e || d[s][e] >= INF) {
                printf("0\n");
                continue;
            }
            int cnt = 0;
            int cur = e;
            path[cnt++] = e;
            while (prev[s][cur] != s) {
                cur = prev[s][cur];
                path[cnt++] = cur;
            }
            printf("%d ", cnt + 1);
            printf("%d ", s);
            for(int k = cnt - 1; k >= 0; --k) {
                printf("%d ", path[k]);
            }
            printf("\n");
        }
    }
    return 0;
}