#include <stdio.h>
#ifndef BOJ
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
    int A, B;
    scanf("%d %d", &A, &B);
    printd("Input - A: %d, B: %d", A, B);
    printd("--------------------------");
    printf("%lld\n", (long long) (A + B) * (A - B));
MAIN_END

/*
이상한 기호 서브태스크출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	5412	2722	2576	56.591%
문제
부산일과학고등학교의 효진이는 수학의 귀재이다. 어떤 문제라도 보면 1분 내에 풀어버린다는 학교의 전설이 내려올 정도였는데, 이런 킹ㅡ갓 효진에게도 고민이 생겼다. 대부분의 문제에서 반복되는 연산이 있었기 때문이다! 이 연산은 너무 길어서 종이에 풀던 효진이는 너무 고통스러워서, 자신이 새로 연산자를 만들기로 했다.

연산자의 기호는 ＠으로, A＠B = (A+B)×(A-B)으로 정의내리기로 했다.

하지만, 효진이는 막상 큰 숫자가 들어오자 계산하기 너무 귀찮아졌다.

효진이를 도와 정수 A, B가 주어지면 A＠B를 계산하는 프로그램을 만들어주자!

입력
첫째 줄에 A, B가 주어진다. (1 ≤ A, B ≤ 100,000)

출력
 첫째 줄에 A＠B의 결과를 출력한다.

서브태스크 1 (30점)
A, B ≤ 1,000
서브태스크 2 (70점)
문제에서 주어진 제약 조건 외 제한 없음

예제 입력 1 
4 3
예제 출력 1 
7
예제 입력 2 
3 4
예제 출력 2 
-7
*/
