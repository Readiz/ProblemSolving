#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
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
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
// 곱셈시 오버플로 안나는 한계값. 2^64 가 두개가 곱해지니, 그것의 절반만 가지고 다녀야 함
#define MAXVAL_WITHOUT_OVERFLOW 100'000'000'000'000'000
typedef __uint128_t ulll;

void printULLL(ulll a, bool isFirst) {
    char buf[100] = {0, }; int p = 0;
    for (int i = 0; i < 17; i++) { // 17: 출력해야할 최소 자리수
        buf[p++] = a % 10 + '0';
        a /= 10;
    }
    // 거꾸로 출력
    bool isFirstNotZeroAppeared = !isFirst;
    for (int i = 16; i >= 0; i--) {
        if (buf[i] != '0') isFirstNotZeroAppeared = true;
        if (isFirstNotZeroAppeared) printf("%c", buf[i]);
    }
}

int assignULLL(ulll T[], char c[]) {
    ulll mul = 1;
    int len;
    for (len = 0; c[len] != 0; len++); // len 돌리기
    printd("len: %d", len);
    int p = 0;
    // 거꾸로 assign 한다.
    for (int i = len - 1; i >= 0; i--) {
        T[p] += (c[i] - '0') * mul;
        mul *= 10;
        // 담을 수 있을 만큼 담았으면, 다음 자리로 넘어간다.
        if (mul == MAXVAL_WITHOUT_OVERFLOW) {
            p++;
            mul = 1;
        }
    }
    return p; // 전체 사용한 T 배열 양 리턴..
}


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");

    // A, B: 값을 collapse해서 저장하는 곳..
    ulll A[20000] = {0, }, B[20000] = {0, }, R[40000] = {0, };
    char bufA[300001], bufB[300001];
    scanf("%s %s", bufA, bufB);
    printd("A: %s B: %s", bufA, bufB);
    if (bufA[0] == '0' || bufB[0] == '0') printf("0\n");
    else {
        int assignedA = assignULLL(A, bufA);
        int assignedB = assignULLL(B, bufB);
        int assignedR = assignedA + assignedB;
        printd("AssignedA: %d, AssignedB: %d / AssignedR: %d", assignedA, assignedB, assignedR);
        for (int i = 0; i <= assignedA; i++) {
            for (int j = 0; j <= assignedB; j++) {
                R[i + j] += A[i] * B[j];
            }
        }
        // 올림 처리..
        int maxR = assignedR;
        for (int i = 0; i <= assignedR; i++) {
            ulll tmp = R[i] / MAXVAL_WITHOUT_OVERFLOW;
            if (tmp > 0) {
                R[i] -= tmp * MAXVAL_WITHOUT_OVERFLOW;
                R[i + 1] += tmp;
                if (maxR < (i + 1)) maxR = i + 1;
            }
        }
        printd("maxR: %d", maxR);
        bool isFirstNotZeroAppeared = false;
        for (int i = maxR; i >= 0; i--) {
            if (R[i] != 0) isFirstNotZeroAppeared = true;
            if (isFirstNotZeroAppeared) {
                if (i == maxR) printULLL(R[i], true);
                else printULLL(R[i], false);
            }
        }
        printf("\n");
    }
    
MAIN_END

/*
큰 수 곱셈 (2) 언어 제한분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	1015	374	207	37.705%
문제
두 정수 A와 B가 주어졌을 때, 두 수의 곱을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 A와 B가 주어진다. 두 정수는 0보다 크거나 같은 정수이며, 0을 제외한 정수는 0으로 시작하지 않으며, 수의 앞에 불필요한 0이 있는 경우도 없다. 또한, 수의 길이는 300,000자리를 넘지 않는다.

출력
두 수의 곱을 출력한다.

예제 입력 1 
1 2
예제 출력 1 
2
예제 입력 2 
3 4
예제 출력 2 
12
예제 입력 3 
893724358493284 238947328947329
예제 출력 3 
213553048277135320552236238436
*/
