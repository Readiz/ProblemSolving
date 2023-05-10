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
        printf("[DEBUG] No Online Judge detected!\n", fname);
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int itoa(char num[], int N) {
    int p = 0;
    while (N != 0) {
        num[p] = (N % 10) + '0';
        N /= 10;
        p++;
    }
    for (int i = 0; i < p / 2; i++) {
        char tmp = num[i];
        num[i] = num[p - i - 1];
        num[p - i - 1] = tmp;
    }
    num[p] = 0;
    printd("[ITOA] Len: %d, str: %s", p, num);
    return p;
}

void reverse(char s[]) {
    int p = 0;
    for (p = 0; s[p] != 0; p++);
    for (int i = 0; i < p / 2; i++) {
        char tmp = s[i];
        s[i] = s[p - i - 1];
        s[p - i - 1] = tmp;
    }
    printd("[REV] Len: %d, str: %s", p, s);
}

int atoi(char s[]) {
    int r = 0;
    for (int p = 0; s[p] != 0; p++) {
        r += s[p] - '0';
        r *= 10;
    }
    r /= 10;
    printd("[ATOI] num: %d", r);
    return r;
}



MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N, M;
    scanf("%d %d", &N, &M);
    printd("--------------------------");
    char numN[10] = {0, };
    char numM[10] = {0, };
    itoa(numN, N); itoa(numM, M); 
    reverse(numN); reverse(numM);
    int sum = atoi(numN) + atoi(numM);
    printd("[SUM] %d", sum);
    char result[10] = {0, };
    itoa(result, sum);
    reverse(result);
    printf("%d\n", atoi(result));
MAIN_END

/*
뒤집힌 덧셈 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	9857	4278	3803	44.768%
문제
어떤 수 X가 주어졌을 때, X의 모든 자리수가 역순이 된 수를 얻을 수 있다. Rev(X)를 X의 모든 자리수를 역순으로 만드는 함수라고 하자. 예를 들어, X=123일 때, Rev(X) = 321이다. 그리고, X=100일 때, Rev(X) = 1이다.

두 양의 정수 X와 Y가 주어졌을 때, Rev(Rev(X) + Rev(Y))를 구하는 프로그램을 작성하시오

입력
첫째 줄에 수 X와 Y가 주어진다. X와 Y는 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.

예제 입력 1 
123 100
예제 출력 1 
223
*/
