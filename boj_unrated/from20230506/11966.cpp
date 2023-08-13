#include <stdio.h>

int main() {
    unsigned long long N;
    scanf("%lld", &N);
    N -= N & -N;
    if (N == 0) printf("1\n");
    else printf("0\n");
    return 0;
}