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
        int n, k;
        scanf("%d %d", &n, &k);
        int A[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        int f, l;
        f = 0;
        l = n - 1;
        while (k-- > 0) {
            while (A[f] <= 0) f++;
            // while (A[l] >= 100) l--;
            if (f >= l) break;
            A[f]--; A[l]++;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
MAIN_END
