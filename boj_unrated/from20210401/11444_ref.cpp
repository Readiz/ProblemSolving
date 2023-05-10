#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit(char fbasename[]) {
        freopen("11444_input.txt", "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
#define MOD 1'000'000'007

class Matrix22 {
public:
    ull a, b, c, d;
    Matrix22() {
        a = d = 1;
        b = c = 0;
    }
    Matrix22 multiply(Matrix22 x) {
        Matrix22 res;
        res.a = (this->a * x.a + this->b * x.c) % MOD;
        res.b = (this->a * x.b + this->b * x.d) % MOD;
        res.c = (this->c * x.a + this->d * x.c) % MOD;
        res.d = (this->c * x.b + this->d * x.d) % MOD;
        return res;
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    ull N;
    scanf("%llu", &N);
    printd("N: %llu", N);

    Matrix22 res, powfib;
    powfib.a = 0;
    powfib.b = powfib.c = powfib.d = 1;
    while (N) {
        // 결국 하는 일은 내 풀이랑 똑같은데, 행렬 두개를 사용해서 멋지게 풀었음.
        // 행렬도 class로 나타내면 쉬운 녀석임.. (동일 로직 반복했네..)
        // 홀수일 때만 res 배열에 곱해주고, 짝수일 때는 참고로 삼는 powfib 배열만 계속해서 shift 한다.
        if (N & 1) {
            res = res.multiply(powfib);
        }
        N >>= 1;
        powfib = powfib.multiply(powfib);
    }
    printf("%llu\n", res.b);

MAIN_END

/*
피보나치 수 6 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	3304	1739	1418	57.432%
문제
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다.

예제 입력 1 
1000
예제 출력 1 
517691607
*/