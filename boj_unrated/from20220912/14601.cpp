#include <stdio.h>

int board[256][256];
int color = 0;

bool checkZero(int x, int y, int size) {
    for(int i = x; i < x + size; ++i)
        for(int j = y; j < y + size; ++j)
            if (board[i][j] != 0) return false;
    return true;
}
void paint(int x, int y, int size) {
    if (size == 1) return;

    int nsize = size >> 1; // size / 2
    ++color;

    if(checkZero(x, y, nsize))
        board[x + nsize - 1][y + nsize - 1] = color;
    if(checkZero(x, y + nsize, nsize))
        board[x + nsize - 1][y + nsize] = color;
    if(checkZero(x + nsize, y, nsize))
        board[x + nsize][y + nsize - 1] = color;
    if(checkZero(x + nsize, y + nsize, nsize))
        board[x + nsize][y + nsize] = color;

    paint(x, y, nsize);
    paint(x + nsize, y, nsize);
    paint(x, y + nsize, nsize);
    paint(x + nsize, y + nsize, nsize);
}

int main() {
    int k, x, y;
    scanf("%d %d %d", &k, &x, &y);
    board[y - 1][x - 1] = -1;
    int bSize = 1 << k;
    paint(0, 0, bSize);
    for(int i = bSize - 1; i >= 0; i--) {
        for(int j = 0; j < bSize; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}