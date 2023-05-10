#include <stdio.h>

int main() {
    while(true) {
        int a,b,c; scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        if (a == b && b == c) printf("Equilateral\n");
        else if (a + b <= c || a + c <= b || b + c <= a) printf("Invalid\n");
        else if (a != b && b != c && c != a) printf("Scalene\n");
        else printf("Isosceles\n");
    }

    return 0;
}