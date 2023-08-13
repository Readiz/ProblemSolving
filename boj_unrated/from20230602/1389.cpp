#include <bits/stdc++.h>
using namespace std;

int F[101][101];
int main() {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        F[i][j] = 9999999;
    }
    for(int i = 1; i <= N; ++i) F[i][i] = 0;
    for(int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        F[a][b] = 1;
        F[b][a] = 1;
    }

    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        if (F[i][k] + F[k][j] < F[i][j]) F[i][j] = F[i][k] + F[k][j];
    }
    // for (int i = 1; i <= N; ++i) {
    //     for(int j = 1; j <= N; ++j) {
    //         printf("%d ", F[i][j]);
    //     }
    //     printf("\n");
    // }
    int Kevin[101] = {0, };
    for (int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        Kevin[i] += F[i][j];
    }
    int min = 99999999;
    int minIdx = -1;
    for(int i = 1; i <= N; ++i) {
        if (min > Kevin[i]) min = Kevin[i], minIdx = i;
    }
    printf("%d\n", minIdx);

    return 0;
}