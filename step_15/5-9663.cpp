#include <stdio.h>

int static N;
bool static board[15][15] = { { false, },  };
int static result = 0;

void static copyBoard(bool source[15][15], bool target[15][15]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            target[i][j] = source[i][j];
        }
    }
}
void static updateIfItIsPossible(int targetI, int targetJ) {
    if (targetI >= 0 && targetI < N && targetJ >= 0 && targetJ < N) {
        board[targetI][targetJ] = true;
    }
}
void static updateBoard(int targetI, int targetJ) {
    // 좌/우, 상/하
    for (int i = 0; i < N; i++) {
        board[i][targetJ] = true;
    }
    for (int j = 0; j < N; j++) {
        board[targetI][j] = true;
    }
    // 대각선
    for (int i = 0; i < N; i++) {
        updateIfItIsPossible(targetI - i, targetJ - i);
        updateIfItIsPossible(targetI - i, targetJ + i);
        updateIfItIsPossible(targetI + i, targetJ - i);
        updateIfItIsPossible(targetI + i, targetJ + i);
    }
}

void static printBoard() {
    printf("------------\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) printf("X");
            else printf("O");
        }
        printf("\n");
    }
    printf("------------\n");
}

void static calculateStep(int step, int startFrom) {
    if (step == N) { // 최종까지 왔을 경우
        result++; // 결과를 추가한다.
        return;
    }
    // printf("StartFrom: %d\n", startFrom);
    for (int k = startFrom; k < N * N; k++) {
        int i = k / N;
        int j = k % N;
        // printf("%d, %d called!\n", i, j);
        // 추가로 현재 위치에 놓을 수 있을 때만 계산
        if (board[i][j] == false) {
            // 현 위치 백업
            bool tmpBoard[15][15];
            copyBoard(board, tmpBoard);
            updateBoard(i, j);
            // printBoard();
            // 다음 단계 계산
            calculateStep(step + 1, k + 1);
            // 백업본으로 되돌리기
            copyBoard(tmpBoard, board);
        }
    }
    return;
}

int main() {
    int memo[16] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 0, 0, 0};
    scanf("%d", &N);
    calculateStep(0, 0);
    printf("%d\n", result);
    // printf("%d\n", memo[N]);
    return 0;
}

/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/
