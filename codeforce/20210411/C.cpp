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

#define MOD 1'000'000'007
typedef unsigned long long ull;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (register int TC = 0; TC < tc; TC++) {
        int N, M;
        scanf("%d %d", &N, &M);
        ull dp[10];
        for (register int i = 0; i < 10; i++) dp[i] = 0ULL;
        while (N > 0) {
            dp[N % 10]++;
            N /= 10;
        }
        // for (int k = 0; k < 10; k++) {
        //     printf("%llu ", dp[k]);
        // }
        // printf("\n");
        while (M > 10) {
            ull tmp = dp[9];
            for (register int k = 8; k >= 0; k--) {
                dp[k + 1] = (dp[k + 1] + dp[k]) % MOD;
            }
            dp[0] = (dp[0] + tmp) % MOD;
            dp[1] = (dp[1] + tmp) % MOD;
            M -= 10;
        }
        for (register int i = 0; i < M; i++) {
            ull tmp = dp[9];
            for (register int k = 8; k >= 0; k--) {
                dp[k + 1] = dp[k];
            }
            dp[0] = tmp;
            dp[1] = (dp[1] + tmp) % MOD;
            // for (int k = 0; k < 10; k++) {
            //     printf("%llu ", dp[k]);
            // }
            // printf("\n");
        }
        ull sum = 0ULL;
        for (register int i = 0; i < 10; i++) {
            sum = (sum + dp[i]) % MOD;
        }
        printf("%llu\n", sum);
    }
MAIN_END
