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

char brd[12][7] = {0, };
bool visited[12][7] = {false, };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int count = 0;
char target;

void printBrd() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c", brd[i][j]);
        }
        printf("\n");
    }
    printf("----------\n");
}

void DFS(int x, int y, char changeChar) {
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX <= 5 && newY >= 0 && newY <= 11 && !visited[newY][newX] && target == brd[newY][newX]) {
            count++;
            brd[newY][newX] = changeChar;
            visited[newY][newX] = true;
            DFS(newX, newY, changeChar);
            visited[newY][newX] = false;
        }
    }
}

bool applyGravity() {
    bool isChanged = false;
    for (int i = 11; i >= 1; i--) { // 아래부터 확인
        for (int j = 0; j < 6; j++) {
            if (brd[i][j] == '.' && brd[i - 1][j] != '.') {
                // 아래로 내리기..
                isChanged = true;
                brd[i][j] = brd[i - 1][j];
                brd[i - 1][j] = '.';
            }
        }
    }
    return isChanged;
}

// R, G, B, P, Y -> 색상
// r, g, b, p, y -> 체크가 끝난 색상
// -> 터진 부분 메우고 (일단 터지면 리턴값은 true), r, g, b, p, y를 되돌리기..
bool getNextTick() {
    // 4개 이상인 것을 x로 변경, 나머지는 소문자로 변경
    bool isChanged = false;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            count = 1;
            if (brd[i][j] >= 65 && brd[i][j] <= 90) { // DFS Start
                target = brd[i][j]; // 같은 문자열 찾기
                brd[i][j] = target + ('a' - 'A');
                visited[i][j] = true;
                DFS(j, i, target + ('a' - 'A')); // to Lower..
                visited[i][j] = false;
            }
            if (count >= 4) {
                isChanged = true;
                target = brd[i][j]; // 같은 문자열 찾기
                brd[i][j] = 'x';
                visited[i][j] = true;
                DFS(j, i, 'x');
                visited[i][j] = false;
            }
        }
    }
    if (isDebug) printBrd();
    // x를 삭제하기
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            count = 1;
            if (brd[i][j] == 'x') { // DFS Start
                target = brd[i][j]; // 같은 문자열 찾기
                brd[i][j] = '.';
                visited[i][j] = true;
                DFS(j, i, '.'); // to Lower..
                visited[i][j] = false;
            }
        }
    }
    // if (isDebug) printBrd();
    // 아래로 내리기 -> 변경할 것이 있으면 나중에 true를 리턴..
    while (applyGravity()) {
        // do nothing
    }
    
    // 소문자를 대문자로 복원하기
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (brd[i][j] >= 97 && brd[i][j] <= 122) { // DFS Start
                target = brd[i][j]; // 같은 문자열 찾기
                brd[i][j] = target - ('a' - 'A');
                visited[i][j] = true;
                DFS(j, i, target - ('a' - 'A')); // to Lower..
                visited[i][j] = false;
            }
        }
    }
    // if (isDebug) printBrd();
    return isChanged;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    for (int i = 0; i < 12; i++) {
        scanf("%s", &brd[i]);
    }
    if (isDebug) printBrd();

    int rensa = 0;
    // genNextTick() 함수는 bool로 변화가 있으면 true를 리턴..
    while (getNextTick()) {
        rensa++;
        printd("------ %d Rensa!", rensa);
    }
    printf("%d\n", rensa);
MAIN_END

/*
Puyo Puyo 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	13021	4885	3451	35.869%
문제
뿌요뿌요의 룰은 다음과 같다.

필드에 여러 가지 색깔의 뿌요를 놓는다. 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.

뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다.

뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례대로 아래로 떨어지게 된다.

아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데, 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.

터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.

남규는 최근 뿌요뿌요 게임에 푹 빠졌다. 이 게임은 1:1로 붙는 대전게임이라 잘 쌓는 것도 중요하지만, 상대방이 터뜨린다면 연쇄가 몇 번이 될지 바로 파악할 수 있는 능력도 필요하다. 하지만 아직 실력이 부족하여 남규는 자기 필드에만 신경 쓰기 바쁘다. 상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산하여 남규를 도와주자!

입력
총 12개의 줄에 필드의 정보가 주어지며, 각 줄에는 6개의 문자가 있다.

이때 .은 빈공간이고 .이 아닌것은 각각의 색깔의 뿌요를 나타낸다.

R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.

입력으로 주어지는 필드는 뿌요들이 전부 아래로 떨어진 뒤의 상태이다. 즉, 뿌요 아래에 빈 칸이 있는 경우는 없e다.

출력
현재 주어진 상황에서 몇연쇄가 되는지 출력한다. 하나도 터지지 않는다면 0을 출력한다.

예제 입력 1 
......
......
......
......
......
......
......
......
.Y....
.YG...
RRYG..
RRYGG.
예제 출력 1 
3
*/
