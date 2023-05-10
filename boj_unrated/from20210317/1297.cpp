#include <stdio.h>
#include <cmath>
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
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int d, rh, rw;
    scanf("%d %d %d", &d, &rh, &rw);
    printd("--------------------------");
    double c = sqrt(rh * rh + rw * rw);
    double h = d * rh / c;
    double w = d * rw / c;
    printf("%d %d\n", (int) h, (int) w);
MAIN_END

/*
TV 크기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	5126	2670	2416	54.001%
문제
김탑은 TV를 사러 인터넷 쇼핑몰에 들어갔다. 쇼핑을 하던 중에, TV의 크기는 그 TV의 대각선의 길이로 나타낸 다는 것을 알았다. 하지만, 김탑은 대각선의 길이가 같다고 해도, 실제 TV의 크기는 다를 수도 있다는 사실에 직접 TV를 보러갈걸 왜 인터넷 쇼핑을 대각선의 길이만 보고있는지 후회하고 있었다.

인터넷 쇼핑몰 관리자에게 이메일을 보내서 실제 높이와 실제 너비를 보내달라고 했지만, 관리자는 실제 높이와 실제 너비를 보내지 않고 그것의 비율을 보내왔다.

TV의 대각선 길이와, 높이 너비의 비율이 주어졌을 때, 실제 높이와 너비의 길이를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 TV의 대각선 길이, TV의 높이 비율, TV의 너비 비율이 공백 한 칸을 사이에 두고 주어진다. 대각선 길이는 5보다 크거나 같고, 1,000보다 작거나 같은 자연수, 높이 비율은 1보다 크거나 같고, 99보다 작거나 같은 자연수 너비 비율은 2보다 크거나 같고, 100보다 작거나 같은 자연수이다. 너비 비율은 항상 높이 비율보다 크다.

출력
첫째 줄에 TV의 높이와 TV의 너비를 공백 한 칸을 이용해서 구분지은 후 출력한다. 만약, 실제 TV의 높이나 너비가 소수점이 나올 경우에는 그 수보다 작으면서 가장 큰 정수로 출력한다. (예) 1.7 -> 1

예제 입력 1 
52 9 16
예제 출력 1 
25 45
*/
