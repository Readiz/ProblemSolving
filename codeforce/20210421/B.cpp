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
        int l = 0;
        int r = n - 1;
        bool flag = false;
        while (l < r) {
            if (A[l] < A[r]) {
                l++;
                A[l] ^= A[l - 1];
                flag = false;
            } else if (A[l] > A[r]) {
                r--;
                A[r] ^= A[r + 1];
                flag = false;
            } else {
                l++;
                r--;
                flag = true;
            }
        }
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
MAIN_END
