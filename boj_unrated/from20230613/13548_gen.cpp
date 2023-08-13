#include <stdio.h>

int rand() {
    static int seed = 5;
    seed = 214013 * seed + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int rrand() {
    return (rand() << 15) | rand();
}

int main() {
    printf("100000\n");
    for(int i = 0; i < 100000; ++i) {
        printf("%d ", rrand() % 100000 + 1);
    }
    printf("\n");
    printf("100\n");
    for(int i = 0; i < 100; ++i) {
        int l = rrand() % 100000 + 1;
        int r = rrand() % 100000 + 1;
        if (l > r) l ^= r ^= l ^= r;
        printf("%d %d\n", l, r);
    }
}