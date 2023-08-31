#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

constexpr ll INF = 1LL << 32;
int main() {
    int N, K; scanf("%d %d", &N, &K);
    vector<int> cost(1);
    set<int> checker;
    for(int i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (checker.find(tmp) == checker.end()) {
            cost.push_back(tmp);
            checker.insert(tmp);
        }
    }
    ll DP[10001]; fill(DP, DP+10001, INF);
    // DP[i] : cost i에서의 최소 동전 수
    DP[0] = 0;
    for(int i = 1; i < cost.size(); ++i) {
        for(int j = cost[i]; j <= 10000; j++) {
            DP[j] = min(DP[j], DP[j - cost[i]] + 1);
        }
    }

    if (DP[K] == INF) printf("-1\n");
    else printf("%d\n", DP[K]);
    return 0;
}