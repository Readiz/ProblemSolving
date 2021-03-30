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
        printf("[DEBUG] No Online Judge detected!\n", fname);
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int getZeroCount(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        if (n % 10 == 0) {
            count++;
        }
        n /= 10;
    }
    return count;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int T;
    scanf("%d", &T);
    printd("--------------------------");
    for (int tc = 0; tc < T; tc++) {
        int N, M;
        scanf("%d %d", &N, &M);
        int count = 0;
        for (int i = N; i <=M; i++) {
            count += getZeroCount(i);
        }
        printf("%d\n", count);
    }
MAIN_END


/*
0의 개수 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
3 초	256 MB	1319	1018	890	79.181%
문제
N부터 M까지의 수들을 종이에 적었을 때 종이에 적힌 0들을 세는 프로그램을 작성하라.

예를 들어, N, M이 각각 0, 10일 때 0을 세면 0에 하나, 10에 하나가 있으므로 답은 2이다.

입력
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 줄에는 N과 M이 주어진다.

1 ≤ T ≤ 20
0 ≤ N ≤ M ≤ 1,000,000
출력
각각의 테스트 케이스마다 N부터 M까지의 0의 개수를 출력한다.

예제 입력 1 
3
0 10
33 1005
1 4
예제 출력 1 
2
199
0
*/
