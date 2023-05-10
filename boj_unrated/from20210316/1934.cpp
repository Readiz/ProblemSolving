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
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
MAIN_START
    int T;
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d", &T);
    printd("Input - T: %d", T);
    for (int i = 0; i < T; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printd("a: %d, b: %d", a, b);
        printf("%d\n", lcm(a, b));
    }
    printd("--------------------------");
MAIN_END

/*
최소공배수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	25715	14875	12643	59.733%
문제
두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다. 이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다. 예를 들어, 6과 15의 공배수는 30, 60, 90등이 있으며, 최소 공배수는 30이다.

두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)

출력
첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다.

예제 입력 1 
3
1 45000
6 10
13 17
예제 출력 1 
45000
30
221
*/
