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
typedef long long ll;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        ll n, m, x;
        scanf("%lld %lld %lld", &n, &m, &x);
        // find coord
        ll _x = ((x % n) == 0) ? x / n : x / n + 1;
        ll _y = ((x % n) == 0) ? n : (x % n);
        printd("%lld, %lld", _x, _y);
        ll val = m * (_y - 1) + _x;
        printf("%lld\n", val);
    }
    return 0;
MAIN_END
