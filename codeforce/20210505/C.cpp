#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define R register
typedef unsigned long long ull;
typedef long long ll;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int N;
        scanf("%d", &N);
        printd("N: %d", N);
        if (N == 1) printf("1\n");
        else if (N == 2) printf("-1\n");
        else {
            int brd[100][100] = {0, };
            brd[0][0] = 1;
            // 증가하는 부분
            int k = 2;
            int num = 3;
            while (k <= N) {
                int x = k - 1;
                int y = 0;
                while (x >= 0) {
                    brd[y][x] = num++;
                    y++;
                    x--;
                }
                k++;
            }
            int p = 1;
            // 감소하는 부분
            while (k >= 2) {
                int x = N - 1;
                int y = p;
                while (y <= N - 1) {
                    brd[y][x] = num++;
                    y++;
                    x--;
                }
                k--;
                p++;
            }
            brd[N - 1][N - 1] = 2;

            for (R int i = 0; i < N; i++) {
                for (R int j = 0; j < N; j++) {
                    printf("%d ", brd[i][j]);
                }
                printf("\n");
            }
        }

    }
MAIN_END
