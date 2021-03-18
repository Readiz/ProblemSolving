#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int lcm(int a, int b, int c) {
    return lcm(lcm(a, b), c);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int T = 0; T < tc; T++) {
        int N, K; // K = 3
        scanf("%d %d", &N, &K);
        int a, b, c;
        for (a = 1; a < N - 1; a++) {
            for (b = 1; b < N - 1; b++) {
                c = N - a - b; // Condition 1 is fullfilled.
                if (c <= 0) continue;
                if (lcm(a, b, c) <= N / 2) {
                    goto out;
                }
            }
        }
        out:
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}