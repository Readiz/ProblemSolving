#include <stdio.h>

int main() {
    printf("1000000\n");
    for(int i = 0; i < 1000000; ++i) {
        printf("%d ", (i + 1) * 100);
    }
    printf("\n");
    printf("1000000\n");
    int l = 0, r = 1000001;
    for(int i = 0; i < 1000000; ++i) {
        ++l, --r;
        if (l <= r) {
            printf("%d %d\n", l, r);
        } else {
            printf("%d %d\n", r, l);
        }
    }
}