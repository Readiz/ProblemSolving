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
    ull N;
    scanf("%llu", &N);
    printd("N: %llu", N);

    N++;

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

    printf("%llu\n", (r.a * r.b) % MOD);
MAIN_END

// 피보나치의 다양한 성질중 하나. ∑Fn^2 = Fn*Fn+1 을 이용


/*
피보나치 수의 제곱의 합 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	478	259	240	67.416%
문제
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, 0번째 피보나치 수의 제곱부터 n번째 피보나치 수의 제곱을 합한 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 0번째 피보나치 수의 제곱부터 n번째 피보나치 수의 제곱의 합을 1,000,000,007으로 나눈 나머지를 출력한다.

예제 입력 1 
10
예제 출력 1 
4895
*/
