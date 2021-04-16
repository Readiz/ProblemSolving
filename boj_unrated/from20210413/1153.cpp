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

int primesMap[1'000'001] = {-1, -1, 1, 1, -1, 1, 0, 0, }; // -1: 소수 아님 / 1: 소수 / 0: 결정안됨
int primes[500'000] = {0, };
int numOfPrimes;

int eratos(int N) {
    for (int i = 2; i <= N; i++) {
        if (primesMap[i] == 0) primesMap[i] = 1; // 처음 도달하면, 소수
        if (primesMap[i] != 1) continue;
        for (int j = i + i; j <= N; j += i) {
            if (primesMap[j] == 0) { // 아직 업뎃 전이면, 업뎃.
                primesMap[j] = -1; // 채에서 쳐내기~
            }
        }
    }
    int p = 0;
    for (int i = 2; i <= N; i++) {
        if (primesMap[i] == 1) {
            primes[p++] = i;
        }
    }
    return p;
}
int N;
bool DFS(int depth, int idx) {
    if (depth == 4) {
        if (N == 0) {
            printd("Found!");
            return true;
        } else {
            return false;
        }
    }
    if (N < 0) return false; // 깊이와 상관없이 return..

    for (int i = idx; i >= 0; i--) {
        N -= primes[i];
        bool r = DFS(depth + 1, i);
        if (r) {
            printf("%d ", primes[i]);
            return true;
        }
        N += primes[i];
    }
    return false;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d", &N);
    bool isFound = false;
    numOfPrimes = eratos(N);
    for (int i = numOfPrimes - 1; i >= 0; i--) {
        N -= primes[i];
        bool r = DFS(1, i);
        if (r) {
            isFound = true;
            printf("%d ", primes[i]); // 이 순서로 출력하면 작은 것 먼저 return 되면서 출력하므로 크기순으로 출력하게 됨 (자연스럽다~)
            break;
        }
        N += primes[i];
    }
    if (!isFound) {
        printf("-1\n");
    } else {
        printf("\n");
    }
    
MAIN_END


/*
네 개의 소수 스페셜 저지분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	1643	601	449	39.699%
문제
임의의 자연수가 주어지면, 이를 네 개의 소수의 합으로 분해하는 프로그램을 작성하시오. 예를 들어 38 = 5 + 7 + 13 + 13이 된다.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

출력
첫째 줄에 네 개의 소수를 빈 칸을 사이에 두고 순서대로 출력한다. 불가능한 경우는 -1을 출력한다.

예제 입력 1 
38
예제 출력 1 
5 7 13 13
*/