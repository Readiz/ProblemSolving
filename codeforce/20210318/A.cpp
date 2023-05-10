#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define MIN(a, b) (a) < (b) ? (a): (b)
#define ABS(a) (a) < 0 ? (-(a)) : (a)

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int n, k1, k2, w, b;
        scanf("%d %d %d", &n, &k1, &k2);
        scanf("%d %d", &w, &b);
        // possible w
        printd("ABS: %d", ABS(k1 - k2));
        int kw = (MIN(k1, k2)) + ((ABS(k1 - k2)) / 2);
        printd("%d %d", MIN(k1, k2) , ((ABS(k1 - k2)) / 2));
        int kb = (MIN(n - k1, n - k2)) + ((ABS(k1 - k2)) / 2);
        printd("%d %d", MIN(n - k1, n - k2), ((ABS(k1 - k2)) / 2));
        printd("kw: %d", kw);
        printd("kb: %d", kb);
        if (kw >= w && kb >= b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
MAIN_END
