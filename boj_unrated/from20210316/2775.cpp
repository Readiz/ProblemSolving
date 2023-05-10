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
    int T;
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d", &T);
    printd("Input - T: %d", T);
    int sum = 0;
    int mulSum = 0;
    for (int i = 0; i < T; i++) {
        char str[101];
        int mul;
        char grade[3] = {0, };
        scanf("%s %d %s", str, &mul, grade);
        sum += mul * convert(grade);
        mulSum += mul;
    }
    printd("MulSum: %d", mulSum);
    printd("Mean: %d", sum / mulSum);
    printd("Remain: %d", sum % mulSum);
    int mean = sum / mulSum;
    int remain = sum % mulSum;
    if (remain * 2 >= mulSum) { // 반올림
        mean += 1;
    }
    printf("%1.2lf\n", (double) mean / 100);
    printd("--------------------------");
MAIN_END

/*
이번학기 평점은 몇점? 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	3172	1054	917	34.748%
문제
최백준이 이번 학기에 들은 과목과 학점 그리고 성적이 주어졌을 때, 평균 평점을 계산하는 프로그램을 작성하시오.

성적은 A+~F까지 총 13개가 있다.

A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0

평균 평점은 각 과목의 학점*성적을 모두 더한 뒤에, 총 학점으로 나누면 된다.

입력
첫째 줄에, 백준이가 이번 학기에 들은 과목 수가 주어진다. 둘째 줄부터 N개의 줄에 각 과목의 과목명, 학점, 성적이 주어진다. 과목명은 알파벳 소문자와 숫자, 그리고 밑줄 (_)로만 이루어져 있으며, 최대 100글자이고, 학점은 1보다 크거나 같고, 3보다 작거나 같은 자연수이다. 성적은 문제에 설명한 13가지 중 하나이다. 

출력
첫째 줄에 평균 평점을 소수점 셋째 자리에서 반올림해서 둘째 자리까지 출력한다. (평균 평점이 1.5이면 1.50을 출력한다.)

예제 입력 1 
7
General_Physics_1 3 A+
Introduction_to_Computer_Science_and_Eng 3 B0
Reading_And_Writing 2 C0
English_1 3 C+
Analytic_Geometry_and_Calculus_1 3 B+
Fortran_Programming 3 B+
C_Language_Programming 3 A+
예제 출력 1 
3.28
*/
