#include <stdio.h>
#include <bits/stdc++.h>
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

char buf[100];
char LUT[1000];
char ans[10010];
int ap;
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");

    // 전처리
    for(char c = 'a'; c <= 'z'; ++c) {
        int idx = c - 'a' + 1;
        LUT[idx] = c;
    }

    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        ap = 0;
        int len;
        scanf("%d", &len);
        scanf("%s", buf);

        for(R int i = len - 1; i >= 0; --i) {
            if (buf[i] == '0') {
                int idx = (buf[i - 1] - '0') + (buf[i - 2] - '0') * 10;
                ans[ap++] = LUT[idx];
                i -= 2;
            } else {
                ans[ap++] = LUT[buf[i] - '0'];
            }
        }
        for(R int i = ap - 1; i >= 0; --i) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
MAIN_END
