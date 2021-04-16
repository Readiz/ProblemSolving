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
int D;
int count;
void DFS(int depth, int idx) {
    if (depth == D) {
        if (N == 0) {
            count++;
        }
        return;
    }
    if (N < 0) return; // 더 커지면, 깊이와 상관없이 return..

    for (int i = idx - 1; i >= 0; i--) {
        N -= primes[i];
        DFS(depth + 1, i);
        N += primes[i];
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int T;
    scanf("%d", &T);
    numOfPrimes = eratos(1120);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &N, &D);
        count = 0;
        for (int i = numOfPrimes - 1; i >= 0; i--) {
            N -= primes[i];
            DFS(1, i);
            N += primes[i];
        }
        printf("%d\n", count);
    }
MAIN_END


/*
서로 다른 소수의 합 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	904	485	335	56.876%
문제
양의 정수는 서로 다른 소수의 합으로 나타낼 수 있다. 두 정수 n과 k가 주어졌을 때, n을 서로 다른 k개의 소수의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오. 여기서 덧셈의 순서만 다른 경우(3+5, 5+3)는 모두 1가지로 센다.

예를 들어, n=24, k=3일 때, 2가지로 나타낼 수 있다. {2, 3, 19}, {2, 5, 17} 합이 24가 되는 서로 다른 소수 3개는 이 2가지를 제외하고는 없다. 또, n=24, k=2일 때 답은 {5, 19}, {7, 17}, {11, 13} 3가지이며, n=2, k=1일 때 답은 {2} 1가지이다. n=1, k=1일 경우에는 1은 소수가 아니기 때문에 답은 0이다. 마지막으로 서로 다른 2개 소수의 합이 4가 되는 경우도 없기 때문에, n=4, k=2도 답이 0이다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각각의 테스트 케이스는 한 줄에 n과 k가 공백으로 구분되어 있다. (n ≤ 1120, k ≤ 14)

출력
각 테스트 케이스에 해당하는 경우의 수를 한 줄에 하나씩 출력한다. 정답은 항상 231보다 작다.

예제 입력 1 
12
24 3
24 2
2 1
1 1
4 2
18 3
17 1
17 3
17 4
100 5
1000 10
1120 14
예제 출력 1 
2
3
1
0
0
2
1
0
1
55
200102899
2079324314
*/