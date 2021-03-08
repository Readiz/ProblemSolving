#include <stdio.h>

bool isDebug = false;
int N;
int board[25][25] = {0, };
int countSort[626] = {0, };
int overallCount = 0;

void printBoard() {
    if (!isDebug) return;
    printf("----------------------------------\n");
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            printf("%d ", board[y][x]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
}

bool isValidPos(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) return true;
    return false;
}

void checkNeighbor(int x, int y) {
    if (!isValidPos(x, y)) return;
    if (board[y][x] == 1) {
        board[y][x] = 2;
        // 인접된 녀석들을 2로 만든다.. DFS.
        checkNeighbor(x + 1, y);
        checkNeighbor(x - 1, y);
        checkNeighbor(x, y + 1);
        checkNeighbor(x, y - 1);
    }
}

void deleteCache() { // 2를 지운다
    int count = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == 2) {
                board[y][x] = 0;
                count++;
            }
        }
    }
    countSort[count]++;
}

void findAPT() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == 1) { // 집을 찾았으면
                board[y][x] = 2; // 타겟 집은 2로 설정
                 // 인접된 녀석들을 2로 만든다.. DFS.
                checkNeighbor(x + 1, y);
                checkNeighbor(x - 1, y);
                checkNeighbor(x, y + 1);
                checkNeighbor(x, y - 1);
                printBoard();
                // 2는 이제 삭제
                deleteCache();
                overallCount++;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int j = 0; j < N; j++) {
        char row[30];
        scanf("%s", row);
        int ptr = 0;
        while (row[ptr] != 0) {
            if (row[ptr] == '0') {
                board[j][ptr] = 0;
            } else {
                board[j][ptr] = 1;
            }
            ptr++;
        }
    }
    findAPT();
    
    printf("%d\n", overallCount);
    // 카운팅 소트 배열 출력
    for (int i = 1; i <= 625; i++) {
        if (countSort[i] != 0) {
            for (int j = 0; j < countSort[i]; j++) {
                printf("%d\n", i);
            }
        }
    }
}

/*
문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

예제 입력 1 
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
예제 출력 1 
3
7
8
9
*/
