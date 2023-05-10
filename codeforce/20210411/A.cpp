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

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int N, K;
        scanf("%d %d", &N, &K);
        if (N % 2 == 0) {
            if (N / 2 - 1 < K) {
                printf("-1\n");
                continue;
            }
        } else {
            if (N / 2 < K) {
                printf("-1\n");
                continue;
            }
        }
        int arr[100] = {0, };
        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }
        int left = 0;
        int right = N - 1;
        while (left <= right) {
            if (N > 0) {
                printf("%d ", arr[left]);
                N--;
            }
            if (K > 0 && N > 0) {
                printf("%d ", arr[right]);
                right--;
                K--;
                N--;
            }
            left++;
        }
        printf("\n");
    }
MAIN_END
