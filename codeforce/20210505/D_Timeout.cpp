#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
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
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int N;
        scanf("%d", &N);
        int A[200000];
        for (R int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        int ans = 0;
        for (R int i = 0; i < N - 1; i++) {
            int Ai = A[i];
            for (R int j = i + 1; j < N; j++) {
                int diff = j - i;
                if (diff == A[j] - Ai) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
MAIN_END
