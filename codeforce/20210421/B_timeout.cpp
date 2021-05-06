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
typedef unsigned long long ull;
typedef long long ll;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int n;
        scanf("%d", &n);
        ull A[2000];
        for (register int i = 0; i < n; i++) {
            ull tmp;
            scanf("%llu", &tmp);
            A[i] = tmp;
        }
        if (n >= 3) {
            printd("Finding 2 Partitions..");
            // 파티션 하나로 찾아보기
            bool isFound = false;
            for (register int a = 1; a < n; a++) {
                ull XORSumPart1 = 0ULL;
                ull XORSumPart2 = 0ULL;
                for (int i = 0; i < n; i++) {
                    if (i < a) {
                        XORSumPart1 ^= A[i];
                    } else {
                        XORSumPart2 ^= A[i];
                    }
                }
                if (XORSumPart1 == XORSumPart2) {
                    isFound = true;
                    printd("Found! Partition => a: %d", a);
                    goto out1;
                }
            }
            out1:
            if (isFound) {
                printf("YES\n");
            } else {
                printd("Finding 3 Partitions..");
                // a, b 파티션 나눠서 접근
                bool isFound = false;
                for (register int a = 1; a < n - 1; a++) {
                    for (register int b = a + 1; b < n; b++) {
                        printd("Check a: %d, b: %d...", a, b);
                        ull XORSumPart1 = 0ULL;
                        ull XORSumPart2 = 0ULL;
                        ull XORSumPart3 = 0ULL;
                        for (int i = 0; i < n; i++) {
                            if (i < a) {
                                XORSumPart1 ^= A[i];
                            } else if (i >= a && i < b) {
                                XORSumPart2 ^= A[i];
                            } else {
                                XORSumPart3 ^= A[i];
                            }
                        }
                        if (XORSumPart1 == XORSumPart2 && XORSumPart2 == XORSumPart3) {
                            isFound = true;
                            printd("Found! Partition => a: %d, b: %d", a, b);
                            goto out2;
                        }
                    }
                }
                out2:
                if (isFound) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            }
        } else {
            if (A[0] == A[1]) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
MAIN_END
