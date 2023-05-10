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

int count[26] = {0, };
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    char str[101] = {0, };
    int len = fio::readString(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] += 'A' - 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= 'A' - 'a';
        }
    }
    printf("%s\n", str);
MAIN_END



/*
대소문자 바꾸기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	4935	3846	3524	79.477%
문제
영어 소문자와 대문자로 이루어진 단어를 입력받은 뒤, 대문자는 소문자로, 소문자는 대문자로 바꾸어 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 영어 소문자와 대문자로만 이루어진 단어가 주어진다. 단어의 길이는 최대 100이다.

출력
첫째 줄에 입력으로 주어진 단어에서 대문자는 소문자로, 소문자는 대문자로 바꾼 단어를 출력한다.

예제 입력 1 
WrongAnswer
예제 출력 1 
wRONGaNSWER
*/
