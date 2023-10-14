#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll DP[100010]; // minimum cost
int main() {
    int N; scanf("%d", &N);
    vector<int> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &v[i]);
    memset(DP, 0x3A, sizeof(ll) * 100010);
    DP[1] = 0;
    DP[2] = abs(v[2] - v[1]);
    for(int i = 3; i <= N; ++i) {
        DP[i] = min(DP[i - 2] + abs(v[i] - v[i - 2]), DP[i - 1] + abs(v[i] - v[i - 1]));
    }
    printf("%lld\n", DP[N]);
    return 0;
}