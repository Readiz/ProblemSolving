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
        int n;
        scanf("%d", &n);
        int type1Cnt = 0, type2Cnt = 0, type3Cnt = 0;
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp == 1) type1Cnt++;
            else if (tmp == 2) type2Cnt++;
            else type3Cnt++;
        }
        printd("%d %d %d", type1Cnt, type2Cnt, type3Cnt);
        printf("%d\n", type1Cnt + type3Cnt);
    }
MAIN_END
