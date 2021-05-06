#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("B_input.txt", "rt", stdin); }
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
    vector<ull> checker;
    for (ull k = 1ULL; k < 10'000'000'000ULL; k *= 10ULL) {
        ull initNum = k;
        ull l = k / 10ULL;
        while (l > 0) {
            initNum += l;
            l /= 10ULL;
        }
        for (int i = 1; i <= 9; i++) {
            checker.push_back(initNum * i);
        }
    }
    // for (auto const & n : checker) {
    //     printf("%llu ", n);
    // }
    // printf("\n");

    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        ull N;
        scanf("%llu", &N);
        auto idx = upper_bound(checker.begin(), checker.end(), N);
        printd("N: %d", N);
        printd("idx diff = %d", idx - checker.begin());
        printf("%d\n", idx - checker.begin());
    }
MAIN_END
