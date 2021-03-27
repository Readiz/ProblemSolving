#include <stdio.h>

bool isDebug = false;

int N, M;
int brd[101][101];
bool visited[101][101] = {false, };
typedef struct _pt {
    int x;
    int y;
    int count;
} Point;
int queueStart = 0;
int queueEnd = 0;
Point queue[20000];
void enqueue(int x, int y, int count) {
    queue[queueEnd].x = x;
    queue[queueEnd].y = y;
    queue[queueEnd].count = count;
    queueEnd++;
    if (isDebug) printf("[DEBUG] Enqueue: %d, %d\n", x, y);
}
void dequeue(int& x, int& y, int& count) {
    x = queue[queueStart].x;
    y = queue[queueStart].y;
    count = queue[queueStart].count;
    queueStart++;
}
void resetQueue() {
    queueStart = 0;
    queueEnd = 0;
}
int getQueueSize() {
    return queueEnd - queueStart;
}

bool isValidPos(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N && !visited[y][x] && brd[y][x] == 1) return true;
    return false;
}

int BFS() {
    enqueue(0, 0, 1);
    visited[0][0] = true;

    while (getQueueSize() > 0) {
        int x, y, count;
        dequeue(x, y, count);

        if (x == M - 1 && y == N - 1) {
            return count;
        }
        if (isValidPos(x + 1, y)) {
            enqueue(x + 1, y, count + 1);
            brd[y][x + 1] = 1;
            visited[y][x + 1] = true;
        }
        if (isValidPos(x - 1, y)) {
            enqueue(x - 1, y, count + 1);
            brd[y][x - 1] = 1;
            visited[y][x - 1] = true;
        }
        if (isValidPos(x, y + 1)) {
            enqueue(x, y + 1, count + 1);
            brd[y + 1][x] = 1;
            visited[y + 1][x] = true;
        }
        if (isValidPos(x, y - 1)) {
            enqueue(x, y - 1, count + 1);
            brd[y - 1][x] = 1;
            visited[y - 1][x] = true;
        }
    }
    return -1;
}

void printBoard() {
    if (!isDebug) return;
    printf("----------------------------------\n");
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            printf("%d ", brd[y][x]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
}

int main() {
    scanf("%d %d", &N, &M);
    for (int j = 0; j < N; j++) {
        char row[101];
        scanf("%s", row);
        int ptr = 0;
        while (row[ptr] != 0) {
            if (row[ptr] == '0') {
                brd[j][ptr] = 0;
            } else {
                brd[j][ptr] = 1;
            }
            ptr++;
        }
    }
    printBoard();
    printf("%d\n", BFS());
}
/*
문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력 1 
4 6
101111
101010
101011
111011
예제 출력 1 
15
예제 입력 2 
4 6
110110
110110
111111
111101
예제 출력 2 
9
예제 입력 3 
2 25
1011101110111011101110111
1110111011101110111011101
예제 출력 3 
38
예제 입력 4 
7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111
예제 출력 4 
13
*/