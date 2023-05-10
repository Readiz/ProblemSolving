#include <bits/stdc++.h>
using namespace std;

int ROOM[1001][1001];
int DP[1001][1001];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for(int n = 1; n <= N; ++n) {
        for(int m = 1; m <= M; ++m) {
            scanf("%d", &ROOM[n][m]);
        }
    }

    for(int n = 1; n <= N; ++n) {
        for(int m = 1; m <= M; ++m) {
            DP[n][m] = max(max(DP[n-1][m], DP[n][m-1]), DP[n-1][m-1]) + ROOM[n][m];
        }
    }

    printf("%d\n", DP[N][M]);

    return 0;
}