#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define R register
#define FOR(i,a,b) for(R int i=(a);((i)^(b)); ++i)
#define _D(...) printf(__VA_ARGS__)

typedef unsigned long long ull;
typedef __int128 lll;

// Refer to https://casterian.net/archives/396
ull checker[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
ull N;

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

// 빠른 거듭제곱.. (2^N) 을 반복해서 곱하는 방식.
ull powmod(ull x, ull y, ull m) {
    ull r = 1ULL;
    // 이진수 연산한다고 생각.. 2^n 꼴은 자리수 올리고.. 아닌 경우 더하고..
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

ull pseudo_rand(ull start, ull end) {
    static ull seed = 3ULL;
    seed = seed * 214013ULL + 2531011ULL;
    ull r = (seed >> 16) & 0xFFFFFFFFFFFFFFFF;
    r %= end - start;
    return r + start;
}

ull gcd(ull a, ull b) {
    while (b != 0ULL) {
        ull r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ull abssub(ull a, ull b) {
    if (a > b) return a - b;
    return b - a;
}
// pollardRho 합성수 구하기 : O(N^(1/4))
ull PR(ull N) {
    if (N == 1) return 1;
    if (N % 2 == 0) return 2;
    if (isPrime(N)) return N;

    ull x = pseudo_rand(2, N);
    ull y = x;
    ull c = pseudo_rand(1, N);
    ull d = 1;
    while (d == 1) {
        // 이 부분에서, ull이 overflow가 나기 때문에, lll(__int128) 비표준을 잠시 사용한다.
        x = (ull)((((lll)x * (lll)x) % N) + c + N) % N;
        y = (ull)((((lll)y * (lll)y) % N) + c + N) % N;
        y = (ull)((((lll)y * (lll)y) % N) + c + N) % N;
        d = gcd(abssub(x, y), N);
        if (d == N) {
            return PR(N);
        }
    }
    if (isPrime(d)) {
        return d;
    } else { // 소수가 아니면, 재귀적으로 반복. (합성수를 리턴하는 것이니) - 이래서 확률적임..
        return PR(d);
    }
}

int main() {
    ull N;
    scanf("%llu", &N);
    
    map<ull, ull> results;
    while (N > 1) {
        ull r = PR(N);
        if (results.find(r) == results.end()) {
            results[r] = 1;
        } else {
            results[r] += 1;
        }
        N /= r;
    }

    // for(auto item: results) {
    //     printf("%d - %d\n", item.first, item.second);
    // }

    bool flag = true;
    while (flag) {
        flag = false;
        for(auto item: results) {
            if (item.second >= 2) {
                results[item.first] = 0;
                ull nv = item.first * item.second;
                if (results.find(nv) == results.end()) {
                    results[nv] = 1;
                } else {
                    results[nv] += 1;
                }
                flag = true;
                break;
            }
        }
    }

    // printf("---\n");
    // for(auto item: results) {
    //     printf("%d - %d\n", item.first, item.second);
    // }


    printf("%llu\n", results.rbegin()->first);

    return 0;
}