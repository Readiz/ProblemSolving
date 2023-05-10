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

namespace fio {
    int readString(char s[]) {
        int ptr = 0;
        while (true) {
            char c = getchar();
            if (c != '\n' && c != EOF) {
                s[ptr++] = c;
            } else {
                s[ptr] = 0;
                break;
            }
        }
        return ptr;
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int T;
    scanf("%d", &T);
    getchar(); // 숫자 뒤 \n 제거 용
    printd("--------------------------");
    char str[1001] = {0, };
    for (int tc = 0; tc < T; tc++) {
        int len = fio::readString(str);
        printf("%c%c\n", str[0], str[len - 1]);
    }
MAIN_END

/*
문자열 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	3989	3049	2762	77.541%
문제
문자열을 입력으로 주면 문자열의 첫 글자와 마지막 글자를 출력하는 프로그램을 작성하시오.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스는 한 줄에 하나의 문자열이 주어진다. 문자열은 알파벳 A~Z 대문자로 이루어지며 알파벳 사이에 공백은 없으며 문자열의 길이는 1000보다 작다.

출력
각 테스트 케이스에 대해서 주어진 문자열의 첫 글자와 마지막 글자를 연속하여 출력한다.

예제 입력 1 
3
ACDKJFOWIEGHE
O
AB
예제 출력 1 
AE
OO
AB
*/
