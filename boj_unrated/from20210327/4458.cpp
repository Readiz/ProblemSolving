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
    char str[31] = {0, };
    for (int tc = 0; tc < T; tc++) {
        int len = fio::readString(str);
        if (str[0] >= 'a' && str[0] <= 'z') {
            str[0] += 'A' - 'a';
        }
        printf("%s\n", str);
    }
MAIN_END
/*
첫 글자를 대문자로 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	5823	2662	2343	47.787%
문제
문장을 읽은 뒤, 줄의 첫 글자를 대문자로 바꾸는 프로그램을 작성하시오.

입력
첫째 줄에 줄의 수 N이 주어진다. 다음 N개의 줄에는 문장이 주어진다. 각 문장에 들어있는 글자의 수는 30을 넘지 않는다. 모든 줄의 첫 번째 글자는 알파벳이다.

출력
각 줄의 첫글자를 대문자로 바꾼뒤 출력한다.

예제 입력 1 
5
powdered Toast Man
skeletor
Electra Woman and Dyna Girl
she-Ra Princess of Power
darth Vader
예제 출력 1 
Powdered Toast Man
Skeletor
Electra Woman and Dyna Girl
She-Ra Princess of Power
Darth Vader
*/
