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

typedef unsigned long long ull;
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N;
    scanf("%d", &N);
    printd("Input - N: %d", N);
    printd("--------------------------");

    ull a = 0, b = 1, c = 1;
    ull tmp;
    for (int i = 0; i < N; i++) {
        tmp = c;
        a = b % 1000000007;
        b = tmp % 1000000007;
        c = a + b;
    }

    printf("%llu\n", a);    
    return 0;
MAIN_END


/*
N = int(input())
a, b, c = 0, 1, 1
temp = 0

for i in range(N):
    temp = c
    a = b % 1000000007
    b = temp % 1000000007
    c = a + b

print(a)
*/
