#include <stdio.h>

int DP[101][101];

int main() {
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        if (i != j) DP[i][j] = 987654321;
    }
    for(int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (DP[a][b] > c) {
            DP[a][b] = c;
        }
    }
    for(int k = 1; k <= N; ++k)
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j) {
                if (DP[i][k] + DP[k][j] < DP[i][j]) {
                    DP[i][j] = DP[i][k] + DP[k][j];
                }
            }
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (DP[i][j] == 987654321) printf("0 ");
            else printf("%d ", DP[i][j]);
        }
        printf("\n");
    }
    return 0;
}