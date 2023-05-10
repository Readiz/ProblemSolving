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
#define R register
typedef unsigned long long ull;
typedef long long ll;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int n;
    scanf("%d", &n);
    int A[5000];
    int B[5000];
    ull S[5000];
    for (R int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    ull max = 0ULL;
    ull init = 0ULL;
    for (R int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
        S[i] = (ull) A[i] * (ull) B[i];
        init += S[i];
    }
    max = init;
    printd("Init max: %llu", max);
    for (R int i = 0; i < n - 1; i++) {
        for (R int j = i + 1; j < n; j++) {
            printd("reverse from %d -> %d...", i, j);
            ull originSum = 0ULL;
            ull reverseSum = 0ULL;
            for (R int p = i; p <= j; p++) {
                originSum += S[p];
                reverseSum += (ull) A[j - p + i] * (ull) B[p];
            }
            printd("originSum: %llu, reverSum: %llu", originSum, reverseSum);
            if (reverseSum > originSum) {
                ull newMax = init - originSum + reverseSum;
                if (newMax > max) {
                    max = newMax;
                    printd("changed max: %llu", max);
                }
            }
        }
    }
    printf("%llu\n", max);
MAIN_END
