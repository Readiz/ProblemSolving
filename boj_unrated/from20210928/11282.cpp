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
    int v;
    scanf("%d", &v);
    v += 0xABFF;
    printd("%d", v);
    printd("%x", v);

    int a = v >> 12;
    printd("%x", a);
    int b = (v >> 8) & 0x0F;
    printd("%x", b);
    int c = (v >> 4) & 0x0F;
    printd("%x", c);
    int d = v & 0x0F;
    printd("%x", d);

    char output[4];
    output[0] = a | 0xE0;
    output[1] = ((b << 2) + (c >> 2)) | 0x80;
    output[2] = (((c & 0x03) << 4) + d) | 0x80;
    output[3] = 0;
    printd("RESULT: %02hhx %02hhx %02hhx %02hhx", output[0], output[1], output[2], output[3]);
    printf("%s\n", output);

    // char test[4] = "각"; // 44032 -> 0xAC00
    // printd("TEST: %02hhx %02hhx %02hhx %02hhx", test[0], test[1], test[2], test[3]);
    // char test2[4] = "나"; // 0xB098
    // printd("%02hhx %02hhx %02hhx %02hhx", test2[0], test2[1], test2[2], test2[3]);
    // char test3[4] = "힣";
    // printd("%02hhx %02hhx %02hhx %02hhx", test3[0], test3[1], test3[2], test3[3]);
    
    // int cho = (input[0] & 0x0F) << 12;
    // int jung = (input[1] & 0x3F) << 6;
    // int jong = input[2] & 0x3F;
    // int cho = (test[0] & 0x0F) << 12;
    // int jung = (test[1] & 0x3F) << 6;
    // int jong = test[2] & 0x3F;
    // printf("%d\n", cho + jung + jong); // - 0xABFF);
    //printf("%s\n", output);
MAIN_END


/*
한글
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	1367	854	783	66.412%
문제
한글의 각 글자는 초성, 중성, 종성으로 이루어져 있고, 이 세 가지를 모아써서 한 글자를 나타낸다.

초성은 ㄱ, ㄲ, ㄴ, ㄷ, ㄸ, ㄹ, ㅁ, ㅂ, ㅃ, ㅅ, ㅆ, ㅇ, ㅈ, ㅉ, ㅊ, ㅋ, ㅌ, ㅍ, ㅎ로 총 19개가 있고, 중성은 ㅏ, ㅐ, ㅑ, ㅒ, ㅓ, ㅔ, ㅕ ㅖ, ㅗ, ㅘ, ㅙ, ㅚ, ㅛ, ㅜ, ㅝ, ㅞ, ㅟ, ㅠ, ㅡ, ㅢ, ㅣ로 총 21개, 종성은 없음, ㄱ, ㄲ, ㄳ, ㄴ, ㄵ, ㄶ, ㄷ, ㄹ, ㄺ, ㄻ, ㄼ, ㄽ, ㄾ, ㄿ, ㅀ, ㅁ, ㅂ, ㅄ, ㅅ, ㅆ, ㅇ, ㅈ, ㅊ, ㅋ, ㅌ, ㅍ, ㅎ로 총 28개가 있다.

첫 번째 글자는 초성에서 ㄱ, 중성에서 ㅏ, 종성에서 없음을 합친 "가"가 되고, 두 번째 글자는 초성에서 ㄱ, 중성에서 ㅏ, 종성에서 ㄱ을 합친 "각"이 된다. 마지막 글자는 초성에서 ㅎ, 중성에서 ㅣ, 종성에서 ㅎ를 합친 "힣"이 된다.

초성과 중성, 그리고 종성을 합쳐서 만들 수 있는 글자의 개수는 총 19*21*28 = 11,172개가 된다.

입력으로 N이 주어졌을 때, N번째 글자를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 11,172)이 주어진다.

출력
첫째 줄에 N번째 글자를 출력한다. 문자열의 인코딩은 UTF-8을 사용해야 한다.

예제 입력 1 
1
예제 출력 1 
가
예제 입력 2 
11172
예제 출력 2 
힣
예제 입력 3 
4146
예제 출력 3 
백
예제 입력 4 
7425
예제 출력 4 
준
*/
