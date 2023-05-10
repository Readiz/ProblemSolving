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
typedef unsigned long long ull;

// 0: undefined, 1: prime, -1: not prime
int primes[4'000'001] = {-1, -1, 1, 1, -1, 1, 0, };
int primeNumbers[2'000'000] = {0, }; // 2의 배수는 기본적으로 제외되니까 적어도 소수 수는 절반보다는 적음..
ull primeSums[2'000'000] = {0, }; // 쉽게 overflow 난다.. (너무 큰 소수들 들어옴..)
int numberOfPrimes;

void getPrimes(int MAX) {
    // 에라토스의 채
    for (int i = 2; i <= MAX; i++) {
        if (primes[i] == 0) primes[i] = 1; // 최초로 도달했다는 것은 prime이라는 뜻
        for (int j = i + i; j <= MAX; j += i) {
            primes[j] = -1; // 배수로 도달했다는 것은 prime아 아니라는 뜻
        }
    }
    // 소수만 깔끔히.. 배열안에 정렬.
    int p = 0;
    ull sum = 0ULL;
    for (int i = 2; i <= MAX; i++) {
        if (primes[i] == 1) {
            sum += i;
            primeSums[p] = sum;
            primeNumbers[p++] = i;
        }
    }
    numberOfPrimes = p;
}


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int N;
    scanf("%d", &N);
    printd("N: %d", N);
    getPrimes(N);
    printd("NumberOfPrimes: %d", numberOfPrimes);

    if (N < 100) {
        for (int i = 0; i < numberOfPrimes; i++) {
            if (isDebug) {
                printf("%d ", primeNumbers[i]);
            }
        }
        if (isDebug) printf("\n");
        for (int i = 0; i < numberOfPrimes; i++) {
            if (isDebug) {
                printf("%llu ", primeSums[i]);
            }
        }
        if (isDebug) printf("\n");
    }

    int count = 0;
    // i, j 영역 설정하여, 부분합 실행하여, target Sum(N) 비교
    for (int i = -1; i < numberOfPrimes; i++) { // 빼지 않는 경우도 비교해야함. 해당 값이 -1..
        for (int j = i + 1; j < numberOfPrimes; j++) {
            ull curAccSum = (i == -1) ? primeSums[j] : (primeSums[j] - primeSums[i]);
            if (curAccSum == N) {
                printd("Check S[%d] - S[%d], is sum: %d", j, i, N);
                count++;
            } else if (curAccSum > N) { // 탈출조건.. 이 조건에서는 더이상 계산할 필요가 없음. (j 증가시 수는 점점 증가)
                break;
            }
        }
    }

    // 아래 방법은 너무 느림. O(4'000'000 * 4'000'000) ...
    // for (int i = 0; i < numberOfPrimes; i++) { // 시작포인터: i, 끝 포인터: j..
    //     for (int j = i + 1; j <= numberOfPrimes; j++) {
    //         int curAccSum = 0;
    //         for (int k = i; k < j; k++) {
    //             curAccSum += primeNumbers[k];
    //             if (curAccSum > N) break; // 더하다가 더이상 진행 필요없으면 break
    //         }
    //         if (curAccSum == N) {
    //             printd("Check S[%d] ~ S[%d], is sum: %d", j, i, N);
    //             count++;
    //         }
    //     }
    // }

    printf("%d\n", count);
MAIN_END

/*
소수의 연속합 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	14770	6350	4491	42.492%
문제
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.

3 : 3 (한 가지)
41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
53 : 5+7+11+13+17 = 53 (두 가지)
하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.

자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

출력
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.
*/
