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

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int A, B;
        scanf("%d %d", &A, &B);
        char s[200001];
        scanf("%s", s);
        printd("---------------------");
        printd("Original: %s", s);
        int len;
        for (len = 0; s[len] != 0; len++) {
            if (s[len] == '0') A--;
            else if(s[len] == '1') B--;
        }
        printd("Remained A: %d / B: %d", A, B);

        // 한쪽만 ?인 케이스를 먼저 처리
        bool canFillCaseA = true;
        for (int i = 0; i < len / 2; i++) {
            if (s[i] == '?' && (s[len - i - 1] == '0' || s[len - i - 1] == '1')) {
                if (s[len - i - 1] == '0') {
                    if (A > 0) {
                        s[i] = '0';
                        A--;
                    } else {
                        canFillCaseA = false;
                        break;
                    }
                } else {
                    if (B > 0) {
                        s[i] = '1';
                        B--;
                    } else {
                        canFillCaseA = false;
                        break;
                    }
                }
            } else if (s[len - i - 1] == '?' && (s[i] == '0' || s[i] == '1')) {
                if (s[i] == '0') {
                    if (A > 0) {
                        s[len - i - 1] = '0';
                        A--;
                    } else {
                        canFillCaseA = false;
                        break;
                    }
                } else {
                    if (B > 0) {
                        s[len - i - 1] = '1';
                        B--;
                    } else {
                        canFillCaseA = false;
                        break;
                    }
                }
            }
        }
        printd("After CaseA: %s", s);
        if (canFillCaseA == false) {
            printf("-1\n");
            continue;
        }

        bool canFillCaseB = true;
        for (int i = 0; i < len / 2; i++) {
            if (s[i] == '?' && s[len - i - 1] == '?') {
                if (A >= B && A >= 2) {
                    A -= 2;
                    s[i] = '0';
                    s[len - i - 1] = '0';
                } else if (B >= A && B >= 2) {
                    B -= 2;
                    s[i] = '1';
                    s[len - i - 1] = '1';
                } else {
                    canFillCaseB = false;
                    break;
                }
            }
        }
        printd("After CaseB: %s", s);
        if (canFillCaseB == false) {
            printf("-1\n");
            continue;
        }

        // Check Odd
        bool canFillCaseC = true;
        if (len & 1 == 1 && s[len / 2] == '?') {
            if (A > 0) {
                s[len / 2] = '0';
                A--;
            } else if (B > 0) {
                s[len / 2] = '1';
                B--;
            } else {
                canFillCaseC = false;
            }
        }
        printd("After CaseC: %s", s);
        printd("Remained A: %d / B: %d", A, B);
        if (canFillCaseC == false) {
            printf("-1\n");
            continue;
        }

        bool checkRemainUndefined = true;
        for (int i = 0; i < len; i++) {
            if (s[i] == '?') {
                checkRemainUndefined = false;
                break;
            }
        }
        if (checkRemainUndefined) {
            bool isOkay = true;
            for (int i = 0; i < len / 2; i++) {
                if (s[i] != s[len - i - 1]) {
                    isOkay = false;
                    break;
                }
            }
            if (isOkay && A == 0 && B == 0) { // 펠린드롬 && 쓴 수 체크
                printf("%s\n", s);
            } else {
                printf("-1\n");
            }
        } else {
            printf("-1\n");
        }
    }
    return 0;
MAIN_END
