#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("1789_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;

// 바빌로니아법
template<class T>
T sqrt(T input) {
    T x = 1; // 임의의 수를 지정해도 하나로 수렴하는 수열임
    for (int i = 0; i < 30; i++)
        x = (x + (input / x)) / 2;
    return x;
}

MAIN_START
    // printd("TEST: %d", sqrt(81));
    // printd("TEST: %d", sqrt(80));
    // printd("TEST: %d", sqrt(82));
    printd("--------------------------");
    printd("TEST START!!!");
    ull S, N;
    scanf("%llu", &S);
    printd("--------------------------");
    N = sqrt(S * 2);
    while (N * N + N > S * 2) {
        N--;
    }
    printf("%llu\n", N);
MAIN_END

/*
n(n+1)/2<=S 인 최대 N을 찾는다.

수들의 합 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	13329	5489	4620	42.885%
문제
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?

입력
첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.

출력
첫째 줄에 자연수 N의 최댓값을 출력한다.

예제 입력 1 
200
예제 출력 1 
19
*/