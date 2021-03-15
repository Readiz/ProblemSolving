#include <stdio.h>

int m[21][21][21] = { 0, };

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if (m[a][b][c] != 0) return m[a][b][c];
    if (a < b && b < c) {
        m[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return m[a][b][c];
    } else {
        m[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return m[a][b][c];
    }
}
int main() {
    // memo
    int k = 1;
    for (int i = 1; i <= 20; i++) {
        k *= 2;
        m[i][i][i] = k;
    }
    while (true) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}

/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
*/
