#include <stdio.h>

int main() {
    int fib[1000] = {0, };
    int p = 2;
    int pprev = 0, prev = 1, cur = 1;
    while (p < 1000) {
        pprev = prev;
        prev = cur;
        cur = pprev + prev;
        fib[p++] = cur;
    }
    for (int i = 0; i < 1000; i++) {
        printf("%d, ", fib[i]);
    }
}