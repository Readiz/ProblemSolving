#include <stdio.h>
#include <unordered_set>
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

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int N;
        scanf("%d", &N);
        int A[200000];
        for (R int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        int ans = 0;
        int last = A[0];
        unordered_set<int> checker;
        for (R int i = 1; i < N; i++) {
            int Ai = A[i];
            if (Ai - last == 1) {
                checker.insert(i);
                checker.insert(i - 1);
            }
            last = Ai;
        }
        printf("%d\n", ans);
    }
MAIN_END
