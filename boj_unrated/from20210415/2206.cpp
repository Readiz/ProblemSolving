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
#define R register

struct NextSearchInfo {
    int x;
    int y;
    int step;
    bool isWallBroken;
};

template<class T>
class Queue {
    T* n;
    int cap;
    int size;
    int startPos;
public:
    Queue() {
        init();
    }
    void init() {
        cap = 1000;
        size = 0;
        startPos = 0;
        n = new T[cap];
    }
    void enqueue(T data) {
        if (size == cap) {
            cap *= 2;
            T* newNodes = new T[cap];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i];
            }
            delete[] n;
            n = newNodes;
        }
        n[size++] = data;
    }
    T& dequeue() {
        return n[startPos++];
    }
    int getSize() {
        return size - startPos;
    }
};
Queue<NextSearchInfo> q;

char brd[1002][1002] = {0, };
bool visited[1002][1002][2] = {false, };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
int minReach = 0x7FFFFFFF;

void printBrd() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", brd[i][j]);
        }
        printf("\n");
    }
    printf("----------\n");
}

void BFSStart() {
    // (0, 0) 은 항상 뚫려 있으며, 해당 좌표에서 다음으로 갈 수 있는 곳은 항상 두곳 뿐
    NextSearchInfo n;
    if (M >= 2) { // 우측으로 이동 가능한 경우
        n.x = 1; n.y = 0; n.isWallBroken = false; n.step = 1;
        visited[0][1][n.isWallBroken] = true;
        q.enqueue(n);
    }
    if (N >= 2) { // 아래로 이동 가능한 경우
        n.x = 0; n.y = 1; n.isWallBroken = false; n.step = 1;
        visited[1][0][n.isWallBroken] = true;
        q.enqueue(n);
    }
    while(q.getSize() > 0) {
        n = q.dequeue();
        // 현재 좌표가 벽이 있고, 벽을 아직 뚫을 수 있는 경우에는 벽을 뚫었다고 표시한다.
        if (n.isWallBroken == false && brd[n.y][n.x] == '1') {
            n.isWallBroken = true;
        } else if (n.isWallBroken == true && brd[n.y][n.x] == '1') {
            continue; // 이미 벽을 뚫었을 경우에는 무시한다.
        }
        n.step++;
        if (n.step >= minReach) continue; // 더 진행할 필요 없음
        // 목표 지점에 도착 하였을 경우, 최소 reach 값을 확인
        if (n.x == M - 1 && n.y == N - 1) {
            if (n.step < minReach) {
                minReach = n.step;
                printd("minReach is updated to %d...", minReach);
            }
            continue;
        }
        int ox = n.x;
        int oy = n.y;
        for (R int i = 0; i < 4; i++) {
            int y = oy + dy[i];
            int x = ox + dx[i];
            if (y >= 0 && y < N && x >= 0 && x < M) {
                if (!visited[y][x][n.isWallBroken]) {
                    // 벽 처리는 나중에 하게 되므로, 그냥 visited가 아니면 무조건 queue에 추가한다.
                    n.x = x;
                    n.y = y;
                    visited[y][x][n.isWallBroken] = true;
                    q.enqueue(n);
                }
            }
        }

    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", &brd[i]);
    }
    if (isDebug) printBrd();

    if (N == 1 && M == 1) {
        printf("1\n");
    } else {
        BFSStart();
        if (minReach == 0x7FFFFFFF) {
            printf("-1\n");
        } else {
            printf("%d\n", minReach);
        }
    }

MAIN_END


/*
벽 부수고 이동하기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	192 MB	55168	13534	8348	22.602%
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

예제 입력 1 
6 4
0100
1110
1000
0000
0111
0000
예제 출력 1 
15
예제 입력 2 
4 4
0111
1111
1111
1110
예제 출력 2 
-1
*/