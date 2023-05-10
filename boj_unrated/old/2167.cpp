#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[300][300] = {0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    int K;
    scanf("%d", &K);
    for (int k = 0; k < K; k++) {
        int i, j, x, y;
        scanf("%d %d %d %d", &i, &j, &x, &y);
        int sum = 0;
        for (int a = i - 1; a <= x - 1; a++) {
            for (int b = j - 1; b <= y - 1; b++) {
                sum += A[a][b];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}