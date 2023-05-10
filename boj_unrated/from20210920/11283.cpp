#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
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
    char input[4];
    scanf("%s", input);
    printd("%s", input);
    // printf("%d\n", input[0] - '가' + 1);
    int cho = (input[0] & 0x0F) << 12;
    int jung = (input[1] & 0x3F) << 6;
    int jong = input[2] & 0x3F;
    printf("%d\n", cho + jung + jong - 0xABFF);
    // input[2] += 1;
    // printf("%s\n", input);
MAIN_END


/*
한글 2
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	1935	1393	1303	77.467%
문제
한글의 각 글자는 초성, 중성, 종성으로 이루어져 있고, 이 세 가지를 모아써서 한 글자를 나타낸다.

초성은 ㄱ, ㄲ, ㄴ, ㄷ, ㄸ, ㄹ, ㅁ, ㅂ, ㅃ, ㅅ, ㅆ, ㅇ, ㅈ, ㅉ, ㅊ, ㅋ, ㅌ, ㅍ, ㅎ로 총 19개가 있고, 중성은 ㅏ, ㅐ, ㅑ, ㅒ, ㅓ, ㅔ, ㅕ ㅖ, ㅗ, ㅘ, ㅙ, ㅚ, ㅛ, ㅜ, ㅝ, ㅞ, ㅟ, ㅠ, ㅡ, ㅢ, ㅣ로 총 21개, 종성은 없음, ㄱ, ㄲ, ㄳ, ㄴ, ㄵ, ㄶ, ㄷ, ㄹ, ㄺ, ㄻ, ㄼ, ㄽ, ㄾ, ㄿ, ㅀ, ㅁ, ㅂ, ㅄ, ㅅ, ㅆ, ㅇ, ㅈ, ㅊ, ㅋ, ㅌ, ㅍ, ㅎ로 총 28개가 있다.

첫 번째 글자는 초성에서 ㄱ, 중성에서 ㅏ, 종성에서 없음을 합친 "가"가 되고, 두 번째 글자는 초성에서 ㄱ, 중성에서 ㅏ, 종성에서 ㄱ을 합친 "각"이 된다. 마지막 글자는 초성에서 ㅎ, 중성에서 ㅣ, 종성에서 ㅎ를 합친 "힣"이 된다.

초성과 중성, 그리고 종성을 합쳐서 만들 수 있는 글자의 개수는 총 19*21*28 = 11,172개가 된다.

한글이 주어졌을 때, 몇 번째 글자인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 글자 하나가 주어진다. 주어지는 글자는 UTF-8로 인코딩 되어 있는 한글이며, 문제 설명에 나온 방법으로 만들 수 있다.

출력
입력으로 주어진 글자가 몇 번째인지 출력한다.

예제 입력 1 
가
예제 출력 1 
1
예제 입력 2 
힣
예제 출력 2 
11172
예제 입력 3 
백
예제 출력 3 
4146
예제 입력 4 
준
예제 출력 4 
7425
*/
