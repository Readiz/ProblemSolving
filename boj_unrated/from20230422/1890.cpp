#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int B[101][101];
ull DP[120][120];
int N;

void pdebug() {
    printf("-----\n");
    for(int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }
}
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &B[i][j]);
        }
    }
    DP[1][1] = 1;

    for(int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == N && j == N) break;
            int v = B[i][j];
            DP[i + v][j] += DP[i][j];
            DP[i][j + v] += DP[i][j];
        }
    }

    printf("%llu\n", DP[N][N]);
    return 0;
}