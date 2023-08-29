#include <stdio.h>
int main() {
    printf("1000\n");
    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            printf("1 ");
        }
        printf("\n");
    }
    printf("1\n");
    return 0;
}