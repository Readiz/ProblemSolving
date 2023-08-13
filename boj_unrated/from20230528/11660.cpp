#include <stdio.h>

long long board[1025][1025] = {0, };
long long DP[1025][1025] = {0, };
int main() {
    int N, M; scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &board[j][i]);
        }
    }

    for(int j = 1; j <= N; ++j) {
        for(int i = 1; i <= N; ++i) {
            DP[j][i] = DP[j-1][i] + DP[j][i-1] + board[j][i] - DP[j-1][i-1];
        }
    }
    
    // for(int j = 1; j <= N; ++j) {
    //     for(int i = 1; i <= N; ++i) {
    //         printf("%lld ", DP[j][i]);
    //     }
    //     printf("\n");
    // }

    for(int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        --x1; --y1;
        printf("%lld\n", DP[y2][x2] + DP[y1][x1] - DP[y2][x1] - DP[y1][x2]);
    }

    return 0;
}