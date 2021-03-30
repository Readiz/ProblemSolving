#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
int n, k;
int ray[1002][1001][2] = {0, }; // pos, size, direction

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int leftSum = 0, rightSum = 0;
        scanf("%d %d", &n, &k);
        // use 0 ~ n + 1. 0 & n + 1 is not reflection anything.
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 1; j <= k; j++) {
                ray[i][j][0] = 0;
                ray[i][j][1] = 0;
            }
        }
        ray[1][k][0] = 1;
        if (k > 0) {
            ray[0][k - 1][1] = 1;
        }
        // Simulation Start
        for (int s = k; s >= 1; s--) {
            for (int p = 1; p <= n; p++) {
                if (ray[p][s][0] != 0) {
                    // printd("Pos: %d, Ray: %d detected! (direction: right)", p, s);
                    // 직진 (0: 우측 방향)
                    int cur = ray[p][s][0];
                    ray[p][s][0] = 0;
                    ray[n + 1][s][0] += cur;
                    ray[n + 1][s][0] %= 1000000007;
                    for (int dp = p + 1; dp <= n; dp++) {
                        // 반사 (크기 1 초과할 때만)
                        if (s > 1) {
                            ray[0][s - 1][1] += cur;
                            ray[0][s - 1][1] %= 1000000007;
                        }
                        if (s > 2) {
                            ray[dp - 1][s - 2][0] += cur;
                            ray[dp - 1][s - 2][0] %= 1000000007;
                        }
                    }
                } else if (ray[p][s][1] != 0) {
                    // printd("Pos: %d, Ray: %d detected! (direction: left)", p, s);
                    // 직진 (1: 좌측 방향)
                    int cur = ray[p][s][1];
                    ray[p][s][1] = 0;
                    ray[0][s][1] += cur;
                    ray[0][s][1] %= 1000000007;
                    for (int dp = p - 1; dp >= 1; dp--) {
                        // 반사 (크기 1 초과할 때만)
                        if (s > 1) {
                            ray[n + 1][s - 1][0] += cur;
                            ray[n + 1][s - 1][0] %= 1000000007;
                        }
                        if (s > 2) {
                            ray[dp + 1][s - 2][1] += cur;
                            ray[dp + 1][s - 2][1] %= 1000000007;
                        }
                    }
                }
            }
        }
        // Left sum, Right Sum
        for (int s = k; s >= 1; s--) {
            leftSum += ray[0][s][1];
            leftSum %= 1000000007;
            rightSum += ray[n + 1][s][0];
            rightSum %= 1000000007;
        }
        int sum = (leftSum + rightSum) % 1000000007;
        printf("%d\n", sum);
    }
    return 0;
MAIN_END
