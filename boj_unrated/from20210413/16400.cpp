#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
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
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define MOD 123456789U
typedef unsigned long long ull;

int N;
int numOfPrimes;
int primesMap[40001] = {-1, -1, 0, }; // -1: 소수 아님 / 1: 소수 / 0: 결정안됨
int primes[4204] = {0, };
int dp[40001] = {1, }; // 소수를 N개 썼을 때, 도달하는 합의 경우의 수임

int eratos(int N) {
    int p = 0;
    for (register int i = 2; i <= N; i++) {
        if (primesMap[i] == 0) {
            primesMap[i] = 1; // 처음 도달하면, 소수
            primes[p++] = i;
        }
        // 새로운 소수가 발견될 때마다만 배수들을 채로 쳐낸다.
        if (primesMap[i] != 1) continue;
        for (register int j = i + i; j <= N; j += i) {
            if (primesMap[j] == 0) { // 아직 업뎃 전이면, 업뎃.
                primesMap[j] = -1; // 채에서 쳐내기~
            }
        }
    }
    return p;
}


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d", &N);
    printd("N: %d", N);
    numOfPrimes = eratos(N);
    printd("Num of Primes: %d", numOfPrimes);
    printd("Max Prime: %d", primes[numOfPrimes - 1]);

    for (register int primeIdx = 0; primeIdx < numOfPrimes; primeIdx++) {
        int curPrime = primes[primeIdx];
        printd("Calculating prime: %d...", curPrime);
        for (register int i = 0; i <= N - curPrime; i++) {
            dp[i + curPrime] = (dp[i + curPrime] + dp[i]) % MOD;
        }
    }

    printf("%d\n", dp[N]);

    // Greedy로는 모든 경우 커버 불가능.
    // for (int checkPrimeIdx = numOfPrimes - 1; checkPrimeIdx >= 0; checkPrimeIdx--) {
    //     int targetN = N;
    //     printd("Check: %d", primes[checkPrimeIdx]);
    //     for (int idx = checkPrimeIdx; idx >= 0; idx--) {
    //         if (targetN >= primes[idx]) {
    //             targetN -= primes[idx];
    //             // printd("targetN: %d", targetN);
    //             idx++; // 8 = 2 * 4 같은 경우처럼, 같은 수로 뺄 수도 있으니 빼고나선 같은 소수로 반복
    //             continue;
    //         }
    //     }
    //     if (targetN == 0) count++;
    // }

MAIN_END

// DFS는 시간초과이므로...
// Greedy로 접근. 가장 큰 소수로 빼고, 그 다음 큰 소수로 빼고.. 하다가, 0을 만들 수 있으면 count 추가.

/*
소수 화폐 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	471	219	177	49.859%
문제
소수나라는 특이하게 모든 소수(prime number)를 화폐 단위로 사용한다.

소수나라에 놀러 온 하나는 관광을 하다가 가격이 N인 물건을 발견하고 너무 마음에 들어 999983원을 내고 구매하려고 했다. 하지만 상점 주인이 거스름돈이 없어 정확히 N원을 지불해달라고 하였다.

물건을 구매하려던 하나는 소수나라의 화폐를 이용하여 N원을 정확히 만들 수 있는 방법의 가짓수가 얼마나 되는지 궁금해졌다.

하나를 도와 N원을 지불하기 위한 가짓수가 얼마나 되는지 구해보자.

단, 하나는 소수나라의 모든 화폐가 무한정 있다고 가정한다.

입력
구매하려고하는 물건의 값 N(2 ≤ N ≤ 40,000, N은 정수)이 주어진다.

출력
소수나라의 화폐를 이용하여 지불할 수 있는 방법의 수를 출력한다.

단, 지불할 수 있는 방법의 수가 매우 크기때문에, 123,456,789로 나눈 나머지 값을 출력한다.

예제 입력 1 
8
예제 출력 1 
3
힌트
8원짜리 물건은 아래와 같이 3가지 방법으로 구할 수 있다.

1. 2원 4개

2. 2원 1개, 3원 2개

3. 3원 1개, 5원 1개
*/