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
        int N;
        scanf("%d", &N);
        int evenArr[2000], oddArr[2000];
        int numE = 0, numO = 0;
        for (int i = 0; i < N; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp % 2 == 0) {
                evenArr[numE] = tmp;
                numE++;
            } else {
                oddArr[numO] = tmp;
                numO++;
            }
        }
        for (int i = 0; i < numO; i++) {
            printf("%d ", oddArr[i]);
        }
        for (int i = 0; i < numE; i++) {
            printf("%d ", evenArr[i]);
        }
        printf("\n");
    }
MAIN_END
