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
        printf("[DEBUG] No Online Judge detected!\n");
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef long long ll;
#define MOD 1'000'000'000

class Matrix {
public:
    ll a, b, c, d;
    Matrix() {
        a = d = 1;
        b = c = 0;
    }
    Matrix mul(Matrix x) {
        Matrix r;
        r.a = (this->a * x.a + this->b * x.c) % MOD;
        r.b = (this->a * x.b + this->b * x.d) % MOD;
        r.c = (this->c * x.a + this->d * x.c) % MOD;
        r.d = (this->c * x.b + this->d * x.d) % MOD;
        return r;
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    ll a, b;
    scanf("%llu %llu", &a, &b);
    printd("a: %llu / b: %llu", a, b);

    a += 1; b += 2; // 합은 두개항 뒤의 값에서 1을 뺀 것임, 단 a의 경우 앞에 값을 포함시켜야 하니 1만 더한다.

    Matrix sumA, sumB, fib;
    fib.a = 0; fib.b = fib.c = fib.d = 1;
    while (a) {
        // 홀수일 때만 res 배열에 곱해주고, 짝수일 때는 참고로 삼는 powfib 배열만 계속해서 shift 한다.
        if (a & 1) {
            sumA = sumA.mul(fib);
        }
        a >>= 1;
        fib = fib.mul(fib);
    }
    a = sumA.b - 1;

    fib.a = 0; fib.b = fib.c = fib.d = 1;
    while (b) {
        // 홀수일 때만 res 배열에 곱해주고, 짝수일 때는 참고로 삼는 powfib 배열만 계속해서 shift 한다.
        if (b & 1) {
            sumB = sumB.mul(fib);
        }
        b >>= 1;
        fib = fib.mul(fib);
    }
    b = sumB.b - 1;
    if (b > a) {
        printf("%lld\n", b - a);
    } else {
        printf("%lld\n", b - a + MOD);
    }
MAIN_END
/*
피보나치 수의 합 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	1775	489	392	33.080%
문제
제 1항과 제 2항을 1이라 하고, 제 3항부터는 앞의 두 항의 합을 취하는 수열을 피보나치(fibonacci) 수열이라고 한다. 예를 들어 제 3항은 2이며, 제 4항은 3이다.

피보나치 수열의 a번째 항부터 b번째 항까지의 합을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으므로 마지막 아홉 자리만을 구하도록 한다. 즉 1,000,000,000으로 나눈 나머지를 구하면 된다.

입력
첫째 줄에 a와 b(1≤a≤b≤9,000,000,000,000,000,000)이 주어진다.

출력
첫째 줄에 구한 합을 출력한다.

예제 입력 1 
4 10
예제 출력 1 
139
*/