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
#define MOD 10'000

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
    while (true) {
        ull N;
        scanf("%llu", &N);
        printd("N: %llu", N);
        if (N == -1) {
           break;
        }

        Matrix r, fib;
        fib.a = 0; fib.b = fib.c = fib.d = 1;
        while (N) {
            // 홀수일 때만 res 배열에 곱해주고, 짝수일 때는 참고로 삼는 powfib 배열만 계속해서 shift 한다.
            if (N & 1) {
                r = r.mul(fib);
            }
            N >>= 1;
            fib = fib.mul(fib);
        }
        printf("%llu\n", r.b);
    }
MAIN_END

/*
Fibonacci 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	355	226	201	75.000%
문제
In the Fibonacci integer sequence, F0 = 0, F1 = 1, and Fn = Fn−1 + Fn−2 for n ≥ 2. For example, the first ten terms of the Fibonacci sequence are:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, . . .

An alternative formula for the Fibonacci sequence is

  			 

Given an integer n, your goal is to compute the last 4 digits of Fn.

입력
The input test file will contain multiple test cases. Each test case consists of a single line containing n (where 0 ≤ n ≤ 1,000,000,000). The end-of-file is denoted by a single line containing the number -1.

출력
For each test case, print the last four digits of Fn. If the last four digits of Fn are all zeros, print ‘0’; otherwise, omit any leading zeros (i.e., print Fn mod 10000).

예제 입력 1 
0
9
999999999
1000000000
-1
예제 출력 1 
0
34
626
6875
*/
