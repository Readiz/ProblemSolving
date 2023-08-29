#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// DP[i]: i 코스트를 사용했을 때 가장 max로 확보할 수 있는 메모리 공간

int main() {
    int N, M; scanf("%d %d", &N, &M);
    vector<ll> A(N+1), C(N+1);
    for(int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
    for(int i = 1; i <= N; ++i) scanf("%lld", &C[i]);

    ll DP[101][10001] = {0,}; // i번째 친구가 cost j에서 최대한 확보할 수 있는 메모리 공간
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= 10000; ++j) {
            if (j - C[i] >= 0) {
                // i번째 앱을 죽이지 않았을 때 vs i번째 앱을 죽였을 때
                // 더 많은 메모리를 확보할 수 있는 것을 저장한다.
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-C[i]] + A[i]);
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    for(int i = 0; i <= 10000; ++i) {
        if (DP[N][i] >= M) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}