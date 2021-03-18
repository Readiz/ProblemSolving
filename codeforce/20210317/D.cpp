#include <stdio.h>

int N;

int main() {
    int r = 2;
    for (int i = 0; i < 20; i++) {
        r *= 2;
    }
    printf("%d\n", r);
    int tc;
    for (int t = 0; t < tc; t++) {
        scanf("%d", &N);
    }

    return 0;
}