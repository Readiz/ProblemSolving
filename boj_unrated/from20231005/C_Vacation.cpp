#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int act[3][100010];
ll DP[3][100010]; // j 활동을 했을 때의 최대 행복을 저장
int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        for(int j = 0; j < 3; ++j)
            scanf("%d", &act[j][i]);
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < 3; ++j) {
            DP[j][i] = max(DP[(j+1)%3][i-1], DP[(j+2)%3][i-1]) + act[j][i];
            // printf("DP[%d][%d] = %lld\n", j, i, DP[j][i]);
        }
    }
    
    ll ans = max(max(DP[0][N], DP[1][N]), DP[2][N]);
    printf("%lld\n", ans);

    return 0;
}