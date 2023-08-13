#include <stdio.h>


int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    // A^B % C 구하기
    long long r = 1;
    while(B) {
        if (B & 1) {
            r *= A;
            r %= C;
        }
        A = A * A;
        A %= C;
        B >>= 1;
        // printf("%lld %lld %lld\n", A, B, r);
    }
    printf("%lld\n", r);
    return 0;
}