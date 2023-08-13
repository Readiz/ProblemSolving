#include <stdio.h>

int main() {
    printf("200000 200000\n");
    for(int i = 0; i < 200000; ++i) printf("1 ");
    printf("\n");
    for(int i = 0; i < 200000; ++i) printf("2 199999 100\n");

    return 0;
}