#include <stdio.h>

void solve() {
    int r, c; scanf("%d %d", &r, &c);
    int cr = 0, cc = 0;
    int dir = 1;
    int tcnt = r * c, cnt = 0;
    printf("1\n");

    // 왼쪽 쭉~ 아래로
    do {
        printf("(%d, %d)\n", cr, cc);
        ++cnt;
        if (cnt == r) break;
        ++cr;
    } while(true);

    if (r % 2) {
        dir = -1;
        cc = c - 1;
    } else {
        dir = 1;
        cc = 1;
    }

    do {
        printf("(%d, %d)\n", cr, cc);
        ++cnt;
        if (cnt == tcnt) break;
        if (dir == 1 && cc < c - 1) {
            ++cc;
        } else if (dir == 1 && cc == c - 1) {
            --cr;
            dir = -1;
        } else if (dir == -1 && cc > 1) {
            --cc;
        } else if (dir == -1 && cc == 1) {
            --cr;
            dir = 1;
        }
    } while(true);
}

int main() {
    int TC; scanf("%d", &TC);
    while(TC--) {
        solve();
    }
    return 0;
}