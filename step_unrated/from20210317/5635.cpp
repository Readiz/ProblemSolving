#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("5635_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

void strcpy(char target[], char original[]) {
    int p;
    for (p = 0; original[p] != 0; p++) {
        target[p] = original[p];
    }
    target[p] = 0;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");

    int T;
    scanf("%d", &T);
    printd("--------------------------");
    char maxName[20] = {0, };
    char minName[20] = {0, };
    int maxVal = -1;
    int minVal = 0x7FFFFFF;
    for (int tc = 0; tc < T; tc++) {
        char tmpName[20];
        int dd, mm, yyyy;
        scanf("%s %d %d %d", tmpName, &dd, &mm, &yyyy);
        int val = yyyy * 10000 + mm * 100 + dd;
        if (minVal > val) {
            minVal = val;
            strcpy(minName, tmpName);
        }
        if (maxVal < val) {
            maxVal = val;
            strcpy(maxName, tmpName);
        }
    }
    printf("%s\n%s\n", maxName, minName);
MAIN_END


/*
생일 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	2403	1703	1549	73.447%
문제
어떤 반에 있는 학생들의 생일이 주어졌을 때, 가장 나이가 적은 사람과 가장 많은 사람을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 반에 있는 학생의 수 n이 주어진다. (1 ≤ n ≤ 100)

다음 n개 줄에는 각 학생의 이름과 생일이 "이름 dd mm yyyy"와 같은 형식으로 주어진다. 이름은 그 학생의 이름이며, 최대 15글자로 이루어져 있다. dd mm yyyy는 생일 일, 월, 연도이다. (1990 ≤ yyyy ≤ 2010, 1 ≤ mm ≤ 12, 1 ≤ dd ≤ 31) 주어지는 생일은 올바른 날짜이며, 연, 월 일은 0으로 시작하지 않는다.

이름이 같거나, 생일이 같은 사람은 없다.

출력
첫째 줄에 가장 나이가 적은 사람의 이름, 둘째 줄에 가장 나이가 많은 사람 이름을 출력한다.

예제 입력 1 
5
Mickey 1 10 1991
Alice 30 12 1990
Tom 15 8 1993
Jerry 18 9 1990
Garfield 20 9 1990
예제 출력 1 
Tom
Jerry
*/
