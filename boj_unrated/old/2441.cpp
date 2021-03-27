#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int K = 0;
    while (N >= 1) {
        for (int i = 0; i < K; i++) {
            printf(" ");
        }
        for (int i = 0; i < N; i++) {
            printf("*");
        }
        printf("\n");
        N--;
        K++;
    }
    return 0;
}
