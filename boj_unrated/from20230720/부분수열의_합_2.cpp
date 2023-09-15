#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll ODP[9'000'010] = {0, };
int main() {
    int N, S; scanf("%d%d", &N, &S);
    ll *DP = &ODP[4'500'005];
    ll A[40]; for(int i = 0; i < N; ++i) scanf("%lld", &A[i]);
    
    for(int i = 0; i < N; ++i) {
        ll cur = A[i];
        if (A[i] >= 0) {
            for(int j = 4'000'000; j >= -4'000'000; --j) {
                DP[j] += DP[j-A[i]];
            }
            DP[A[i]] += 1;
        } else {
            for(int j = -4'000'000; j <= 4'000'000; ++j) {
                DP[j] += DP[j-A[i]];
            }
            DP[A[i]] += 1;
        }
    }
    printf("%lld\n", DP[S]);
    return 0;
}