#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); }
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
        multiset<int, greater<>> gp; // good person;
        multiset<int, greater<>> bp; // bad person;
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
        printd("GP\n");
        for(auto& item: gp) {
            printd("%d\n", item);
        }
        printd("BP\n");
        for(auto& item: bp) {
            printd("%d\n", item);
        }
        printd("cnt0: %d\n", cnt0); // 0은 특별취급

        int overallcnt = 0;
        while (gp.size() > 0 && bp.size() > 0) {
            auto git = gp.begin();
            auto bit = bp.begin();
            if (*git >= *bit) {
                printd("Erase %d vs %d...\n", *git, *bit);
                gp.erase(git);
                bp.erase(bit);
                ++overallcnt;
            } else {
                bp.erase(bit);
            }
        }

        printd("Remainder: %d + 0: %d\n", gp.size(), cnt0);

        overallcnt += (gp.size() + cnt0) >> 1;

        printf("%d\n", overallcnt);
    }
MAIN_END
