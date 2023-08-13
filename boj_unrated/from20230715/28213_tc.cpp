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
    printf("200000 200000\n");
    for(int i = 0; i < 200000; ++i) printf("%d ", rand() % 1000000000 + 1);
    printf("\n");
    for(int i = 0; i < 200000; ++i) {
        int l = rand() % 200000 + 1;
        int r = rand() % 200000 + 1;
        if (l > r) l ^= r ^= l ^= r;
        printf("%d %d %d\n", l, r, rand() % 1000000000 + 1);
        // printf("2 199999 987654321\n");
    }

    return 0;
}