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
    int TT, N; scanf("%d %d", &TT, &N);
    vector<int> I(N+1);
    vector<int> T(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d %d", &I[i], &T[i]);
    ll DP[10001]; fill(DP, DP+10001, 0);
    // DP[i]: 공부시간 i에서의 최대 중요도
    for(int i = 1; i <= N; ++i) {
        for(int j = 10000; j >= T[i]; j--) {
            DP[j] = max(DP[j], DP[j - T[i]] + I[i]);
        }
    }

    ll maxImportance = 0;
    for(int j = 0; j <= TT; ++j) {
        maxImportance = max(maxImportance, DP[j]);
    }
    printf("%lld\n", maxImportance);
    return 0;
}