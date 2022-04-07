#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("A_input.txt", "rt", stdin); }
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

void printcb(int cb) {
    for (int i = 0; i < cb; i++) {
        printf("()");
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int n;
        scanf("%d", &n);
        for (int cb = 0; cb <= n - 2; cb++) {
            printcb(cb);
            int rb = n - cb;
            for (int i = 0; i < rb; i++) {
                printf("(");
            }
            for (int i = 0; i < rb; i++) {
                printf(")");
            }
            printf("\n");
        }
        printcb(n); printf("\n");
    }
MAIN_END
