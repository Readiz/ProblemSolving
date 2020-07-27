#include <stdio.h>
int static board[9][9] = { {0, }, };
int static solution[9][9] = { {0, }, };
bool static checkFinished() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] + solution[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool static checkValidAns() {
    // 가로 + 세로
    for (int i = 0; i < 9; i++) {
        int sumHor = 0;
        int sumVer = 0;
        for (int j = 0; j < 9; j++) {
            sumHor += board[i][j];
            sumVer += board[j][i];
        }
        if (sumHor != 45 || sumVer != 45) return false;
    }
    // 구역
    for (int offsetX = 0; offsetX < 9; offsetX += 3) {
        for (int offsetY = 0; offsetY < 9; offsetY += 3) {
            int sumArea = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sumArea += board[i + offsetX][j + offsetY];
                }
            }
            if (sumArea != 45) return false;
        }
    }
    return true;
}

bool static getEasySol() {
    bool changedFlag = false;
    // 가로 + 세로
    for (int i = 0; i < 9; i++) {
        int countHor = 0;
        int countVer = 0;
        int sumHor = 0;
        int sumVer = 0;
        int zeroPosHor = 0;
        int zeroPosVer = 0;

        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                countHor++;
                zeroPosHor = j;
            }
            sumHor += board[i][j];
            if (board[j][i] == 0) {
                countVer++;
                zeroPosVer = j;
            }
            sumVer += board[j][i];
        }
        if (countHor == 1) { // 답이 명백한 케이스..
            board[i][zeroPosHor] = 45 - sumHor;
            changedFlag = true;
        }
        if (countVer == 1) {
            board[zeroPosVer][i] = 45 - sumVer;
            changedFlag = true;
        }
    }
    // 구역
    for (int offsetX = 0; offsetX < 9; offsetX += 3) {
        for (int offsetY = 0; offsetY < 9; offsetY += 3) {
            int sumArea = 0;
            int countZero = 0;
            int countZeroPosX;
            int countZeroPosY;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sumArea += board[i + offsetX][j + offsetY];
                    if (board[i + offsetX][j + offsetY] == 0) {
                        countZero++;
                        countZeroPosX = i + offsetX;
                        countZeroPosY = j + offsetY;
                    }
                }
            }
            if (countZero == 1) { // 마찬가지로 답이 명백한 케이스...
                board[countZeroPosX][countZeroPosY] = 45 - sumArea;
                changedFlag = true;
            }
        }
    }
    return changedFlag;
}

void static getAns(int startFrom) {
    if (checkFinished()) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                board[i][j] += solution[i][j];
        if (checkValidAns()) {
            return;
        }
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                board[i][j] -= solution[i][j];
    }
    for (int k = startFrom; k < 9 * 9; k++) {
        int i = k / 9;
        int j = k % 9;
        if (board[i][j] == 0) {
            for (int n = 1; n <= 9; n++) {
                // printf("on %d, %d: trying [%d]\n", i, j, n);
                solution[i][j] = n;
                getAns(k + 1);
                solution[i][j] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            scanf("%d", &tmp);
            board[i][j] = tmp;
        }
    }

    for (int k = 0; k < 5; k++) {
        getEasySol();
    }
    getAns(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j] + solution[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/* 
스도쿠
0 에 해당하는 곳을 채우는 것
*/
