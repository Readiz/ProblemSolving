#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
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
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define INT_MIN 0x80000000

int R, C;
char map[21][21];
int curCount = 0;
int maxCount = INT_MIN;
bool visitedChar[26] = {false, }; // 방문한 알파벳
bool visited[21][21] = {false, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int atoi(char a) {
    return a - 'A';
}

bool checkPos(int x, int y) {
    if (!visited[y][x] && x >= 0 && x < C && y >= 0 && y < R) {
        return true;
    }
    return false;
}

void DFS(int x, int y) {
    // printd("visited: %d, %d", x, y);
    // 이 문제의 종료 조건은 어차피 boundry에 막히면 끝나게 되므로, 따로 넣지 않는다.
    if (curCount > maxCount) {
        maxCount = curCount;
    }

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (checkPos(newX, newY)) {
            if (!visitedChar[atoi(map[newY][newX])]) {
                visitedChar[atoi(map[newY][newX])] = true;
                visited[newY][newX] = true;
                curCount++;
                DFS(newX, newY);
                curCount--;
                visited[newY][newX] = false;
                visitedChar[atoi(map[newY][newX])] = false;
            }
        }
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", map[i]);
    }

    visitedChar[atoi(map[0][0])] = true;
    visited[0][0] = true;
    curCount = 1;
    DFS(0, 0);

    printf("%d\n", maxCount);
MAIN_END

/*
알파벳 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	48178	15300	9350	29.429%
문제
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.

예제 입력 1 
2 4
CAAB
ADCB
예제 출력 1 
3
*/
