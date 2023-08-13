#include <bits/stdc++.h>

int main() {
    unsigned int N;
    scanf("%d", &N);

    int R = -((int)N);

    unsigned int bitsdiff = R ^ (unsigned int)N;
    printf("%d\n", __builtin_popcount(bitsdiff));

    return 0;
}