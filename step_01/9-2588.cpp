#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int b1, b2, b3;
    b1 = b / 100;
    b2 = b / 10 - b1 * 10;
    b3 = b % 10;

    printf("%d\n", a * b3);
    printf("%d\n", a * b2);
    printf("%d\n", a * b1);
    printf("%d\n", a * b);
    return 0;
}
