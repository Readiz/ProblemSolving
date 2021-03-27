#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int getLoopTotal(int loopIdx) {
    return 4 + (loopIdx + 1) * 2;
}

int N, T;
int Tx, Ty;
int A[1000][1000] = {0, };
void fill(int s, int n, int x, int y, int dx, int dy, bool toggle) {
    for (int i = 0; i < n; i++) {
        if (s == T) {
            Tx = x; Ty = y;
        }
        A[y][x] = s;
        // printd("Current Val: %d", s);
        if (i == n - 1) break;
        s--; x += dx; y += dy;
    }
    if (s == 1) return;
    if (dx == 0 && dy == 1) { // 아래 진행
        dx = 1; dy = 0; // 우측 진행
    } else if (dx == 1 && dy == 0) {
        dx = 0; dy = -1; // 위쪽 진행
    } else if (dx == 0 && dy == -1) {
        dx = -1; dy = 0; // 왼쪽 진행
    } else {
        dx = 0; dy = 1; // 아래 진행
    }
    s--; x += dx; y += dy; // 다음 시작점 잡아준다.
    // printd("Next Start: %d, %d", x, y);
    fill(s, toggle ? (n - 1) : n, x, y, dx, dy, !toggle);
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d %d", &N, &T);
    printd("Input - N: %d, T: %d", N, T);
    printd("--------------------------");

    fill(N * N, N, 0, 0, 0, 1, true);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("%d %d\n", Ty + 1, Tx + 1);
MAIN_END


/*
달팽이 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	5740	3128	2470	55.971%
문제
홀수인 자연수 N(3≤N≤999)이 주어지면, 다음과 같이 1부터 N2까지의 자연수를 달팽이 모양으로 N*N의 표에 늘어놓을 수 있다.

9	2	3
8	1	4
7	6	5
25	10	11	12	13
24	9	2	3	14
23	8	1	4	15
22	7	6	5	16
21	20	19	18	17
N이 주어졌을 때, 이러한 표를 출력하는 프로그램을 작성하시오. 또한 N2 이하의 자연수가 하나 주어졌을 때, 그 좌표도 함께 출력하시오. 예를 들어 N=5인 경우 6의 좌표는 (4,3)이다.

입력
첫째 줄에 홀수인 자연수 N이 주어진다. 둘째 줄에는 위치를 찾고자 하는 N2 이하의 자연수가 하나 주어진다.

출력
N개의 줄에 걸쳐 표를 출력한다. 각 줄에 N개의 자연수를 한 칸씩 띄어서 출력하면 되며, 자릿수를 맞출 필요가 없다. N+1번째 줄에는 입력받은 자연수의 좌표를 나타내는 두 정수를 한 칸 띄어서 출력한다.

예제 입력 1 
7
35
예제 출력 1 
49 26 27 28 29 30 31
48 25 10 11 12 13 32
47 24 9 2 3 14 33
46 23 8 1 4 15 34
45 22 7 6 5 16 35
44 21 20 19 18 17 36
43 42 41 40 39 38 37
5 7
*/

