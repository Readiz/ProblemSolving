#include <stdio.h>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
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

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int N;
        scanf("%d", &N);
        printd("N: %d", N);
        vector<int> sheep;
        char s[1000001];
        scanf("%s", s);
        for (R int i = 0; i < N; i++) {
            char c = s[i];
            if (c == '*') {
                printd("sheep detected at: %d", i);
                sheep.push_back(i);
            }
        }
        if (sheep.size() <= 1) {
            printd("# of sheeps: 0 or 1, continue...");
            printf("0\n");
            continue;
        }
        ull ss = 0ULL;
        for (auto const& a : sheep) {
            ss += a * a;
        }
        ss /= sheep.size();
        printd("squareSum: %llu", ss);
        ull lowerSquare, upperSquare;
        ull p = 1ULL;
        while (ss >= p * p) {
            p++;
        }
        lowerSquare = p - 1;
        upperSquare = p;
        printd("p: %llu, l: %llu, u: %llu", p, lowerSquare, upperSquare);
        vector<int> wish;
        int startPos = lowerSquare - (sheep.size() / 2);
        ull ans = 0ULL;
        for (R int i = 0; i < sheep.size(); i++) {
            int ap = startPos + i;
            wish.push_back(ap);
            if (ap < sheep[i]) {
                ans += sheep[i] - ap;
            } else {
                ans += ap - sheep[i];
            }
        }

        printf("%llu\n", ans);
    }
MAIN_END
