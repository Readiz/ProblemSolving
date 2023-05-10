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



MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int t1 = abs(a - 1);
        int t2 = abs(b - c) + abs(c - 1);
        if (t1 < t2) {
            printf("1\n");
        } else if (t1 > t2) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
MAIN_END
