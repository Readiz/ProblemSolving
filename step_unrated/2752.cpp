#include <stdio.h>

void swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}