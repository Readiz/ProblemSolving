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
template<class T>
T gcd(T a, T b) {
    while (b != 0) {
        T r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int pow10(int a) {
    int r = 1;
    for (int i = 1; i < a; i++) {
        r *= 10;
    }
    return r;
}

int getNum(int a) {
    int r = 0;
    if (a == 0) return 1;
    while (a > 0) {
        a /= 10;
        r++;
    }
    return r;
}

void findGCD(int a, int b, int c, int& ra, int& rb) {
    for (int i = pow10(a); i < pow10(a + 1) - 1; i++) {
        for (int j = pow10(b); j < pow10(b + 1) - 1; j++) {
            if (getNum(gcd(i, j)) == c) {
                ra = i;
                rb = j;
                return;
            }
        }
    }
}

MAIN_START

    for (int a = 1; a <= 9; a++) {
        for (int b = a; b <= 9; b++) {
            for (int c = 1; c <= a; c++) {
                int ra, rb;
                findGCD(a, b, c, ra, rb);
                printf("ra[%d][%d][%d] = %d;\n", a, b, c, ra);
                printf("rb[%d][%d][%d] = %d;\n", a, b, c, rb);
            }
        }
    }

    return 0;



    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {

    }
MAIN_END
