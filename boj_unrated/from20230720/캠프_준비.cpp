#include <stdio.h>

int main() {
    int N, L, R, X; scanf("%d %d %d %d", &N, &L, &R, &X);
    int A[15];
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);

    int cases = 1 << N;
    int ans = 0;

    for(int cur = 0; cur < cases; ++cur) {
        // 완탐
        int max = 0; int min = 987654321;
        int sum = 0; int cnt = 0;
        for(int i = 0; i < N; ++i) {
            if ((1<<i) & cur) { // 비트가 켜져있으면 해당 문제를 선택
                sum += A[i];
                if ((max < A[i])) max = A[i];
                if ((min > A[i])) min = A[i];
                ++cnt;
                // printf("1");
            } else {
                // printf("0");
            }
        }
        // printf("\n");
        if (cnt < 2) continue;
        if (sum >= L && sum <= R && max - min >= X) {
            ans++;
            // printf("  -> added\n");
        }
    }

    printf("%d\n", ans);
    return 0;
}