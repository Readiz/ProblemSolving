#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("9-10844_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
int N;
int curLength;
ull count;
void DFS(int from) {
    if (curLength == N) {
        count++;
        return;
    }
    if (from >= 1) {
        curLength++;
        DFS(from - 1);
        curLength--;
    }
    if (from <= 8) {
        curLength++;
        DFS(from + 1);
        curLength--;
    }
}
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    scanf("%d", &N);
    printd("N: %d", N);
    printd("--------------------------");
    // DFS 풀이 법은 아래.. 이 방법은 N = 30 부터 대략 안된다고 보면 됨.
    // count = 0;
    // for (int i = 1; i <= 9; i++) {
    //     curLength = 1;
    //     DFS(i);
    // }
    // count = 9;
    ull DP[101][10] = {0, };
    // 초기화
    for (int i = 1; i <= 9; i++) DP[1][i] = 1;

    // DP 계산 시작
    for (int i = 2; i <= N; i++) {
        DP[i][0] = DP[i - 1][1];
        DP[i][1] = DP[i - 1][0] + DP[i - 1][2];
        DP[i][2] = DP[i - 1][1] + DP[i - 1][3];
        DP[i][3] = DP[i - 1][2] + DP[i - 1][4];
        DP[i][4] = DP[i - 1][3] + DP[i - 1][5];
        DP[i][5] = DP[i - 1][4] + DP[i - 1][6];
        DP[i][6] = DP[i - 1][5] + DP[i - 1][7];
        DP[i][7] = DP[i - 1][6] + DP[i - 1][8];
        DP[i][8] = DP[i - 1][7] + DP[i - 1][9];
        DP[i][9] = DP[i - 1][8];
        for (int j = 0; j < 10; j++) {
            DP[i][j] %= 1'000'000'000;
        }
    }
    ull sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += DP[N][i];
        sum %= 1'000'000'000;
    }
    printf("%llu\n", sum);
MAIN_END

/*
쉬운 계단 수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	76038	23160	16629	28.513%
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

예제 입력 1 
1
예제 출력 1 
9
예제 입력 2 
2
예제 출력 2 
17
*/
