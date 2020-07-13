#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // (A+B)%C는 ((A%C) + (B%C))%C 와 같을까?
    // (A×B)%C는 ((A%C) × (B%C))%C 와 같을까?
    printf("%d\n", (a+b)%c);
    printf("%d\n", ((a%c)+(b%c))%c);
    printf("%d\n", (a*b)%c);
    printf("%d\n", ((a%c)*(b%c))%c);
    return 0;
}
