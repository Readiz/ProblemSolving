#include <stdio.h>

int main() {
    int T, a, b;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= T - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i * 2; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
