#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("B_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int ax, ay, bx, by;
        int N;
        bool isFirst = false;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            char line[500];
            scanf("%s", line);
            for (int j = 0; j < N; j++) {
                if (line[j] == '*') {
                    if (isFirst == false) {
                        ax = j; ay = i;
                        isFirst = true;
                    } else {
                        bx = j; by = i;
                    }
                }
            }
        }
        if (ax == bx) {
            if (ax > 0) {
                bx = 0;
            } else {
                bx = 1;
            }
        } else if (ay == by) {
            if (ay > 0) {
                by = 0;
            } else {
                by = 1;
            }
        }
        char output[500][500];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= N; j++) {
                if (j == N) {
                    output[i][j] = 0; // EOL
                    continue;
                }
                if ((i == ay && j == ax) ||
                    (i == ay && j == bx) ||
                    (i == by && j == ax) ||
                    (i == by && j == bx)) {
                        output[i][j] = '*';
                } else {
                    output[i][j] = '.';
                }
            }
        }
        for (int i = 0; i < N; i++) {
            printf("%s\n", output[i]);
        }
    }
    return 0;
MAIN_END
