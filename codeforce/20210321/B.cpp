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
        ll A[100000] = {0, };
        ll C = -1;
        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
        }
        bool checkC = true;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] < A[i + 1]) {
                if (C == -1) {
                    C = A[i + 1] - A [i];
                } else if (C != A[i + 1] - A[i]) {
                    checkC = false;
                    break;
                }
            }
        }
        if (checkC == false) {
            printf("-1\n");
            continue;
        }
        bool checkM = true;
        ll M = -1;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                if (M == -1) {
                    M = A[i] + C - A[i + 1];
                } else {
                    if (M != (A[i] + C - A[i + 1])) {
                        checkM = false;
                        break;
                    }
                }
            }
        }
        if (checkM == false) {
            printf("-1\n");
            continue;
        }
        printd("%lld %lld", M, C);
        if (M == -1) {
            bool checkIncreaseOrSame = true;
            if (C == -1) C = 0;
            for (int i = 0; i < N - 1; i++) {
                if (A[i] + C != A[i + 1]) {
                    checkIncreaseOrSame = false;
                    break;
                }
            }
            if (checkIncreaseOrSame) {
                printf("0\n");
                continue;
            }
        }
        // M, C verify
        checkM = true;
        for (int i = 0; i < N; i++) {
            if (A[i] >= M) {
                checkM = false;
                break;
            }
            if (i == N - 1) continue;
            if ((A[i] + C) % M != A[i + 1]) {
                checkC = false;
                break;
            }
        }
        if (checkM == false || checkC == false) {
            printf("-1\n");
            continue;
        }

        printf("%lld %lld\n", M, C);
    }
    return 0;
MAIN_END
