#include <stdio.h>

unsigned int seed = 5;
int rand() {
    seed = seed * 214013 * 2531011;
    return (seed >> 16) & 0x7FFF;
}

int main() {
    int K = 50'000;
    printf("1\n%d\n", K);
    for(int i = 0; i < K; ++i) {
        printf("%d ", rand() % 10000 + 1);
        // printf("%d ", 10000);
    }
    printf("\n");

    return 0;
}