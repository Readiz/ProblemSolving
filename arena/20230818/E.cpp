#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll DP[33][200010]; // 그 지점에서의 최대값임 / 최대 32개 까지 저장.

#define _D(...) printf(__VA_ARGS__)

int main() {
    int N; vector<ll> v;
    scanf("%d", &N); v.resize(N + 1);
    v[0] = 0;
    for(int i = 1; i <= N; ++i) scanf("%lld", &v[i]);

    DP[1][1] = v[1]; // 1개 숫자를 써서 초기화!
    for(int i = 2; i <= N; ++i) {
        if (i > 32) break;
        DP[i][i] = DP[i-1][i-1] ^ v[i];
    }
    for(int i = 2; i <= N; ++i) {
        for(int k = 1; k <= 32; ++k) {
            if (i - k < 0) break;

            // k개 이전의 xor을 구한다.
            ll cur = 0;
            for(int p = 0; p < k; ++p) {
                cur ^= v[i - p];
            }

            for(int pre = 1; pre <= 32; ++pre) {
                if (k == pre) continue; // 같은 구간개수는 안됨~
                if (i - k < 0) continue;
                if (DP[pre][i - k] == 0) continue;
                if (DP[pre][i - k] + cur > DP[k][i]) {
                    DP[k][i] = DP[pre][i - k] + cur;
                    // _D("DP[%d][%d]: %lld (DP[%d][%d] = %d)\n", k, i, DP[k][i], pre, i - k, DP[pre][i-k]);
                }
            }
        }
    }    

    ll ans = 0;
    for(int i = 1; i <= 32; ++i) ans = max(ans, DP[i][N]);
    printf("%lld\n", ans);
    return 0;
}