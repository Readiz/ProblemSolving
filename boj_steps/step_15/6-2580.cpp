#include <stdio.h>
int static board[9][9] = { {0, }, };
// 일종의 해시 테이블 체커..
bool static row[9][10] = { {false, }, };
bool static col[9][10] = { {false, }, };
bool static area[9][10] = { {false, }, };

inline int static mapToArea(int x, int y) {
    return x / 3 * 3 + y / 3;
}

bool static getAns(int startFrom) {
    if (startFrom >= 9 * 9) 
        return true;
    int i = startFrom / 9;
    int j = startFrom % 9;
    while (board[i][j] != 0) {
        startFrom++;
        i = startFrom / 9;
        j = startFrom % 9;
        if (startFrom >= 9 * 9) 
            return true;
    }
    for (int n = 1; n <= 9; n++) {
        // 아직 안쓰인 숫자에 대해서만 수행
        if (!row[i][n] && !col[j][n] && !area[mapToArea(i, j)][n]) {
            board[i][j] += n;
            row[i][n] = col[j][n] = area[mapToArea(i, j)][n] = true;
            if (getAns(startFrom + 1)) return true;
            board[i][j] -= n;
            row[i][n] = col[j][n] = area[mapToArea(i, j)][n] = false;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            scanf("%d", &tmp);
            board[i][j] = tmp;
            if (tmp) {
                row[i][tmp] = true;
                col[j][tmp] = true;
                area[mapToArea(i, j)][tmp] = true;
            }
        }
    }

    getAns(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
추가 연구 항목: 아래 Worst TC를 통과하는 법?
0 2 3 4 5 6 7 8 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
2 4 5 0 0 0 0 0 0
0 6 7 0 0 0 0 0 0
3 8 9 0 0 0 0 0 0
*/

/* 
스도쿠
0 에 해당하는 곳을 채우는 것
*/
