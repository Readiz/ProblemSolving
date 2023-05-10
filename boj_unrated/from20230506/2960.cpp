#include <stdio.h>

int check[1010];

int main() {
    int N, K; scanf("%d %d", &N, &K);
    for(int i = 2; i <= N; ++i) {
        if (check[i] != 0) continue;
        // printf("%d is prime.\n", i);
        for(int j = 1; i * j <= N; ++j) {
            if (check[i*j] == 0) {
                check[i*j] = 1; // 지운다.
                // printf("delete %d...\n", i*j);
                --K;
                if (K == 0) {
                    printf("%d\n", i*j);
                    return 0;
                }
            }
        }
    }
    return 0;
}