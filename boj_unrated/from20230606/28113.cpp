#include <stdio.h>

int main() {
    int A, N, B; scanf("%d %d %d", &N, &A, &B);
    if (N <= B) {
        if (A == B) printf("Anything\n");
        else if (A < B) printf("Bus\n");
        else printf("Subway\n");
    } else {
        printf("Bus\n");
    }
    return 0;
}