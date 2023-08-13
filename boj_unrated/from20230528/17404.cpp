#include <bits/stdc++.h>
using namespace std;

int DP[3][3][1001];
int main() {
    int N; scanf("%d", &N);
    int cost[3][1001];
    for(int i = 1; i <= N; ++i) {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        cost[0][i] = r;
        cost[1][i] = g;
        cost[2][i] = b;
    }
    // DP[sc][c][i] // 1위치의 색상이 sc이며, 색상 c로 i번째를 칠했을 때의 비용의 최소값
    DP[0][0][2] = 0x4FFFFFFF; // 불가능한 case
    DP[1][1][2] = 0x4FFFFFFF;
    DP[2][2][2] = 0x4FFFFFFF;
    DP[0][1][2] = cost[0][1] + cost[1][2];
    DP[0][2][2] = cost[0][1] + cost[2][2];
    DP[1][0][2] = cost[1][1] + cost[0][2];
    DP[1][2][2] = cost[1][1] + cost[2][2];
    DP[2][0][2] = cost[2][1] + cost[0][2];
    DP[2][1][2] = cost[2][1] + cost[1][2];

    // 2~N-1까지 보고,
    // N번째의 경우 N-1과 1을 동시에 보고 선택한다. (사실 선택의 여지가 없음)
    for(int sc = 0; sc < 3; ++sc) {
        for(int i = 3; i <= N-1; ++i) {
            for(int c = 0; c < 3; ++c) {
                int v1 = cost[c][i] + DP[sc][(c+1)%3][i - 1];
                int v2 = cost[c][i] + DP[sc][(c+2)%3][i - 1];
                DP[sc][c][i] = min(v1, v2);
            }
        }
    }
    // N 위치를 채운다.
    DP[0][0][N] = 0x4FFFFFFF;
    DP[1][1][N] = 0x4FFFFFFF;
    DP[2][2][N] = 0x4FFFFFFF;
    DP[0][1][N] = min(DP[0][0][N-1], DP[0][2][N-1]) + cost[1][N];
    DP[0][2][N] = min(DP[0][0][N-1], DP[0][1][N-1]) + cost[2][N];
    DP[1][0][N] = min(DP[1][1][N-1], DP[1][2][N-1]) + cost[0][N];
    DP[1][2][N] = min(DP[1][0][N-1], DP[1][1][N-1]) + cost[2][N];
    DP[2][0][N] = min(DP[2][1][N-1], DP[2][2][N-1]) + cost[0][N];
    DP[2][1][N] = min(DP[2][0][N-1], DP[2][2][N-1]) + cost[1][N];

    int min = 0x7FFFFFFF;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if (DP[i][j][N] < min) min = DP[i][j][N];
        }
    }

    printf("%d\n", min);

    return 0;
}