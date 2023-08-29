#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    vector<int> DP(N+1);
    constexpr int INF = 987654321;
    fill(DP.begin(), DP.end(), INF);
    int a, b; scanf("%d %d", &a, &b);
    DP[0] = 0;

    for(int i = 1; i <= N; ++i) {
        if (i - a >= 0) DP[i] = min(DP[i], DP[i - a] + 1);
        if (i - b >= 0) DP[i] = min(DP[i], DP[i - b] + 1);
    }

    if (DP[N] == INF) printf("-1\n");
    else printf("%d\n", DP[N]);
    return 0;
}