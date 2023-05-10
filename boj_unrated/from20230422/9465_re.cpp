#include <bits/stdc++.h>
using namespace std;

int BOARD[2][100'001];
void solve() {
    int DP[2][100'001] = {0, };
    int N;
    scanf("%d", &N);

    for(int i = 0; i <= 1; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &BOARD[i][j]);
        }
    }

    DP[0][1] = BOARD[0][1];
    DP[1][1] = BOARD[1][1];

    for(int j = 2; j <= N; ++j) {
        for(int i = 0; i <= 1; ++i) {
            DP[i][j] = max(DP[i^1][j-1], DP[i^1][j-2]) + BOARD[i][j];
        }
    }


    for(int i = 0; i <= 1; ++i) {
        
        for(int j = 0; j <= N; ++j) {
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", max(DP[0][N], DP[1][N]));
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        solve();
    }
    return 0;
}