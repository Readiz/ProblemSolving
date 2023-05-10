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
#define MOD 1'000'000'007ULL
typedef unsigned long long ull;


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    ull N, R;
    scanf("%llu %llu", &N, &R);
    ull r = 1ULL;
    ull P = 1ULL;
    if (N - R < R) R = N - R;
    while (P <= R) {
        r *= N;
        r %= MOD;
        r /= P;
        r %= MOD;
        printd("P: %llu => %llu", P, r);
        P++;
        N--;
    }
    printf("%llu\n", r);

MAIN_END


/*
조합 (Combination) 서브태스크출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초 (추가 시간 없음)	256 MB	771	287	225	55.419%
문제
준하는 기초통계학 수업에서 너비가 a, 높이가 ​​​​​b인 격자판의 좌하단 점으로부터 우상단 점까지 최단경로로 가는 방법의 수를 구하라는 과제를 받았어. 

알고 있겠지만 정답은   	 이야. 보기만 해도 벌써 조합을 계산할 생각에 신이 나지? 사실 조합을 구하는 문제도 코딩으로 해결할 수 있대. 코딩으로 과제를 해결해주자!

입력
첫 줄에 N과 R이 주어진다. (0 ≤ R ≤ N ≤ 1,000,000)

출력
 의 값을 1,000,000,007로 나눈 나머지를 출력하자! (단, 1,000,000,007은 소수이다)

서브태스크 1 (10점)
N ≤ 10
서브태스크 2 (30점)
N ≤ 30
서브태스크 3 (50점)
N ≤ 1,000
서브태스크 4 (10점)
추가 제한 없음
예제 입력 1 
4 2
예제 출력 1 
6
예제 입력 2 
30 15
예제 출력 2 
155117520
*/
