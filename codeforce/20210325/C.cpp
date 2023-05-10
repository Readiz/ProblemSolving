#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int strlen(char s[]) {
    int p;
    for (p = 0; s[p] != 0; p++);
    return p;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        char a[30] = {0, }, b[30] = {0, };
        scanf("%s %s", a, b);
        int lenA = strlen(a);
        int lenB = strlen(b);
        // short is a
        if (lenA > lenB) {
            char* tmp = a;
            *a = *b;
            *b = *tmp;
            int tmp2 = lenA;
            lenA = lenB;
            lenB = tmp2;
        }

        int aStart = -1, aEnd = -1, bStart = -1, bEnd = -1;
        int i = 0, j = 0;
        while (true) {
            if (a[i] == b[j]) {
                i++; j++;
            }
        }
    }
    return 0;
MAIN_END
