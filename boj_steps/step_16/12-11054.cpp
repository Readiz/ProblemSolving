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
    int A[1001] = {0, };
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        printd("A[%d]: %d", i, A[i]);
    }
    int dp[1001][2] = {0, };
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    // dp[i][0]: 위치 i에서의 증가하는 수열의 최대 길이
    // dp[i][1]: 위치 i에서의 감소하는 수열의 최대 길이
    for (int i = 1; i <= n; i++) {
        // 증가하는 부분 체크
        for (int j = i - 1; j > 0; j--) { // 이전 배열을 확인한다..
            if (A[j] < A[i]) { // i 가 j 보다 크다면, 증가하는 수열임
                int newMax = dp[j][0] + 1;
                if (newMax > dp[i][0]) { // 더 큰 증가하는 배열이 있다면..
                    dp[i][0] = newMax;
                    printd("updated dp[%d][0]: %d", i, newMax);
                }
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        // 감소하는 부분 체크
        for (int j = i + 1; j <= n; j++) { // 이후 배열을 확인한다..
            if (A[i] > A[j]) { // i가 j 보다 작다면, 감소하는 수열임
                int newMax = dp[j][1] + 1;
                if (newMax > dp[i][1]) {
                    dp[i][1] = newMax;
                    printd("updated dp[%d][1]: %d", i, newMax);
                }
            }
        }
    }
    
    int longest = -1;
    for (int i = 1; i <= n; i++) {
        int tmp = dp[i][0] + dp[i][1] - 1;
        printd("dp[%d]: %d / %d => longest: %d", i, dp[i][0], dp[i][1], tmp);
        if (longest < tmp) longest = tmp;
    }

    printf("%d\n", longest);

MAIN_END

/*
가장 긴 바이토닉 부분 수열 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	22531	11606	9173	51.656%
문제
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

예제 입력 1 
10
1 5 2 1 4 3 4 5 2 1
예제 출력 1 
7
힌트
예제의 경우 {1 5 2 1 4 3 4 5 2 1}이 가장 긴 바이토닉 부분 수열이다.
*/
