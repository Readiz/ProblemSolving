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
        char I[100];
        scanf("%s", I);
        printd("%s", I);
        int a = 0, b = 0, c = 0;
        for (R int i = 0; I[i] != 0; i++) {
            if (I[i] == 'A') a++;
            else if (I[i] == 'B') b++;
            else if (I[i] == 'C') c++;
        }
        printd("A: %d, B: %d, C: %d", a, b, c);
        if (a + c == b) printf("YES\n");
        else printf("NO\n");
    }
MAIN_END
