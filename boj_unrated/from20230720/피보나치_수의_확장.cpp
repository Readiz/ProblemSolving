#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll MOD = 1'000'000'000;
ll ODP[2'000'010];
ll *fib;
void build() {
    fib = &ODP[1'000'005];
    
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= 1'000'000; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= MOD;
    }
    // 음수
    for(int i = -1; i >= -1'000'000; --i) {
        //fib[i+2] = fib[i+1] + fib[i];
        fib[i] = fib[i + 2] - fib[i + 1];
        fib[i] %= MOD;
    }
}

int main() {
    build();
    int N; scanf("%d", &N);
    if (N < 0 && abs(N) % 2 == 0) printf("-1\n");
    else if (N == 0) printf("0\n");
    else printf("1\n");
    printf("%lld\n", abs(fib[N]) % MOD);
    return 0;
}