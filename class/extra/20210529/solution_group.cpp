#include "main.cpp"
#define printd(...) { printf(__VA_ARGS__); }
typedef unsigned long long ull;
#define R register
#define sqr(x) ((x) * (x))
#define COUNT_PLANETS 100'000

int oc[100'000];
int ocSize = 0;
int ac[100'000][3];

void test(double coord[100'000][3], int results[3]) {
    double min;
    int minIdx = 0;
    for (R int i = 0; i < COUNT_PLANETS; i++) {
        double dist = sqr(coord[i][0] - 1) + sqr(coord[i][1] - 1) + sqr(coord[i][2] - 1);
        if (i == 0) {
            min = dist;
        } else {
            if (dist < min) {
                minIdx = i;
                min = dist;
            }
        }
        if (dist > 1000000) { // 거리가 1000 보다 멀면
            oc[ocSize++] = i;
        }
        ac[i][0] = (int) coord[i][0];
        ac[i][1] = (int) coord[i][1];
        ac[i][2] = (int) coord[i][2];
    }
    results[0] = minIdx;
    printd("[#%d] %lf, %lf, %lf\n", minIdx, coord[minIdx][0], coord[minIdx][1], coord[minIdx][2]);

    printd("OCSize: %d\n", ocSize);
    ull minDist = 0xFFFFFFFFFFFFFFFF;
    int minIdx1, minIdx2;
    for (R int i = 0; i < ocSize - 1; i++) {
        for (R int j = i + 1; j < ocSize; j++) {
            ull dist = 0ULL;
            for (int k = 0; k < ocSize; k++) {
                int c = oc[k];
                ull dist0 = sqr(ac[c][0] - 1) + sqr(ac[c][1] - 1) + sqr(ac[c][2] - 1);
                ull dist1 = sqr(ac[c][0] - ac[oc[i]][0]) + sqr(ac[c][1] - ac[oc[i]][1]) + sqr(ac[c][2] - ac[oc[i]][2]);
                ull dist2 = sqr(ac[c][0] - ac[oc[j]][0]) + sqr(ac[c][1] - ac[oc[j]][1]) + sqr(ac[c][2] - ac[oc[j]][2]);
                // printd("%llu / %llu / %llu\n", dist0, dist1, dist2);
                if (dist0 < dist1 && dist0 < dist2) {
                    dist += dist0;
                } else if (dist1 < dist2) {
                    dist += dist1;
                } else {
                    dist += dist2;
                }
            }
            // printd("dist: %llu\n", dist);
            if (dist < minDist) {
                minDist = dist;
                minIdx1 = oc[i];
                minIdx2 = oc[j];
                // printd("updated! dist: %llu\n", minDist);
            }
        }
    }
    results[1] = minIdx1;
    results[2] = minIdx2;
    printd("[#%d] %lf, %lf, %lf\n", minIdx1, coord[minIdx1][0], coord[minIdx1][1], coord[minIdx1][2]);
    printd("[#%d] %lf, %lf, %lf\n", minIdx2, coord[minIdx2][0], coord[minIdx2][1], coord[minIdx2][2]);
}
