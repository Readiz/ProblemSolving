#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("1149_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

void SWAP(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
int MIN(int a, int b, int c) {
    if (a > b) SWAP(a, b);
    if (b > c) SWAP(b, c);
    if (a > b) SWAP(a, b);
    return a;
}
int MIN(int a, int b) {
    if (a > b) return b;
    return a;
}

int cost[1000][3] = {0, };
int DP[1000][3] = {0, };
int N;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    scanf("%d", &N);
    printd("N: %d", N);
    printd("--------------------------");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    DP[0][0] = cost[0][0]; DP[0][1] = cost[0][1]; DP[0][2] = cost[0][2];
    for (int i = 1; i < N; i++) {
        // 때로는 함수를 타면서 모든 경우를 구하는 것보다 경우에 대해 공간을 확장시켜서, 반복해나가는게 좋을 때도 있다.
        // 한정된 색을 칠하는 경우가 가장 대표적인 DP 문제라고 할 것.
        // DP: 어떤 공간을 선언하고, 초기값을 설정한 뒤, 공간간의 관계로 점점 값을 채워나가는 법.

        // i 번쨰 집을 color: 0 으로 칠했을 때의 값 - 그 이전의 값이 최소로 되는 것과 더한다.
        DP[i][0] = MIN(DP[i - 1][1], DP[i - 1][2]) + cost[i][0];
        // i 번쨰 집을 color: 1 으로 칠했을 때의 값
        DP[i][1] = MIN(DP[i - 1][0], DP[i - 1][2]) + cost[i][1];
        // i 번쨰 집을 color: 2 으로 칠했을 때의 값
        DP[i][2] = MIN(DP[i - 1][0], DP[i - 1][1]) + cost[i][2];
    }
    printf("%d\n", MIN(DP[N - 1][0], DP[N - 1][1], DP[N - 1][2]));
MAIN_END


/*
RGB거리 실패분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.5 초 (추가 시간 없음)	128 MB	56962	27280	20392	48.068%
문제
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
*/
