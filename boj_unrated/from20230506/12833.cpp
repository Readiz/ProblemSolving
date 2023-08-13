#include <stdio.h>

int main() {
    int A, B, C; scanf("%d %d %d", &A,&B,&C);
    if (C & 1) printf("%d\n", A ^ B);
    else printf("%d\n", A);

    return 0;
}