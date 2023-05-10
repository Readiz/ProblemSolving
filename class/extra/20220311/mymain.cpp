#include <stdio.h>
#include <time.h>

#define DEST 40000

static unsigned long long seed = 13;
const int result = 80275;

char map[40000][40000];

int test(char map[40000][40000]);

void build() {
    for (register int y = 0; y < DEST; y++) {
        for (register int x = 0; x < DEST; ) {
            seed = seed * 25214903917ULL + 11ULL;
            for (register int c = 0; c < 64; c += 2) {
                map[y][x++] = (seed >> c) & 3ULL;
            }
        }
    }
}

int main() {
    double SCORE = 0;

    build();

    time_t start = clock();
    if (test(map) != result) SCORE += 100000000.0;
    SCORE += (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("SCORE: %lf\n", SCORE);
    
    return 0;
}