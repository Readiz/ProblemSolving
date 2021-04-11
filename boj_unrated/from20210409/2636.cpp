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

// 기본 클래스 생성 (DArray, DArray Based Queue)
typedef struct __N {
    int x;
    int y;
} Coord;

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
        size = 0;
        capacity = 100;
        n = new T[capacity];
    }
    void push(T item) {
        // 공간 다 찼을 경우.. 늘린다.
        if (size == capacity) {
            capacity *= 2; // 두배로 늘린다.
            T* newNodes = new T[capacity];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i]; // 기존 값 복사
            }
            delete[] n;
            n = newNodes;
        }
        n[size++] = item;
    }
    T& operator[] (int idx) {
        return n[idx];
    }
    ~DArray() {
        delete[] n;
    }
};

template<class T>
class Queue {
    DArray<T> db;
    int startPos;
public:
    Queue() {
        startPos = 0;
    };
    void enqueue(T n) {
        db.push(n);
    }
    T& dequeue() {
        return db[startPos++];
    }
    int getSize() {
        return db.size - startPos;
    }
};

int N, M;
char brd[101][101] = {0, };

void printBrd() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", brd[i][j]);
        }
        printf("\n");
    }
}

bool visited[101][101] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool canVisit(int x, int y) {
    if (!visited[y][x] && y >= 0 && y < N && x >= 0 && x < M) {
        return true;
    }
    return false;
}

void getNextTick() {
    Queue<Coord> q;
    Coord root;
    root.x = 0; root.y = 0;
    q.enqueue(root);
    visited[0][0] = true;

    while (q.getSize() > 0) {
        Coord& cur = q.dequeue();
        if (brd[cur.y][cur.x] == 0) {
            for (int i = 0; i < 4; i++) {
                if (canVisit(cur.x + dx[i], cur.y + dy[i])) {
                    Coord n;
                    n.x = cur.x + dx[i];
                    n.y = cur.y + dy[i];
                    q.enqueue(n);
                    visited[n.y][n.x] = true;
                }
            }
        } else if (brd[cur.y][cur.x] == 1) {
            brd[cur.y][cur.x] = 2; // 현재 녹을 치즈임
        }
    }
}

int getBorder() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (brd[i][j] == 2) {
                cnt++;
                brd[i][j] = 0;
            }
        }
    }
    return cnt;
}

void resetVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &brd[i][j]);
        }
    }
    if (isDebug) printBrd();
    int count = -1;
    int tick = 0;
    while (true) {
        printd("-------------------------");
        printd("Tick: %d", tick);
        printd("-------------------------");
        tick++;
        getNextTick();
        if (isDebug) printBrd();
        int nextCount = getBorder();
        if (nextCount == 0) {
            printf("%d\n%d\n", tick - 1, count);
            break;
        }
        count = nextCount;
        resetVisited();
    }
MAIN_END

/*
치즈 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	11185	5635	4144	51.370%
문제
아래 <그림 1>과 같이 정사각형 칸들로 이루어진 사각형 모양의 판이 있고, 그 위에 얇은 치즈(회색으로 표시된 부분)가 놓여 있다. 판의 가장자리(<그림 1>에서 네모 칸에 X친 부분)에는 치즈가 놓여 있지 않으며 치즈에는 하나 이상의 구멍이 있을 수 있다.

이 치즈를 공기 중에 놓으면 녹게 되는데 공기와 접촉된 칸은 한 시간이 지나면 녹아 없어진다. 치즈의 구멍 속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어가게 된다. <그림 1>의 경우, 치즈의 구멍을 둘러싼 치즈는 녹지 않고 ‘c’로 표시된 부분만 한 시간 후에 녹아 없어져서 <그림 2>와 같이 된다.



다시 한 시간 후에는 <그림 2>에서 ‘c’로 표시된 부분이 녹아 없어져서 <그림 3>과 같이 된다.



<그림 3>은 원래 치즈의 두 시간 후 모양을 나타내고 있으며, 남은 조각들은 한 시간이 더 지나면 모두 녹아 없어진다. 그러므로 처음 치즈가 모두 녹아 없어지는 데는 세 시간이 걸린다. <그림 3>과 같이 치즈가 녹는 과정에서 여러 조각으로 나누어 질 수도 있다.

입력으로 사각형 모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 때, 공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다. 세로와 가로의 길이는 최대 100이다. 판의 각 가로줄의 모양이 윗 줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어지며 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출력하고, 둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다.

예제 입력 1 
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
예제 출력 1 
3
5
*/
