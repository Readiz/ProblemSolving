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
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    ull N;
    scanf("%llu", &N);
    printd("N: %llu", N);

    ull a = 1, b = 1, c = 1, d = 0; // 행렬에 대응되는 수들
    ull newA, newB, newC, newD;
    ull curN = 1;

    // 2^N 번째의 fib 숫자는 행렬을 이용하면 매우 빠르게 접근하여 구할 수 있다.
    ull fib2[100000][4] = {{1, 1, 1, 0}, }; // 2^N 꼴의 fib 수의 캐싱
    int i = 0;
    while (curN * 2 <= N) {
        newA = ((a * a) % MOD + (b * c) % MOD) % MOD;
        newB = ((a * b) % MOD + (b * d) % MOD) % MOD;
        newC = ((c * a) % MOD + (d * c) % MOD) % MOD;
        newD = ((c * b) % MOD + (d * d) % MOD) % MOD;
        a = newA; b = newB; c = newC; d = newD;
        curN *= 2;
        i++;
        // 2^n 캐싱
        fib2[i][0] = a;
        fib2[i][1] = b;
        fib2[i][2] = c;
        fib2[i][3] = d;
    }
    printd("[FIRST] curN: %llu, fib: %llu", curN, b);
    // 2^N + 2^N 꼴의 fib 숫자도 행렬을 이용해서 빠르게 구할 수 있다.
    // 2^i 에 fib2[i] 행렬로 숫자가 저장되어 있음. 최초 i는 curN..
    ull posN = curN;
    while (i >= 1) {
        if (posN + (curN / 2) <= N) {
            printd("posN = %llu  |  posN + (curN / 2) = %llu", posN, posN + (curN / 2));
            curN /= 2; posN += curN; i--;
            newA = ((a * fib2[i][0]) % MOD + (b * fib2[i][2]) % MOD) % MOD;
            newB = ((a * fib2[i][1]) % MOD + (b * fib2[i][3]) % MOD) % MOD;
            newC = ((c * fib2[i][0]) % MOD + (d * fib2[i][2]) % MOD) % MOD;
            newD = ((c * fib2[i][1]) % MOD + (d * fib2[i][3]) % MOD) % MOD;
            a = newA; b = newB; c = newC; d = newD;
        } else {
            curN /= 2; i--;
        }
    }
    curN = posN;
    printd("[SECOND] curN: %llu, fib: %llu", curN, b);

    if (N == 0) printf("0\n");
    else if (N == 1) printf("1\n");
    else if (curN == N) printf("%llu\n", b);
    else if (curN + 1 == N) printf("%llu\n", a);
    else {
        // 사실 아래 로직은 필요 없다.. (2진법으로 모든 수 구할 수 있으니까..)
        // 여기부턴 정석대로 구한다.
        ull pprev = b, prev = a, cur = (a + b) % MOD;
        ull curIdx = curN + 2;
        while (curIdx < N) {
            curIdx++;
            pprev = prev;
            prev = cur;
            cur = (pprev + prev) % MOD;
        }
        printd("[THIRD] curN: %llu, fib: %llu", curIdx, cur);
        printf("%llu\n", cur);
    }

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