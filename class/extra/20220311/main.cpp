// Written by jseo@samsung.com

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>


int test(char map[40000][40000]);
int test_verify(char map[40000][40000]);


static unsigned long long seed; // This will be changed
static char map[40000][40000];
static char ori_map[40000][40000];

static void build(void)
{
   for (register int y = 0; y < 40000; y++)
   {
      for (register int x = 0; x < 40000; )
      {
         seed = seed * 25214903917ULL + 11ULL;
         for (register int c = 0; c < 64; c += 2)
         {
            ori_map[y][x++] = (seed >> c) & 0x0000000000000003ULL;
         }
      }
   }
}

int main(void)
{
    double OverallSCORE = 0.0;
    for (register int i = 1; i <= 100; i += 1) {
        seed = i;
        double SCORE = 0.0;

        build();
        memcpy(map, ori_map, 40000 * 40000 * sizeof(char));
        int result = test_verify(map);
        memcpy(map, ori_map, 40000 * 40000 * sizeof(char));
        time_t time = clock();
        int mresult = test(map);
        if (mresult != result) SCORE += 100000000;
        SCORE += (double)(clock() - time) / CLOCKS_PER_SEC;

        printf("seed: %d / ans: %d, res: %d -> SCORE: %lf\n", i, result, mresult, SCORE);
        OverallSCORE += SCORE;
    }
    printf("Overall Score: %lf\n", OverallSCORE);

    return 0;
}
