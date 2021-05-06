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

int MAX(int a, int b) {
    if (a > b) return a;
    return b;
}
int MAX(int a, int b, int c) {
    return MAX(MAX(a, b), c);
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int n;
    scanf("%d", &n);
    int cost[10001] = {0, };
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    int dp[10001] = {0, };
    // [유의사항] 첫번째, 두번째를 선택하면 세번째를 선택 못함..
    // DP의 핵심: 각 배열 간의 관계를 파악하는 것!
    
    // DP[i][1]: i 지점의 잔에서의 최대값 (유의: i 번째 잔을 마시지 않을 수도 있음)
    dp[1] = cost[1];
    dp[2] = cost[1] + cost[2];
    dp[3] = MAX(cost[2] + cost[3], cost[1] + cost[3], dp[2]);
    dp[4] = MAX(dp[2] + cost[4], dp[1] + cost[3] + cost[4], dp[3]);
    for (int i = 5; i <= n; i++) {
        // 1. i 번째 잔을 마실 경우의 최대값은 관계식으로 표현 가능.
        //    1 - 1. 세 번째 전의 잔을 마시고, 이전 잔을 마시고, 현재 잔을 마시는 경우
        //    1 - 2. 두 번째 전의 잔을 마시고, 현재 잔을 마시는 경우 (세 잔 연속으로 마시는 것 방지)
        //    1 - 3. 현재 잔을 마시지 않는 경우 (그 이전 값과 동일)
        dp[i] = MAX(dp[i - 3] + cost[i- 1] + cost[i], dp[i - 2] + cost[i], dp[i - 1]);
        printd("dp[%d]: %d", i, dp[i]);
    }
    printf("%d\n", dp[n]);
MAIN_END


/*
포도주 시식 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	71404	25328	18083	33.648%
문제
효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.

포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 

예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.

입력
첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 음이 아닌 정수이다.

출력
첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.

예제 입력 1 
6
6
10
13
9
8
1
예제 출력 1 
33
*/
