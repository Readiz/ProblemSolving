#include <stdio.h>

int main() {
    int dan;
    scanf("%d", &dan);

    for (int i = 1; i <= 9; i++) {
        printf ("%d * %d = %d\n", dan, i, dan * i);
    }
    return 0;
}

/*
2 * 1 = 2
2 * 2 = 4
2 * 3 = 6
2 * 4 = 8
2 * 5 = 10
2 * 6 = 12
2 * 7 = 14
2 * 8 = 16
2 * 9 = 18
*/