#include <stdio.h>

int main() {
    unsigned long long N;
    scanf("%llu", &N);

    for(int j = 0; j < 64; ++j) {
        unsigned long long t = 1;
        // j만 실수
        for(int i = 0; i < 64; ++i) {
            t <<= 1;
            if (i == j) t -= 1;
        }
        if (t == N) {
            printf("%d\n", j + 1);
            return 0;
        }
    }
    return 0;
}