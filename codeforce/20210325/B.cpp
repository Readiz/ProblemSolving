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

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int n, k;
        scanf("%d %d", &n, &k);
        char s[100] = {0, };
        scanf("%s", s);
        printd("%s", s);
        int leftPtr = 0, rightPtr = n - 1;
        int lastLeftPos = -1, lastRightPos = -1;
        int count = 0;
        // replace last right one.
        while (true) {
            if (s[rightPtr] == '*') {
                s[rightPtr] = 'x';
                lastRightPos = rightPtr;
                count++;
                break;
            }
            rightPtr--;
        }
        while (lastRightPos > leftPtr) {
            if (s[leftPtr] == '*') {
                s[leftPtr] = 'x';
                lastLeftPos = leftPtr;
                count++;
                leftPtr += k;
                if (leftPtr >= lastRightPos) break;
                while (s[leftPtr--] != '*');
            }
            printd("New: %s", s);
            leftPtr++;
        }
        // last check..
        if (lastLeftPos != -1 && lastRightPos != -1) {
            if (lastRightPos - lastLeftPos > k) {
                count++;
            }
        }
        printd("%s", s);
        printf("%d\n", count);
    }
    return 0;
MAIN_END
