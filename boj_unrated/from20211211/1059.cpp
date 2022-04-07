#include <stdio.h>

int main() {
    bool S[1001] = {0, };
    int L;
    scanf("%d", &L);
    for (register int i = 0; i < L; i++) {
        int t;
        scanf("%d", &t);
        S[t] = 1;
    }
    int N;
    scanf("%d", &N);
    if (S[N] == 1) printf("0\n");
    else {
        int m, M;
        for (register int i = N; i >= 1; i--) {
            if (S[i] == 1) {
                m = i;
                break;
            }
        }
        for (register int i = N; i <= 1000; i++) {
            if (S[i] == 1) {
                M = i;
                break;
            }
        }
        printf("%d\n", (N - m) * (M - N) - 1);
    }

    return 0;
}