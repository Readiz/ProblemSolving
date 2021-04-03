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
#define MOD 1'000'000'007
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
        ull N, M;
        scanf("%llu %llu", &N, &M);
        printd("N: %llu / M: %llu", N, M);
        ull gcdNum = gcd(N, M);
        printd("gcd Result: %llu", gcdNum);

        ull fibR;
        Matrix r, fib;
        r.a = r.d = 1; r.b = r.c = 0;
        fib.a = 0; fib.b = fib.c = fib.d = 1;
        while (gcdNum) {
            // 홀수일 때만 res 배열에 곱해주고, 짝수일 때는 참고로 삼는 powfib 배열만 계속해서 shift 한다.
            if (gcdNum & 1) {
                r = r.mul(fib);
            }
            gcdNum >>= 1;
            fib = fib.mul(fib);
        }
        fibR = r.b;

        printf("%llu\n", fibR % MOD);
    }
MAIN_END

// 피보나치의 다양한 성질중 하나. gcd(Fib(a), Fib(b)) = Fib(gcd(a, b)) 이다.

/*
Fibo 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	63	40	37	63.793%
문제
Fibonacci sequence is a well-known integer sequence that has many beautiful properties. Fibonacci sequence is something looks like this 0, 1, 1, 2, 3, 5, 8, 13, 21, … To make it formal, the mathematical term of Fibonacci sequence is define by recurrence relation.


If you know the technique to solve recurrence relation it will look like

 
 
 

And these are some of its beautiful properties (there are a lot more!)

 

Enough for an introduction, let’s get to the main point. This problem is about finding greatest common divisor (GCD) between Fibonacci numbers. Given two Fibonacci number, your task is to find their GCD! Simple right?

입력
The first line contains a single integer T indicate the number of test cases (1 ≤ T ≤ 1 000)

Each of next T lines contains two integer N, M separated by a space (0 < N, M ≤ 1 000 000 000)

출력
For each test case, print a line contains value of gcd(Fn,Fm) modulo by 1000000 007

예제 입력 1 
2
7 10
6 12
예제 출력 1 
1
8
*/
