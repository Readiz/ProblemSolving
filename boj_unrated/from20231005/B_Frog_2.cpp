#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll DP[100010]; // minimum cost
int main() {
    int N, K; scanf("%d%d", &N, &K);
    vector<int> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &v[i]);
    memset(DP, 0x3A, sizeof(ll) * 100010);
    DP[1] = 0;
    for(int i = 2; i <= N; ++i) {
        for(int k = 1; k <= K; ++k) {
            if (i - k >= 1) DP[i] = min(DP[i], DP[i - k] + abs(v[i] - v[i - k]));
        }
    }
    printf("%lld\n", DP[N]);
    return 0;
}