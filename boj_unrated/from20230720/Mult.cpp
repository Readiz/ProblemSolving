#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int n; scanf("%d", &n);
    for(int i = 1; i < N; ++i) {
        int c; scanf("%d", &c);
        if (n == 0) n = c;
        else if (c % n == 0) {
            printf("%d\n", c);
            n = 0;
        }
    }
    return 0;
}