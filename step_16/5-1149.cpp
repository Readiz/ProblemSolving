#include <stdio.h>
#define Color int
#define undefined 0
#define R 1
#define G 2
#define B 3
static int N;
static int cost[4][1001] = {{0, }, };
static Color house[1001] = {undefined, };
static int min = 2000000000;

static void paint(int pos, int curSum) {
    if (pos == N) {
        if (curSum < min) min = curSum;
        return;
    }

    for (int color = R; color <= B; color++) {
        if (pos == 0 || house[pos - 1] != color) { // 마주보는 집끼리 다른 색상을 하도록 함
            house[pos] = color;
            int newSum = curSum + cost[color][pos];
            paint(pos + 1, newSum);
        }
    }
    return;
}

int main() {
    int i = 0;
    for (scanf("%d", &N); i < N; i++) {
        // 비용 등록
        scanf("%d %d %d", &cost[R][i], &cost[G][i], &cost[B][i]);
    }
    paint(0, 0);
    printf("%d\n", min);

    return 0;
}


/*
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
