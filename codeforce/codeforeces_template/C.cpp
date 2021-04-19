#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
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
    ull n;
    scanf("%llu", &n);
    printd("N: %llu\n-------------------------------", n);
    int A[100001] = {0, };
    // 에라토네스의 채처럼 풀자..
    for (int i = 1; i < n; i++) {
        A[i] = 1;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) { // 나누어 떨어지면 걸러냄 (배수도)..
            for (int j = i; j < n; j += i) {
                A[j] = 0;
            }
        }
    }
    ull r = 1ULL;
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] == 1) { // 살아남았으면 출력
            r *= i;
            r %= n;
            s++;
        }
    }
    printd("remained r: %llu", r);
    if (r == 1) { // 전체 그대로 출력
        printf("%d\n", s); // 총 개수
        for (int i = 1; i < n; i++) {
            if (A[i] == 1) { // 살아남았으면 출력
                printf("%d ", i);
            }
        }
        printf("\n");
    } else { // n - 2 까지만 출력
        printf("%d\n", s - 1);
        for (int i = 1; i < n - 1; i++) {
            if (A[i] == 1) { // 살아남았으면 출력
                printf("%d ", i);
            }
        }
        printf("\n");
    }
MAIN_END
