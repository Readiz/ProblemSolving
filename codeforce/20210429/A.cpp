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
        ll a, b, d;
        scanf("%lld %lld %lld", &a, &b, &d);
        if (a < b) {
            ll tmp = a;
            a = b;
            b = tmp;
        }
        ll dP = a / b;
        if (a % b > 0) { // 나머지가 있으면
            dP += 1LL;
        }
        printd("%lld", dP);
        printd("largest A - B = %lld", dP - 1);
        if (dP - 1 <= d) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
MAIN_END
