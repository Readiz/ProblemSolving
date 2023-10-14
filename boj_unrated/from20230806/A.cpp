#include <stdio.h>

int main() {
    int N, X; scanf("%d %d", &N, &X);
    int a = 0;
    for(int i = 0; i < N; ++i) {
        int t; scanf("%d", &t);
        a += t;
    }

    if (a % X == 0) printf("1\n");
    else printf("0\n");

    return 0;
}