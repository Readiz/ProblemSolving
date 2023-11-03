#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull checker[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
// int checker[] = {2, 7, 61}; // int 범위일 때

ull addmod(ull x, ull y, ull m) {
    if (x >= m - y) {
        return x - (m - y);
    } else {
        return x + y;
    }
}
ull mulmod(ull x, ull y, ull m) {
    ull r = 0ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = addmod(r, x, m);
        x = addmod(x, x, m);
        y /= 2;
    }
    return r;
}
ull powmod(ull x, ull y, ull m) {
    ull r = 1ULL;
    while (y > 0) {
        if (y % 2 == 1) {
            r = mulmod(r, x, m);
        }
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}

// Miller-Rabin checker
// true를 리턴한다고 해서 무조건 소수인 것은 아님. (확률적 소수)
// 그러나 특정 수들에 대해 (checker 배열) 모두 검사한다면, 확정적으로 소수임을 판별가능.
// (log n)^3 알고리즘
bool MR(ull N, ull A) {
    ull d = N - 1;
    while (d % 2 == 0) {
        if (powmod(A, d, N) == N - 1) {
            return true;
        }
        d /= 2;
    }

    ull tmp = powmod(A, d, N);
    if (tmp == N - 1 || tmp == 1) { // a^(d*2^r) mod n = -1 판정 하는 부분임
        return true;
    } else {
        return false;
    }
}

bool isPrime(ull N) {
    if (N <= 1) {
        return false;
    } else if (N == 2) {
        return true;
    } else if (N <= 10000000000ULL) { // 기존 방법이 빠른 구간 + 밀러라빈 checker 수보다 작은 구간
        for (ull i = 3ULL; i * i <= N; i += 2) { // 홀수만 검사한다.
            if (N % i == 0ULL) return false; // 나누어 떨어지면, 소수
        }
        return true;
    } else {
        for (int i = 0; i < 7; i++) { // 7: checker size
            ull A = checker[i];
            if (MR(N, A) == false) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    ull N; scanf("%llu", &N);
    printf("%d\n", isPrime(N));
    return 0;
}