#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
typedef unsigned __int128 lll;
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


ll a, b, c, d;
vector<ll> targetPrimes;
ll v1, v2;
ll ansx, ansy;
set<pair<ll,ll>> memo;
struct MINPUT {
    ll a, b, c, d;
    bool operator<(const struct MINPUT& t) const {
        if (a != t.a) return a< t.a;
        if (b != t.b) return b< t.b;
        if (c != t.c) return c< t.c;
        if (d != t.d) return d< t.d;
        return false;
    }
};
map<MINPUT, pair<ll,ll>> gmemo;
void dfs(int depth) {
    if (depth == targetPrimes.size()) {
        ll s1 = v1; ll s2 = v2; // step
        // _D("Checking %lld / %lld...\n", s1, s2);
        while (s1 <= c && s2 <= d) {
            // _D("  step: %lld / %lld\n", s1, s2);
            if (s1 > a && s1 <= c && s2 > b && s2 <= d) {
                ansx = s1;
                ansy = s2;
            }
            if (s1 + v1 <= c && s2 + v2 <= d) {
                s1 += v1; s2 += v2;
            } else if (s1 + v1 <= c) s1 += v1;
            else if (s2 + v2 <= d) s2 += v2;
            else break;
        }
        return;
    }
    if (memo.find({v1,v2}) != memo.end()) return;
    memo.insert({v1,v2});
    v1 *= targetPrimes[depth];
    if (v1 <= c && ansx == -1) dfs(depth + 1);
    v1 /= targetPrimes[depth];
    v2 *= targetPrimes[depth];
    if (v2 <= d && ansx == -1) dfs(depth + 1);
    v2 /= targetPrimes[depth];
}
void solve() {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if (gmemo.find(MINPUT{a,b,c,d}) != gmemo.end()) {
        pair<ll, ll> RES = gmemo[MINPUT{a,b,c,d}];
        printf("%lld %lld\n", RES.first, RES.second);
        return;
    }
    ll target = a * b;
    _D("A*B = %lld\n", target);
    targetPrimes.clear();
    memo.clear();
    v1 = 1; v2 = 1;
    ansx = -1; ansy = -1;
    while (target > 1) {
        ull r = PR(target);
        targetPrimes.push_back(r);
        target /= r;
    }
    sort(targetPrimes.begin(), targetPrimes.end());
    for(auto& i: targetPrimes) {
        _D("%lld ", i);
    }
    _D("\n");
    dfs(0);
    printf("%lld %lld\n", ansx, ansy);
    gmemo[MINPUT{a,b,c,d}] = {ansx, ansy};
    // for(ll x = a + 1; x <= c; ++x) {
    //     for(ll y = b + 1; y <= d; ++y) {
    //         if ((x * y) % (a * b) == 0) {
    //             printf("%lld %lld\n", x, y);
    //             return;
    //         }
    //     }
    // }
    // printf("-1 -1\n");
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
