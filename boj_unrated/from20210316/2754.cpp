#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int convert(char g[]) {
    int r = 0;
    if (g[1] == '+') {
        r += 30;
    } else if (g[1] == '-') {
        r -= 30;
    }
    if (g[0] == 'A') {
        r += 400;
    } else if (g[0] == 'B') {
        r += 300;
    } else if (g[0] == 'C') {
        r += 200;
    } else if (g[0] == 'D') {
        r += 100;
    } else if (g[0] == 'F') {
        r = 0;
    }
    return r;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    char grade[3] = {0, };
    scanf("%s", grade);
    printf("%1.1lf\n", (double) convert(grade) / 100);
    printd("--------------------------");
MAIN_END

/*
학점계산 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	4704	2893	2699	63.942%
문제
어떤 사람의 C언어 성적이 주어졌을 때, 평점은 몇 점인지 출력하는 프로그램을 작성하시오.

A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0

입력
첫째 줄에 C언어 성적이 주어진다. 성적은 문제에서 설명한 13가지 중 하나이다.

출력
첫째 줄에 C언어 평점을 출력한다.

예제 입력 1 
A0
예제 출력 1 
4.0
*/
