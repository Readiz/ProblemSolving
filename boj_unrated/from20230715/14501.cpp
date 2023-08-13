// DP 연습
#include <stdio.h>

int T[15], P[15];
int curMax;

int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &T[i], &P[i]);
    }

    int casemax = 1 << N;
    int gMax = -1;

    for(int mcase = 0; mcase < casemax; ++mcase) {
        int occ[15] = {0, };
        int curMax = 0;
        for(int i = 0; i < N; ++i) {
            if (mcase & (1 << i)) {
                for(int j = 0; j < T[i]; ++j) {
                    if (i + j >= N || occ[i + j]) {
                        curMax = -99999999;
                        break;
                    }
                    occ[i + j] = 1;
                }
                curMax += P[i];
            }
        }
        if (curMax > gMax) gMax = curMax;
    }

    printf("%d\n", gMax);


    return 0;
}