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
    vector<int> C(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &C[i]);
    ll DP[100001]; fill(DP, DP+100001, INF);
    // DP[i]: 카페인이 i만큼 있을 때 마신 최소의 커피잔 수
    DP[0] = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 100000; j >= C[i]; j--) {
            DP[j] = min(DP[j], DP[j-C[i]] + 1);
        }
    }

    if (DP[K] == INF) printf("-1\n");
    else printf("%lld\n", DP[K]);
    return 0;
}