#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == i) continue;
            printf(" ");
        }
        for (int j = 0; j < (T - i) * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= T - 1; i++) {
        for (int j = T - i - 1; j > 0; j--) {
            printf(" ");
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}


/*
입력이 5인 경우:
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********
*/
