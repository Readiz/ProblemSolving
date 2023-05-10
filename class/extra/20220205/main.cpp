#include <stdio.h>
#include <math.h>
#include <time.h>

int alpha, beta;
#define CNTHOUSE 100000
unsigned int alloc[CNTHOUSE];
double station[5];
double house[CNTHOUSE];

extern void test(double const house[], double station[], unsigned int alloc[]);


static unsigned short pseudo_rand() {
    static unsigned long long seed = 5;
    unsigned short r = (unsigned short)((seed = seed * 25214903917ULL + 11ULL) >> 16);
    // printf("VAL: %d\n", r);
    return r;
}


void build() {
    alpha = pseudo_rand() % 100;
    beta = pseudo_rand() % 100;

    printf("Alpha: %d / Beta: %d\n", alpha, beta);

    for (register int i = 0; i < CNTHOUSE;) {
        int tmp = 0;
        for (int c = 0; c < 3; c++) {
            tmp += pseudo_rand() % 100;
        }
        house[i++] = (double)((((tmp / 3) + alpha) % 100) + (pseudo_rand() % 1000000) / 1000000.0);
        house[i++] = (double)((((tmp / 3) + beta) % 100) + (pseudo_rand() % 1000000) / 1000000.0);
    }

}


int main() {

    double SCORE = 0.0F;
    build();


    for (register int i = 0; i < 100; i++) {
        // printf("house[%3d] = %03.8lf\n", i, house[i]);
    }

    time_t start = clock();
    test(house, station, alloc);
    double deltatime = (double)((clock() - start) / CLOCKS_PER_SEC);
    printf("TIME SCORE: %lf\n", deltatime);
    SCORE += deltatime;
    
    for (register int i = 0; i < CNTHOUSE; i++) {
        alloc[i] %= 5;
        SCORE += fabs(station[alloc[i]] - house[i]);
    }
    int count[5] = {0, };
    for (register int i = 0; i < CNTHOUSE; i++) {
        count[alloc[i]]++;
    }
    for (int i = 0; i < 5; i++) {
        if (count[i] > 22000) {
            SCORE += 10000000;
        }
    }

    printf("SCORE: %lf\n", SCORE);
}