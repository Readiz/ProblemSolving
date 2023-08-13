#include <stdio.h>

int main() {
    long long N; scanf("%lld", &N);
    printf("%lld\n2\n", (((N-1)*N)>>1));
    return 0;
}