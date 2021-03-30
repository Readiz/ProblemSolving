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
    printd("Len: %d, str: %s", p, num);
    return p;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N, M;
    char num[10] = {0, };
    scanf("%d %d", &N, &M);
    printd("--------------------------");
    char s[3000] = {0, };
    int p = 0;
    int len = itoa(num, N);
    while (p < 3000) {
        s[p] = num[p % len];
        p++;
    }
    for (int i = 0; i < MIN(len * N, M); i++) {
        printf("%c", s[i]);
    }
    printf("\n");
MAIN_END

/*
NN 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	32 MB	4256	1607	1455	39.962%
문제
문제는 매우 간단하다. N을 N번 출력하는 프로그램을 작성하여라. 다만, 답이 길어지는 경우 답의 앞 M자리만 출력한다.

입력
첫 번째 줄에는 N, M이 주어진다. (1 ≤ N, M ≤ 2016)

출력
N을 N번 출력한다. 만약 답이 길어지면 답의 앞 M자리를 출력한다.

예제 입력 1 
20 16
예제 출력 1 
2020202020202020
*/
