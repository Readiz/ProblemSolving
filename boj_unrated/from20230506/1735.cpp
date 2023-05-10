#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int aa = a;
        a = b;
        b = aa % b;
    }
    return a;
}
int main() {
    int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
    int up = a * d + b * c;
    int down = b * d;

    int g = gcd(up, down);
    printf("%d %d\n", up / g, down / g);
    return 0;
}