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


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N;
    scanf("%d", &N);
    printd("Input - N: %d", N);
    printd("--------------------------");
    if (N) {
        printf("Leading the Way to the Future\n");
    } else {
        printf("YONSEI\n");
    }
    return 0;
MAIN_END


/*
연세대학교 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	4401	3224	2985	74.831%
문제


연세대학교의 영문명은 YONSEI, 슬로건은 Leading the Way to the Future이다.

이를 출력하는 프로그램을 작성해보도록 하자.

입력
첫째 줄에 N이 주어진다. (N = 0 또는 1)

출력
N = 0일 경우: 연세대학교의 영문명을 출력한다.
N = 1일 경우: 연세대학교의 슬로건을 출력한다.
대소문자 구별에 주의하도록 하자.

예제 입력 1 
0
예제 출력 1 
YONSEI
*/
