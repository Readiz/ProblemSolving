#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int A[200'002];
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int N;
        scanf("%d", &N);
        int max = -1, maxIdx;
        int sum = 0;
        for (int i = 0; i < N + 2; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp > max) {
                max = tmp;
                maxIdx = i;
            }
            sum += tmp;
            A[i] = tmp;
        }
        printd("Sum: %d / Max: %d, MaxIdx: %d", sum, max, maxIdx);

        // A. 우선 MAX 인놈이 b_n+1 / b_n+2 라고 가정하고 풀어본다. (O(n) 시간에 알 수 있음)
        printd("Continue to CaseA...");
        int caseASum = sum - max;
        int findIdx = -1;
        for (int i = 0; i < N + 2; i++) {
            if (i == maxIdx) continue;
            caseASum -= A[i];
            if (A[i] == caseASum) {
                findIdx = i;
                break;
            } else if (caseASum == max) {
                findIdx = i;
                break;
            }
            caseASum += A[i];
        }
        if (findIdx != -1) {
            for (int i = 0; i < N + 2; i++) {
                if (i == maxIdx || i == findIdx) continue;
                printf("%d ", A[i]);
            }
            printf("\n");
            continue;
        } else {
            printf("-1\n");
        }
        // printd("Continue to CaseB... (n^2)");
        // bool possible = false;
        // int i, j;
        // for (i = 0; i < N + 2; i++) {
        //     int caseBSum = sum - A[i]; // X 라 가정
        //     for (j = 0; j < N + 2; j++) {
        //         if (i == j) continue;
        //         if (A[j] == caseBSum - A[j]) {
        //             possible = true;
        //             break;
        //         }
        //     }
        //     if (possible) break;
        // }
        // if (possible) {
        //     for (int k = 0; k < N + 2; k++) {
        //         if (i == k || j == k) continue;
        //         printf("%d ", A[k]);
        //     }
        //     printf("\n");
        // } else {
        //     printf("-1\n");
        // }
    }
    return 0;
MAIN_END
