#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        for (int i = 1; i <= (T + 1) / 2; i++) {
            printf("* ");
        }
        printf("\n");
        if (T >= 2) {
            for (int i = 1; i <= T / 2; i++) {
                printf(" *");
            }
            printf("\n");
        }
    }

    return 0;
}


/*
별 출력 하기... 규칙에 맞춰서.
*/
