#include <stdio.h>

int main() {
    printf("100000\n");
    for(int i = 0; i < 100000; ++i)
        printf("2 ");
    printf("\n100000\n");
    for(int i = 0; i < 100000; ++i) {
        printf("1 100000 1\n");
    }
}