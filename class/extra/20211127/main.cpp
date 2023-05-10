#include <stdio.h>
#include <time.h>
#include <memory.h>

#define SIZE 10000
extern void encode(char map[SIZE][SIZE], char data[150000]);
extern void decode(char map[SIZE][SIZE], char data[150000]);


static unsigned short pseudo_rand() {
    static unsigned long long seed = 5;
    return (unsigned short)((seed = seed * 25214903917ULL + 11ULL) >> 16);
}

char map_ori[SIZE][SIZE];
char map[SIZE][SIZE];
char data[150000];

void build() {
    for (register int c = 0; c < 10000; c++) {
        int sx = pseudo_rand() % SIZE;
        int ex = pseudo_rand() % SIZE;
        int sy = pseudo_rand() % SIZE;
        int ey = pseudo_rand() % SIZE;

        if (sx >= ex || sy >= ey) {
            c--;
            continue;
        }

        for (register int i = sx; i < ex; i++) {
            map[sy][i] = map_ori[sy][i] = 1;
            map[ey][i] = map_ori[ey][i] = 1;
        }
        for (register int i = sy; i < ey; i++) {
            map[i][sx] = map_ori[i][sx] = 1;
            map[i][ex] = map_ori[i][ex] = 1;
        }

    }
}

bool valid(char c1[SIZE][SIZE], char c2[SIZE][SIZE]) {
    for (register int y = 0; y < SIZE; y++)
        for (register int x = 0; x < SIZE; x++)
            if (c1[y][x] != c2[y][x]) return false;
    return true;
}

int main() {
    build();

    // int cnt_1 = 0, cnt_0 = 0;
    // for (register int i = 0; i < SIZE; i++) {
    //     for (register int j = 0; j < SIZE; j++) {
    //         if (i < 100 && j < 100)
    //             printf("%d", map[i][j]);
    //         if (map[i][j] == 0) cnt_0++;
    //         else cnt_1++;
    //     }
    //     printf("\n");
    // }
    // printf("COUNT_0: %d / COUNT_1: %d\n", cnt_0, cnt_1);


    clock_t s = clock();
    encode(map, data);
    memset(map, 0, 1 * SIZE * SIZE);
    decode(map, data);
    int SCORE = (clock() - s) / (CLOCKS_PER_SEC / 1000);
    if (valid(map_ori, map) == false) SCORE = 100000000;
    
    printf("SCORE: %d\n", SCORE);
    return 0;
}