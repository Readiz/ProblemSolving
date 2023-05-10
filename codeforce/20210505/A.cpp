#include <stdio.h>
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
        char work[100];
        bool visited[30] = {false, };
        char lastChar = 0;
        bool isYes = true;
        int numChar;
        scanf("%d", &numChar);
        scanf("%s", work);
        printd("Check: %s", work);
        for (int p = 0; work[p] != 0; p++) {
            if (work[p] == lastChar) continue;
            lastChar = work[p];
            if (visited[lastChar - 'A'] == true) {
                isYes = false;
                break;
            }
            visited[lastChar - 'A'] = true;
        }
        if (isYes) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
MAIN_END
