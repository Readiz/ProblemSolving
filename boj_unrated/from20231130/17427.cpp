#include <bits/stdc++.h>
using namespace std;

long long g(int x) {
    long long ret = 0;
    for(int i = 1; i <= x; ++i) {
        ret += i * (x / i);
    }
    return ret;
}

void solve(int N) {
    printf("%lld\n", g(N));
}

int main() {
    int N;
    scanf("%d", &N);
    solve(N);

    return 0;
}