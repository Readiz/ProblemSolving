#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1000000;
vector<int> primes;
int isNotPrime[MAX + 1];

void solve() {
    int N; scanf("%d", &N);
    int M = N / 2;
    int ans = 0;
    for(; M >= 2; --M) {
        if (isNotPrime[M] == 0 && isNotPrime[N - M] == 0) {
            ++ans;
        }
    }

    printf("%d\n", ans);
}

void init() {
    for(int num = 2; num <= MAX; ++num) {
        if (isNotPrime[num] == 0) {
            primes.push_back(num);
            for(int k = num * 2; k <= MAX; k += num) {
                isNotPrime[k] = 1;
            }
        }
    }
}

int main() {
    init();
    int TC; scanf("%d", &TC);
    while(TC--) {
        solve();
    }
    return 0;
}

// 5
// 6
// 8
// 10
// 12
// 100