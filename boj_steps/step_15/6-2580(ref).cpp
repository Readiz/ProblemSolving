#include <stdio.h>

#define idx_to_sq(a, b) a / 3 * 3 + b / 3
using namespace std;
int row[9][10], col[9][10], sq[9][10];
int sdoku[9][9];

bool DFS(int x, int y) {
    if (y == 9)
        return true;

    while (sdoku[x][y]) {
        x = x + 1;
        if (x == 9) {
            x = 0;
            y = y + 1;
        }
        if (y == 9)
            return true;
    }

    int nx = x + 1;
    int ny = y;

    if (nx == 9) {
        nx = 0;
        ny = y + 1;
    }

    for (int i = 1; i <= 9; i++) {
        if (row[x][i] && col[y][i] && sq[idx_to_sq(x, y)][i]) {
            sdoku[x][y] = i;
            row[x][i] = col[y][i] = sq[idx_to_sq(x, y)][i] = false;

            if (DFS(nx, ny))
                return true;

            sdoku[x][y] = 0;
            row[x][i] = col[y][i] = sq[idx_to_sq(x, y)][i] = true;
        }
    }
    return false;
}

int main() {
    for (size_t i = 0; i < 9; i++) {
        for (size_t j = 0; j < 10; j++) {
            row[i][j] = true;
            col[i][j] = true;
            sq[i][j] = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sdoku[i][j]);
            if (sdoku[i][j]) {
                row[i][sdoku[i][j]] = false;
                col[j][sdoku[i][j]] = false;
                sq[idx_to_sq(i, j)][sdoku[i][j]] = false;
            }
        }
    }

    DFS(0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", sdoku[i][j]);
        printf("\n");
    }

    return 0;
}
