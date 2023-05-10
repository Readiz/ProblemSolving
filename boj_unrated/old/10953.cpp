#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char str[4];
        scanf("%s", str);
        printf("%d\n", (str[0] - '0') + (str[2] - '0'));
    }
}