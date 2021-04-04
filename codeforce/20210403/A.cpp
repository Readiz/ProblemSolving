#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("A_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

char A[300002];

bool checkIsAllA() {
    for (int i = 1; A[i] != 0; i++) {
        if (A[i] != 'a') return false;
    }
    return true;
}
bool isPanlindrome(char s[]) {
    int len;
    for (len = 0; s[len] != 0; len++);

    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        scanf("%s", &A[1]);
        if (checkIsAllA()) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        // 앞에 a 추가
        A[0] = 'a';
        if (!isPanlindrome(A)) {
            printf("%s\n", A);
        } else {
            printf("%sa\n", &A[1]);
        }
    }
    return 0;
MAIN_END
