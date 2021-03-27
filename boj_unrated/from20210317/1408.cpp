#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("1408_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int atoi(char a1, char a2) {
    return (a1 - '0') * 10 + (a2 - '0');
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    char s[30] = {0, };
    char t[30] = {0, };
    scanf("%s", s);
    scanf("%s", t);
    printd("%s", s);
    printd("%s", t);
    printd("--------------------------");
    int hh = atoi(s[0], s[1]);
    int mm = atoi(s[3], s[4]);
    int ss = atoi(s[6], s[7]);
    int thh = atoi(t[0], t[1]);
    int tmm = atoi(t[3], t[4]);
    int tss = atoi(t[6], t[7]);
    
    tss -= ss; tmm -= mm; thh -= hh;
    while (tss < 0 || tmm < 0 || thh < 0) {
        if (tss < 0) {
            tss += 60;
            tmm --;
        }
        if (tmm < 0) {
            tmm += 60;
            thh --;
        }
        if (thh < 0) {
            thh += 24;
        }
    }
    printf("%02d:%02d:%02d\n", thh, tmm, tss);
MAIN_END



/*
문제
도현이는 Counter Terror Unit (CTU)에서 일하는 특수요원이다. 도현이는 모든 사건을 정확하게 24시간이 되는 순간 해결하는 것으로 유명하다. 도현이는 1시간 만에 범인을 잡을 수 있어도 잡지 않는다. 정확하게 24시간이 되는 순간이 아니면 잡지 않는 CTU 특수요원이다.

2008년 3월 3일 월요일, CTU는 새학기에 맞춰 핵폭탄을 날리겠다는 테러 정보를 입수했다. CTU에서는 특수요원 도현이에게 이 임무를 맡겼다. CTU의 프로그래머 준규는 이 사건의 배후가 김선영이란 것을 해킹을 통해 밝혀내었다.

도현이는 선영이를 임무를 시작한지 정확하게 24시간이 되는 순간에 잡으려고 한다.

만약 지금 시간이 13:52:30이고, 임무를 시작한 시간이 14:00:00 이라면 도현이에게 남은시간은 00:07:30 이다.

모든 시간은 00:00:00 ~ 23:59:59로 표현할 수 있다. 입력과 출력에 주어지는 모든 시간은 XX:XX:XX 형태이며, 숫자가 2자리가 아닐 경우에는 0으로 채운다.

도현이가 임무를 시작한 시간과, 현재 시간이 주어졌을 때, 도현이에게 남은 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 현재 시간이, 둘째 줄에는 도현이가 임무를 시작한 시간이 주어진다. 임무를 시작한 시간과 현재 시간이 같은 경우는 주어지지 않는다.

출력
첫째 줄에 도현이가 임무를 수행하는데 남은 시간을 문제에서 주어지는 시간의 형태 (XX:XX:XX)에 맞춰 출력한다.

예제 입력 1 
13:52:30
14:00:00
예제 출력 1 
00:07:30
*/
