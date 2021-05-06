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
#define R register
typedef unsigned long long ull;

// Refer to https://casterian.net/archives/396
ull checker[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
ull N;

ull addmod(ull x, ull y, ull m) {
    if (x >= m - y) {
        return x - (m - y);
    } else {
        return x + y;
    }
}
ull mulmod(ull x, ull y, ull m) {
    ull r = 0ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = addmod(r, x, m);
        x = addmod(x, x, m);
        y /= 2;
    }
    return r;
}

// 빠른 거듭제곱.. (2^N) 을 반복해서 곱하는 방식.
ull powmod(ull x, ull y, ull m) {
    ull r = 1ULL;
    // 이진수 연산한다고 생각.. 2^n 꼴은 자리수 올리고.. 아닌 경우 더하고..
    while (y > 0) {
        if (y % 2 == 1) {
            r = mulmod(r, x, m);
        }
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}

// Miller-Rabin checker
// true를 리턴한다고 해서 무조건 소수인 것은 아님. (확률적 소수)
// 그러나 특정 수들에 대해 (checker 배열) 모두 검사한다면, 확정적으로 소수임을 판별가능.
// (log n)^3 알고리즘
bool MR(ull N, ull A) {
    ull d = N - 1;
    while (d % 2 == 0) {
        if (powmod(A, d, N) == N - 1) {
            return true;
        }
        d /= 2;
    }

    ull tmp = powmod(A, d, N);
    if (tmp == N - 1 || tmp == 1) { // a^(d*2^r) mod n = -1 판정 하는 부분임
        return true;
    } else {
        return false;
    }
}

bool isPrime(ull N) {
    if (N <= 1) {
        return false;
    } else if (N == 2) {
        return true;
    } else if (N <= 10000000000ULL) { // 기존 방법이 빠른 구간 + 밀러라빈 checker 수보다 작은 구간
        for (ull i = 3ULL; i * i <= N; i += 2) { // 홀수만 검사한다.
            if (N % i == 0ULL) return false; // 나누어 떨어지면, 소수
        }
        return true;
    } else {
        for (int i = 0; i < 7; i++) { // 7: checker size
            ull A = checker[i];
            if (MR(N, A) == false) {
                return false;
            }
        }
        return true;
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int T;
    scanf("%d", &T);
    for (R int tc = 0; tc < T; tc++) {
        ull A, B;
        scanf("%llu %llu", &A, &B);
        printd("A: %llu / B: %llu", A, B);
        ull S = A + B;
        if (S & 1ULL == 1) { // 홀수
            if (isPrime(S - 2ULL)) {
                printf("YES\n"); // 3 + 4 = 7 = 2 + 5 인 것이 예시.. 홀수 소수 분해시 한 수는 2가 될 수밖에..
            } else {
                printf("NO\n");
            }
        } else {
            if (S == 2ULL) printf("NO\n");
            else printf("YES\n"); // 골드바흐 추측. 모든 짝수는 두 소수의 합으로 나타낼 수 있음
        }
    }
MAIN_END


/*
환상의 짝꿍 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	2297	424	283	16.540%
문제
환상의 나라 디디랜드에서는 인연의 증표로 끈을 하나씩 가지고 있다. 그들은 지극히 평범한 방법으로 이 끈을 이용하여 어떤 두 사람이 환상의 짝꿍인지 판단하는데, 두 사람의 끈을 서로 이어붙이고 그 끈을 다시 길이가 소수인 끈 두개로 정확히 나눌 수 있다면 두 사람은 환상의 짝꿍이라고 한다. 하지만 그들은 길이가 소수인 두개의 끈으로 나눌 수 있는지 판단하는 것이 어려워서 대부분 서로가 인연임을 모르고 그냥 지나간다고 한다. 애석하게도...

그런 그들을 위해서 어떤 두 사람이 환상의 짝꿍인지 판단하는 프로그램을 작성하라.

편의상 두 사람의 끈을 이어붙일 때와 나눌 때 손실되는 끈의 길이는 0이라고 가정한다.

입력
첫째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 500)가 주어진다.

둘째 줄부터 T개 줄에 두 사람이 가지고 있는 끈의 길이를 나타내는 정수 A, B가 공백으로 구분되어 주어진다. (1 ≤ A, B ≤ 2 × 1012)

출력
각 테스트 케이스마다 한 줄씩 두 사람의 끈을 이어붙이고 그 끈을 다시 길이가 소수인 두개의 끈으로 정확히 나눌 수 있다면 YES, 불가능하면 NO를 출력하라.

예제 입력 1 
2
3 4
3 5
예제 출력 1 
YES
YES
*/
