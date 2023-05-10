#include <stdio.h>

int main() {
    int a,b,c; scanf("%d %d %d", &a, &b, &c);
    while (a + b <= c || a + c <= b || b + c <= a) {
        if (a + b <= c) --c;
        if (a + c <= b) --b;
        if (b + c <= a) --a;
    }
    printf("%d\n", a + b + c);

    return 0;
}