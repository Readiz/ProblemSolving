#include <stdio.h>

int main() {
    int total;
    scanf("%d\n", &total);
    for (int i = 0; i < 9; i++) {
        int tmp;
        scanf("%d", &tmp);
        total -= tmp;
    }
    printf("%d\n", total);
    return 0;
}
