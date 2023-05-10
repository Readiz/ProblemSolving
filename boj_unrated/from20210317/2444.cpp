#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("2444_input.txt", "rt", stdin); }
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
    int N;
    scanf("%d", &N);
    printd("N: %d", N);
    printd("--------------------------");
    for (int i = 0; i < N; i++) {
        for (int j = N - i - 2; j >= 0; j--) {
            printf(" ");
        }
        for (int j = 1; j <= i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - i - 2; j >= 0; j--) {
            printf(" ");
        }
        for (int j = 1; j <= i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
MAIN_END

/*
예제 입력 1 
5
예제 출력 1 
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
    *
*/