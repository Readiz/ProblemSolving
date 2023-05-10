#include <stdio.h>

int main() {
    printf("100\n");
    for(int k = 0; k < 100; ++k) {
        printf("1000 1000\n");
        for(int i = 0; i < 1000; ++i) {
            for(int j = 0; j < 1000; ++j) {
                printf("1 ");
            }
            printf("\n");
        }
    }
}