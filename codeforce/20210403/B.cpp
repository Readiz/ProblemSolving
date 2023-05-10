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

char A[300001], B[300001];

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int len;
        scanf("%d", &len);
        scanf("%s", A);
        scanf("%s", B);

        int diffPos = -1;
        int count0, count1;
        bool canBeSame = true;
        int sameCount = 0;
        int swapCount = 0;
        // 뒤부터 판별
        for (int i = len; i >= 0; i--) {
            if (diffPos == -1 && A[i] == B[i]) {
                sameCount++;
                continue;
            }
            else if (diffPos != -1 && A[i] == B[i]) {
                sameCount++;
                if (count0 == count1) {
                    // 이 때는 swap 하여 같아지는 case, skip 가능.
                    printd("There is different area, but can make same.");
                    swapCount++;
                } else {
                    // 같아질 수 없는 case. flag set.
                    printd("There is different area, and cannot make it same.");
                    canBeSame = false;
                    break;
                }
                diffPos = -1;
            }
            else {
                // 처음 달라지는 부분 catch
                if (diffPos == -1) {
                    printd("sameCount: %d / swapCount: %d", sameCount, swapCount);
                    // 같은 부분에 대한 check. Swap 횟수가 홀수면 실패.
                    if (swapCount % 2 == 1 && sameCount % 2 == 1) {
                        printd("Same area inverted by odd tries, cannot make same.");
                        canBeSame = false;
                        break;
                    } else if (sameCount % 2 == 0) {
                        swapCount++;
                    }
                    sameCount = 0;

                    printd("A and B are differnt start at %d", i);
                    diffPos = i;
                    if (A[i] == '0') {
                        count0 = 1;
                        count1 = 0;
                    } else {
                        count0 = 0;
                        count1 = 1;
                    }
                    // 처음에는 swappable 하지 않다. 그러므로 추가 행동 X
                } else {
                    // 계속 다르고 있는 중
                    if (A[i] == '0') count0++;
                    else count1++;
                }
            }
        }
        if (diffPos != -1) {
            if (count0 == count1) {
                // 이 때는 swap 하여 같아지는 case, skip 가능.
                printd("There is different area, but can make same.");
                swapCount++;
            } else {
                // 같아질 수 없는 case. flag set.
                printd("There is different area, and cannot make it same.");
                canBeSame = false;
            }
        } else {
            printd("sameCount: %d / swapCount: %d", sameCount, swapCount);
            // 같은 부분에 대한 check. Swap 횟수가 홀수면 실패.
            if (swapCount % 2 == 1 && sameCount % 2 == 1) {
                printd("Same area inverted by odd tries, cannot make same.");
                canBeSame = false;
            } else if (sameCount % 2 == 0) {
                swapCount++;
            }
        }
        if (canBeSame) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
MAIN_END
