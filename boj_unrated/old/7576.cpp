#include <stdio.h>

bool isDebug = false;
int M, N;
int board[1001][1001];
bool visited[1001][1001] = {false, };

typedef struct _pt {
    int x;
    int y;
} Point;
int queueStart = 0;
int queueEnd = 0;
Point queue[1000001];
int queueNextStart = 0;
int queueNextEnd = 0;
Point queueNext[1000001];

void enqueue(int x, int y) {
    queue[queueEnd].x = x;
    queue[queueEnd].y = y;
    queueEnd++;
}
void dequeue(int& x, int& y) {
    x = queue[queueStart].x;
    y = queue[queueStart].y;
    queueStart++;
}
void resetQueue() {
    queueStart = 0;
    queueEnd = 0;
}
int getQueueSize() {
    return queueEnd - queueStart;
}
void enqueueNext(int x, int y) {
    queueNext[queueNextEnd].x = x;
    queueNext[queueNextEnd].y = y;
    queueNextEnd++;
}
void dequeueNext(int& x, int& y) {
    x = queueNext[queueNextStart].x;
    y = queueNext[queueNextStart].y;
    queueNextStart++;
}
void resetQueueNext() {
    queueNextStart = 0;
    queueNextEnd = 0;
}
int getQueueNextSize() {
    return queueNextEnd - queueNextStart;
}
void printBoard() {
    if (!isDebug) return;
    printf("----------------------------------\n");
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            printf("%d ", board[y][x]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
}

bool checkZero() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 0)
                return true;
        }
    }
    return false;
}

bool isValidPos(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N && !visited[y][x] && board[y][x] == 0) return true;
    return false;
}

bool getNextTick() {
    bool isChanged = false;
    while (getQueueSize() != 0) {
        int x, y;
        dequeue(x, y);
        if (isValidPos(x + 1, y)) {
            enqueueNext(x + 1, y);
            board[y][x + 1] = 1;
            visited[y][x + 1] = true;
            isChanged = true;
        }
        if (isValidPos(x - 1, y)) {
            enqueueNext(x - 1, y);
            board[y][x - 1] = 1;
            visited[y][x - 1] = true;
            isChanged = true;
        }
        if (isValidPos(x, y + 1)) {
            enqueueNext(x, y + 1);
            board[y + 1][x] = 1;
            visited[y + 1][x] = true;
            isChanged = true;
        }
        if (isValidPos(x, y - 1)) {
            enqueueNext(x, y - 1);
            board[y - 1][x] = 1;
            visited[y - 1][x] = true;
            isChanged = true;
        }
    }
    return isChanged;
}

void makeQueue() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 1) {
                enqueue(x, y);
                visited[y][x] = true;
            }
        }
    }
}
void moveQueue() {
    queueStart = 0;
    queueEnd = getQueueNextSize();
    for (int i = 0; i < getQueueNextSize(); i++) {
        queue[i] = queueNext[i + queueNextStart];
    }
    resetQueueNext();
}

int main() {
    scanf("%d %d", &M, &N); // M: 가로 칸 수, N: 세로 칸 수
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf("%d", &board[y][x]);
        }
    }
    int time = 0;
    makeQueue();
    while (true) {
        if (!getNextTick()) { // 변화가 없으면 break
            break;
        }
        printBoard();
        moveQueue();
        time++;
    }
    if (checkZero()) {
        printf("-1\n");
    } else {
        printf("%d\n", time);
    }
}

/*
문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 



창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

출력
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/
