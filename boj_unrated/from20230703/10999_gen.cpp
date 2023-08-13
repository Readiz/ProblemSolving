#include <stdio.h>

int main() {
    printf("1000000 1 2\n");
    for(int i = 0; i < 1000000; ++i) printf("1\n");
    printf("2 1 1000000\n");
    printf("1 1 1000000 1\n");
    printf("2 1 1000000\n");
    return 0;
}