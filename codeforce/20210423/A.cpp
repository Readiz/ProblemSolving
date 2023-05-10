#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("A_input.txt", "rt", stdin); }
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
        ull startNum = 2050000000000000000ULL;
        ull n;
        int count = 0;
        scanf("%llu", &n);
        while (n >= 2050) {
            if (startNum > n && startNum > 2050ULL) {
                startNum /= 10ULL;
                continue;
            }
            n -= startNum;
            count++;
        }
        if (n == 0) {
            printf("%d\n", count);
        } else {
            printf("-1\n");
        }
    }
MAIN_END
