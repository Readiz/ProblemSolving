#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit(char fbasename[]) {
        char fname[100];
        char* ftailname = "_input.txt";
        int p;
        for (p = 0; fbasename[p] != 0; p++) fname[p] = fbasename[p];
        int t;
        for (t = 0; ftailname[t] != 0; t++) fname[p++] = ftailname[t];
        fname[p] = 0;
        printf("[DEBUG] No Online Judge detected!\n");
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

char A[10001] = {0, };
char B[10001] = {0, };
int C[10001];

int len(char s[]) {
    int p;
    for (p = 0; s[p] != 0; p++);
    return p;
}
void reverse(char s[]) {
    int l = len(s);
    for (int i = 0; i < l / 2; i++) {
        char tmp = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = tmp;
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%s %s", A, B);
    printd("A: %s, B:%s", A, B);
    printd("Reverse...");
    reverse(A); reverse(B);
    printd("A: %s, B:%s", A, B);
    printd("Sum...");
    int la = len(A), lb = len(B);
    int l = (la > lb)? la : lb;
    for (int i = 0; i < l; i++) { // 길이가 다를 수 있음
        int a = A[i] - '0';
        int b = B[i] - '0';
        if (a >= 0 && b >= 0) {
            C[i] = a + b;
        } else if (a >= 0) {
            C[i] = a;
        } else if (b >= 0) {
            C[i] = b;
        }
    }
    while (true) {
        bool noCarryLeft = true;
        for (int i = 0; i < l; i++) {
            if (C[i] >= 10) {
                noCarryLeft = false;
                C[i + 1] += C[i] / 10;
                C[i] %= 10;
            }
        }
        if (noCarryLeft == true) break;
    }
    printd("Print...");
    bool isNonFirstZeroAppeared = false;
    for (int i = 10000; i >= 0; i--) {
        if (isNonFirstZeroAppeared == false && C[i] != 0) {
            isNonFirstZeroAppeared = true;
        }
        if (isNonFirstZeroAppeared) {
            printf("%d", C[i]);
            if (C[i] >= 10) {
                printd("[ERROR] Carray Left!!!!");
            }
        }
    }
    printf("\n");

MAIN_END


/*
큰 수 A+B (2) 언어 제한분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	3123	1509	1288	55.589%
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

출력
첫째 줄에 A+B를 출력한다.

예제 입력 1 
9223372036854775807 9223372036854775808
예제 출력 1 
18446744073709551615
*/
