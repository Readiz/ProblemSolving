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

int main() {
    int N, K; scanf("%d %d", &N, &K);
    vector<int> cost(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &cost[i]);
    ll DP[10001]; fill(DP, DP+10001, 0);
    // DP[i] : cost i에서의 경우의 수
    DP[0] = 1;
    for(int i = 1; i <= N; ++i) {
        for(int j = cost[i]; j <= 10000; j++) {
            DP[j] += DP[j - cost[i]];
        }
    }

    printf("%d\n", DP[K]);
    return 0;
}