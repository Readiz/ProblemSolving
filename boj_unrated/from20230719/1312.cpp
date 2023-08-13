#include <stdio.h>

int main() {
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    int c = N % M;
    int p = N / M;
    for(int i = 1; i <= K; ++i) {
        c *= 10;
        p = c / M;
        c = c % M;
    }
    printf("%d\n", p);
}