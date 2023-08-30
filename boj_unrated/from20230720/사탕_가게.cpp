#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
double tmp;

void solve() {
    vector<int> cal(N+1);
    vector<int> cost(N+1);
    for(int i = 1; i <= N; ++i) {
        scanf("%d %lf", &cal[i], &tmp);
        cost[i] = tmp * 100.0 + 0.5;
    }

    // DP[i][j]: i번쨰 사탕까지 고려했을 떄 j 만큼 돈 썼을 때의 최대 칼로리
    ll DP[10001] = {0,};
    for(int i = 1; i <= N; ++i) {
        for(int j = cost[i]; j <= M; ++j) { // 여러개 살 수 있으므로 정방향
            DP[j] = max(DP[j], DP[j-cost[i]] + cal[i]);
        }
    }
    ll maxCal = 0;
    for(int i = 0; i <= M; ++i) {
        maxCal = max(maxCal, DP[i]);
    }
    printf("%lld\n", maxCal);
}

int main() {
    while (true) {
        scanf("%d %lf", &N, &tmp);
        M = tmp * 100.0 + 0.5;
        if (N == 0 && M == 0) break;
        solve();
    }
    return 0;
}