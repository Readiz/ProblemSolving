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
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int sn = 1, sm = 1;
        int cost = 0;
        cost += (n - sn);
        // n에 도달함
        cost += n * (m - sm);
        printd("cost: %d", cost);
        if (cost == k) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
MAIN_END
