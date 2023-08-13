#include <stdio.h>

int d[15] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10};
int dSize = 15;

int lb(int v) { // lower bound
    int l = 0, r = (sizeof(d) / sizeof(int)) - 1;
    while (l < r) { // 이건 고정이고
        int m = (l + r) >> 1;
        if (d[m] >= v) { // 등호에 유의
            r = m; // 등호 포함된게 r 결정, m을 포함해야 함. (m - 1로 두면, corner 생김)
        } else {
            l = m + 1;
        }
    }
    return l;
}

int ub(int v) {
    int l = 0, r = (sizeof(d) / sizeof(int)) - 1;
    while (l < r) { // 이건 고정이고
        int m = (l + r) >> 1;
        if (d[m] > v) { // 등호에 유의 -> lb 대비 등호만 없음.
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    // lower bound
    printf("%d\n", lb(3));
    printf("%d\n", ub(3));

}