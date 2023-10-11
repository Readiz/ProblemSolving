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

int N, M;
void solve() {
    scanf("%d %d", &N, &M);
    int unit[301] = {0, };
    int unitMax[301] = {0, };
    FOR(i,0,N) {
        int n; scanf("%d", &n); // n unit을 어느 기업에 쓰는게 효율적?
        int maxVal = 0;
        int maxIdx = -1;
        for(int j = 1; j <= M; ++j) {
            int k; scanf("%d", &k);
            if (k > maxVal) {
                maxVal = k;
                maxIdx = j;
            }
        }
        unit[n] = maxVal;
        unitMax[n] = maxIdx;
    }
    for(int i = 1; i <= N; ++i) {
        _D("max %d: %d / t: %d\n", i, unit[i], unitMax[i]);
    }
    int DP[301] = {0, }; // j 원을 투자했을 때 얻게 되는 가장 max의 투자 방식
    int from[301] = {0, }; // j 원의 max를 갱신할 때 같이 갱신하는 vector, 누구 누구를 합했는지 기록
    for(int i = 1; i <= N; ++i) {
        for(int j = N; j >= i; j--) {
            int newVal = DP[j - i] + unit[i];
            if (newVal > DP[j]) {
                DP[j] = newVal;
                from[j] = i;
            }
        }
    }
    int maxVal = 0;
    int maxIdx = -1;
    for(int i = 1; i <= N; ++i) {
        if (DP[i] > maxVal) {
            maxVal = DP[i];
            maxIdx = i;
        }
    }
    int ans[21] = {0, };
    int cur = maxIdx;
    _D("maxIdx: %d\n", maxIdx);
    for(int i = 0; i <= maxIdx; ++i) {
        _D("from[%d] = %d\n", i, from[i]);
    }
    while(cur != -1 && cur != 0 && from[cur] != 0) {
        int i = from[cur];
        ans[unitMax[i]] += i;
        cur = cur - i;
    }
    printf("%d\n", maxVal);
    for(int i = 1; i <= M; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}