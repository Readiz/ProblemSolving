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
    printd("--------------------------");
    char str[501] = {0, };
    while (true) {
        int len = fio::readString(str);
        if (len == 3 && str[0] == 'E' && str[1] == 'N' && str[2] == 'D') break;
        for (int i = 0; i < len / 2; i++) {
            char tmp = str[i];
            str[i] = str[len - i - 1];
            str[len - i - 1] = tmp;
        }
        printf("%s\n", str);
    }
MAIN_END


/*
!밀비 급일 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	6870	4151	3783	62.436%
문제
당신은 길을 가다가 이상한 쪽지를 발견했다. 그 쪽지에는 암호가 적혀 있었는데, 똑똑한 당신은 암호가 뒤집으면 해독된다는 것을 발견했다.

이 암호를 해독하는 프로그램을 작성하시오.

입력
한 줄에 하나의 암호가 주어진다. 암호의 길이는 500을 넘지 않는다.

마지막 줄에는 "END"가 주어진다. (END는 해독하지 않는다.)

출력
각 암호가 해독된 것을 한 줄에 하나씩 출력한다.

예제 입력 1 
!edoc doog a tahW
noitacitsufbo
erafraw enirambus detcirtsernu yraurbeF fo tsrif eht no nigeb ot dnetni eW
lla sees rodroM fo drol eht ,ssertrof sih nihtiw delaecnoC
END
예제 출력 1 
What a good code!
obfustication
We intend to begin on the first of February unrestricted submarine warfare
Concealed within his fortress, the lord of Mordor sees all
*/
