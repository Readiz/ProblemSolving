#include <math.h>
#include <stdio.h>
typedef unsigned long long ull;
#define R register
#define sqr(x) ((x) * (x))
#define COUNT_PLANETS 100'000
extern void test(double coord[100'000][3], int results[3]);

unsigned short m_rand() {
    static ull seed = 5;
    return ((unsigned short)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}

double coord[100'000][3];

int main() {

    for (R int i = 0; i < COUNT_PLANETS; i++) {
        coord[i][0] = (double) (m_rand() / (double)(m_rand() + 1));
        coord[i][1] = (double) (m_rand() / (double)(m_rand() + 1));
        coord[i][2] = (double) (m_rand() / (double)(m_rand() + 1));
    }
    int results[3] = {0, };
    test(coord, results);

    double score = 0;
    for (R int i = 0; i < COUNT_PLANETS; i++) {
        double min = 100000000000.0;
        for (int k = 0; k < 3; k++) {
            double dist = sqr(coord[i][0] - coord[results[k]][0]) + \
                        sqr(coord[i][1] - coord[results[k]][1]) + \
                        sqr(coord[i][2] - coord[results[k]][2]);
            if (dist < min) {
                min = dist;
            }
        }
        score += sqrt(min);
    }
    printf("RESULT: %lf\n", score);

    return 0;
}