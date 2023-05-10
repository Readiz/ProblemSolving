#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
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

int x[100000], y[100000];
int N;


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &x[i]);
        }
        for(int i = 0; i < N; ++i) {
            scanf("%d", &y[i]);
        }
        int cnt0 = 0;
        multiset<int> gp; // good person;
        multiset<int> bp; // bad person;
        for(int i = 0; i < N; ++i) {
            int d = y[i] - x[i];
            if (d == 0) ++cnt0;
            else if (d > 0) {
                gp.insert(d);
            }
            else {
                bp.insert(-d);
            }
        }
        printd("cnt0: %d\n", cnt0);


        int overallcnt = 0;
        while(gp.size() > 0 && bp.size() > 0) {
            printd("cur size: %d vs %d...\n", gp.size(), bp.size());
            auto gcan = gp.begin();
            auto bcan = bp.begin();
            if (*gcan > *bcan) {
                bcan = bp.upper_bound(*gcan);
                if (bcan == bp.begin()) { // 더 작은걸 못찾음
                    int v1 = *gcan;
                    int v2 = *bcan;
                    while (v1 < v2) {
                        ++gcan;
                        if (gcan == gp.end()) {
                            goto END;
                        }
                        v1 += *gcan;
                    }
                    if (v1 < v2) goto END;
                    auto p = gp.begin();
                    printd("Erase ...\n");
                    while (p != gcan) {
                        auto cit = p;
                        ++p;
                        printd("%d ", *cit);
                        gp.erase(cit);
                    }
                    printd("vs %d\n", *bcan);
                    bp.erase(bcan);
                    ++overallcnt;
                } else { // 찾음
                    --bcan;
                    printd("Erase %d vs %d!\n", *gcan, *bcan);
                    gp.erase(gcan);
                    bp.erase(bcan);
                    ++overallcnt;
                }
            } else if (*gcan < *bcan) {
                gcan = gp.lower_bound(*bcan);
                if (gcan == gp.end()) { // 더 작은걸 못찾음
                    --gcan;
                    int v1 = *gcan;
                    int v2 = *bcan;
                    printd("v1: %d / v2: %d\n", v1, v2);
                    while (v1 < v2) {
                    printd("v1: %d / v2: %d\n", v1, v2);
                        if (gcan == gp.begin()) {
                            goto END;
                        }
                        --gcan;
                        v1 += *gcan;
                    }
                    printd("v1: %d / v2: %d\n", v1, v2);
                    if (v1 < v2) goto END;
                    auto p = bp.begin();
                    printd("Erase ...\n");
                    while (p != gp.end()) {
                        auto cit = p;
                        ++p;
                        printd("%d ", *cit);
                        gp.erase(cit);
                    }
                    printd("vs %d\n", *bcan);
                    bp.erase(bcan);
                    ++overallcnt;
                } else { // 찾음
                    printd("Erase %d vs %d!\n", *gcan, *bcan);
                    gp.erase(gcan);
                    bp.erase(bcan);
                    ++overallcnt;
                }
            } else { // 같은 case
                printd("Erase %d vs %d!\n", *gcan, *bcan);
                gp.erase(gcan);
                bp.erase(bcan);
                ++overallcnt;
            }
        }
END:
        if (gp.size() >= cnt0) {
            overallcnt += gp.size();
            cnt0 -= gp.size();
            printd("Added %d due to the cnt0!\n", gp.size());
        }
        cnt0 &= ~1;
        overallcnt += cnt0 / 2;
        printf("%d\n", overallcnt);
        continue;
    }
MAIN_END
