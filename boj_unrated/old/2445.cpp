#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int K = 1;
    while (N >= 1) {
        for (int i = 0; i < K; i++) {
            printf("*");
        }
        for (int i = (N - 1) * 2; i > 0; i --) {
            printf(" ");
        }
        for (int i = 0; i < K; i++) {
            printf("*");
        }
        printf("\n");
        N--;
        K++;
    }
    N++;
    K--;
    N++;
    K--;
    while (K >= 1) {
        for (int i = 0; i < K; i++) {
            printf("*");
        }
        for (int i = (N - 1) * 2; i > 0; i --) {
            printf(" ");
        }
        for (int i = 0; i < K; i++) {
            printf("*");
        }
        printf("\n");
        K--;
        N++;
    }
    return 0;
}
