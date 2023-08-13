#include <stdio.h>

int rand15() {
    static unsigned int seed = 5;
    seed = 214013 * seed + 2531011;
    return (seed >> 16) & 0x7FFF;
}

unsigned int rand() {
    return (rand15() << 30) | (rand15() << 15) | rand15();
}

int main() {
    printf("100000\n");
    for(int i = 0; i < 100000; ++i) {
        printf("%d ", rand() % 1000000000 + 1);
    }
    printf("\n100000\n");
    for(int i = 0; i < 100000; ++i) {
        int cmd = rand() % 4 + 1;
        int x = rand() % 100000 + 1;
        int y = rand() % 100000 + 1;
        if (x > y) x ^= y ^= x ^= y;
        printf("%d ", cmd);
        if (cmd == 4) {
            printf("%d %d\n", x, y);
        } else {
            printf("%d %d %d\n", x, y, rand() % 1000000000 + 1);
        }
        // if (x == 1095 && y == 48963) {
        //     printf("i: %d\n", i);
        //     return 0;
        // }
    }
    return 0;
}