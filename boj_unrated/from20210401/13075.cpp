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
typedef unsigned long long ull;
#define MOD 1'000'000'000
template<class T>
T gcd(T a, T b) {
    while (b != 0) {
        T r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class Matrix {
public:
    ull a, b, c, d;
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
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        ull N;
        scanf("%llu", &N);

        ull fibR;
        Matrix r, fib;
        r.a = r.d = 1; r.b = r.c = 0;
        fib.a = 0; fib.b = fib.c = fib.d = 1;
        while (N) {
            // 홀수일 때만 res 배열에 곱해주고, 짝수일 때는 참고로 삼는 powfib 배열만 계속해서 shift 한다.
            if (N & 1) {
                r = r.mul(fib);
            }
            N >>= 1;
            fib = fib.mul(fib);
        }
        fibR = r.b;

        printf("%llu\n", fibR % MOD);
    }
MAIN_END

/*
Fibonacci Sequence 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	73	56	54	79.412%
문제
Your job is to take an integer x as the input and compute f(x) mod 109, where f(x) is the x-th value in the well-known Fibonacci sequence. 

Note that Fibonacci sequence is defined as follows:

f(1) = f(2) = 1
f(k) = f(k-1) + f(k-2) for any k > 2

입력
The first line of the input includes the number of test cases, 1 ≤ t ≤ 1000. Each test case is a line containing an integer 1 ≤ x ≤ 248.

출력
For each test case, print one line containing f(x) mod 109
*/
