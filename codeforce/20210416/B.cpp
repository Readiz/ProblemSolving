#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("B_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;

char s[100001];
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int N;
        scanf("%d", &N);
        int leftT = 0; // 현 시점의 짝짓기가 가능한 T..
        int overallT = 0, overallM = 0;
        bool isPossible = true;
        scanf("%s", s);
        for (int i = 0; i < N; i++) {
            char a = s[i];
            if (a == 'T') {
                leftT++;
                overallT++;
            } else {
                if (leftT > 0) {
                    leftT--;
                } else {
                    isPossible = false;
                    break;
                }
                overallM++;
            }
        }
        // Check Reverse
        int rightT = 0;
        for (int i = N - 1; i >= 0; i--) {
            char a = s[i];
            if (a == 'T') {
                rightT++;
            } else {
                if (rightT > 0) {
                    rightT--;
                } else {
                    isPossible = false;
                    break;
                }
            }
        }
        if (isPossible == true && overallT == overallM * 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
MAIN_END
