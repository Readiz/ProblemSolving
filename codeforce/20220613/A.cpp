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
    for (R int TC = 0; TC < tc; TC++) {
        R int a, b;
        scanf("%d", &a);
        b = a % 1000;
        a = a / 1000;
        R char x = 0;
        R char y = 0;
        x += a % 10;
        a /= 10;
        x += a % 10;
        a /= 10;
        x += a % 10;

        y += b % 10;
        b /= 10;
        y += b % 10;
        b /= 10;
        y += b % 10;

        if (x == y) printf("YES\n");
        else printf("NO\n");

    }
MAIN_END

