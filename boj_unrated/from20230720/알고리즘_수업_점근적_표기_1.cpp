#include <stdio.h>
int main() {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);

    if (c >= a && a * d + b <= c * d) printf("1\n");
    else printf("0\n");

    return 0;
}