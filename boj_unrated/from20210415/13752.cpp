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
#define R register
typedef unsigned long long ull;
typedef long long ll;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int T = 0; T < tc; T++) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            printf("=");
        }
        printf("\n");
    }
MAIN_END


/*
히스토그램 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	2233	1919	1762	87.271%
문제
히스토그램은 데이터를 시각적으로 표현한 것이다. 막대로 구성되며 각 막대의 길이는 데이터 양의 크기를 나타낸다. 일부 데이터가 주어지면 히스토그램을 생성하시오.

입력
첫 번째 줄에는 테스트 케이스의 개수 n (1 ≤ n ≤ 100)이 주어진다. 다음 n 개의 줄에는 각 히스토그램의 크기 k (1 ≤ k ≤ 80)가 주어진다.

출력
각 테스트 케이스에 대해서 히스토그램의 크기 k와 동일한 수의 '='를 출력한다. '='사이에 공백은 존재하지 않는다.

예제 입력 1 
5
1
3
4
6
2
예제 출력 1 
=
===
====
======
==
*/
