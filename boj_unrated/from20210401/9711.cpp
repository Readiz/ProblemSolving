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

ull MOD;

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
    for (int tc = 1; tc <= T; tc++) {
        ull N;
        int dummy;
        scanf("%llu %llu", &N, &MOD);

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

        printf("Case #%d: %llu\n", tc, fibR % MOD);
    }
MAIN_END

/*
피보나치 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	732	220	171	37.916%
문제
피보나치 수열은 아래와 같이 표현된다.

1, 1, 2, 3, 5, 8, 13, 21, 34, ...

각 숫자는 앞의 두 숫자의 합으로 나타내는 것을 알 수 있다.

P와 Q 그리고 n이 주어질 때, P번째 피보나치 숫자를 Q로 나눈 나머지를 구하여라. 

입력
첫 번째 라인에는 정수 T개의 테스트 케이스가 주어진다.

각 테스트 케이스는 정수 P와 Q가 주어진다.

출력
각 테스트 케이스마다 "Case #x: M" 형식으로 출력한다.

x는 테스트 케이스 번호(1부터 시작), M은 P번째 피보나치 숫자를 Q로 나눈 나머지이다.

제한
1 ≤ P ≤ 10,000
1 ≤ Q ≤ 2,000,000,000
*/
