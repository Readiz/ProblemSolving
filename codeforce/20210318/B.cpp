#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        char str[101] = {0, };
        scanf("%s", str);
        char lastChar = str[0];
        bool isElevenAppeared = false; // After this, "00" is not allowed.
        bool isNO = false;
        for (int p = 1; str[p] != 0; p++) {
            if (lastChar != str[p]) {
                lastChar = str[p];
                continue;
            }
            if (!isElevenAppeared) {
                if (lastChar == '0' && str[p] == '0') continue;
                else isElevenAppeared = true;
            } else {
                if (lastChar == '1' && str[p] == '1') continue;
                else {
                    isNO = true;
                    break;
                }
            }
        }
        if (isNO) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
MAIN_END
