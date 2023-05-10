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

ull gcd(ull a, ull b) {
    while (b != 0) {
        ull r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ull sumEach(ull n) {
    ull sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

ull gcdSum(ull x) {
    return gcd(x, sumEach(x));
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        ull N;
        scanf("%llu", &N);
        ull x = N;
        while (true) {
            ull val = gcdSum(x);
            if (val > 1) break;
            x++;
        }
        printf("%llu\n", x);
    }
    return 0;
MAIN_END
