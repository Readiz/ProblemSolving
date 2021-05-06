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
typedef unsigned long long ull;
typedef long long ll;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int n;
    scanf("%d", &n);
    int brd[500][500] = {0, };
    for (int i = 0; i < n; i++) {
        scanf("%d", &brd[i][i]);
    }
    if (isDebug) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (brd[i][j] > 0) {
                    printf("%2d ", brd[i][j]);
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
        int curRegion = brd[i][i];
        int remained = curRegion - 1; // 이미 숫자 하나는 대각선에 써있으니..
        int x = i, y = i;
        printd("fill %d...", curRegion);
        while (remained > 0) {
            if (x > 0 && brd[y][x - 1] == 0) { // 왼쪽이 비어있으면 왼쪽 먼저 채움
                x--;
                brd[y][x] = curRegion;
            } else { // 아래가 비어있으면 아래 먼저 채움
                y++;
                brd[y][x] = curRegion;
            }
            remained--;
        }
    }
    if (isDebug) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (brd[i][j] > 0) {
                    printf("%2d ", brd[i][j]);
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (brd[i][j] > 0) {
                printf("%d ", brd[i][j]);
            }
        }
        printf("\n");
    }
MAIN_END
