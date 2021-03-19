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
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int n;
        scanf("%d", &n);
        ull c[100000] = {0, };
        for (int i = 0; i < n; i++) {
            scanf("%llu", &c[i]);
        }
        bool isFirst = true;
        ull minSum;
        ull wMin = c[0], hMin = c[1];
        int wMinPos = 0, hMinPos = 1;
        int lastMaxPos = -1;
        for (int edge = 2; edge <= n; edge++) {
            if (edge < n) {
                if (edge % 2 == 0) {
                    if (wMin > c[edge]) {
                        wMin = c[edge];
                        wMinPos = edge;
                    }
                } else {
                    if (hMin > c[edge]) {
                        hMin = c[edge];
                        hMinPos = edge;
                    }
                }
            }
            printd("wMin: %d @ %d", wMin, wMinPos);
            printd("hMin: %d @ %d", hMin, hMinPos);
            int maxPos = (wMinPos > hMinPos) ? wMinPos : hMinPos;
            if (lastMaxPos == maxPos) continue;
            lastMaxPos = maxPos;
            ull sum1 = 0;
            int wCount = 0;
            int hCount = 0;
            for (int i = 0; i <= maxPos; i++) {
                if (i % 2 == 0) {
                    sum1 += c[i];
                    wCount++;
                } else {
                    sum1 += c[i];
                    hCount++;
                }
            }
            sum1 += (n - wCount) * wMin + (n - hCount) * hMin ;
            if (isFirst) {
                minSum = sum1;
                isFirst = false;
            } else {
                if (minSum > sum1) minSum = sum1;
            }
        }
        printf("%llu\n", minSum);
    }
    return 0;
MAIN_END
