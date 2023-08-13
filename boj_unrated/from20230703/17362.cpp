#include <stdio.h>

int main() {
    int N; scanf("%d", &N);
    int mode = (((N-1) / 4) % 2 == 0) ? 1 : 2;
    int v;
    if (mode == 1) { // 순방향
        v = N % 4;
        if (v == 0) v = 4;
    } else {
        if (N % 4 == 0) v = 2;
        else v = 5 - (N % 4) + 1;
    }

    printf("%d\n", v);

    return 0;
}