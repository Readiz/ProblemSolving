#include <bits/stdc++.h>
using namespace std;

enum SEL {
    UNSELECTED = 0,
    SELECTED = 1
};


int BOARD[2][100'001];
void solve() {
    int DP[2][100'001][2] = {0, };
    int N;
    scanf("%d", &N);

    for(int i = 0; i <= 1; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &BOARD[i][j]);
        }
    }


    for(int j = 1; j <= N; ++j) {
        for(int i = 0; i <= 1; ++i) {
            // SELECTED는 명백한 case.
            DP[i][j][SELECTED] = max(max(DP[i^1][j-1][UNSELECTED], DP[i^1][j-1][SELECTED]), DP[i][j-1][UNSELECTED]) + BOARD[i][j];
            // UNSELECTED는 세가지를 생각해야함
            // 하나만 선택 a, b, 둘다 선택 c
            int left = max(DP[i][j-1][SELECTED], DP[i][j-1][UNSELECTED]);
            int top = max(DP[i^1][j-1][UNSELECTED] + BOARD[i^1][j], DP[i^1][j-1][SELECTED]);
            int both = max(DP[i][j-1][SELECTED] - BOARD[i][j-1], DP[i^1][j-1][UNSELECTED]) + BOARD[i][j-1] + BOARD[i^1][j];
            DP[i][j][UNSELECTED] = max(max(left,top),both);
        }
    }
    for(int i = 0; i <= 1; ++i) {
        printf("[DEBUG] ");
        for(int j = 1; j <= N; ++j) {
            printf("%d ", DP[i][j][SELECTED]);
        }
        printf("\n");
    }
    for(int i = 0; i <= 1; ++i) {
        printf("[DEBUG] ");
        for(int j = 1; j <= N; ++j) {
            printf("%d ", DP[i][j][UNSELECTED]);
        }
        printf("\n");
    }

    printf("%d\n", max(DP[1][N][SELECTED], DP[1][N][UNSELECTED]));
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        solve();
    }
    return 0;
}