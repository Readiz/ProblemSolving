#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr int INF = 60000;
unsigned short DP[2][20'000'001];
int mmin(int a, int b) {
    return a < b? a: b;
}
int main() {
    int N, TM; scanf("%d %d", &N, &TM); // target memory
    vector<int> M(N+1);
    vector<int> C(N+1);
    int MS = 0;
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &M[i]);
        MS += M[i];
    }
    for(int i = 1; i <= N; ++i) scanf("%d", &C[i]);

    fill(DP[0], DP[1] + 20'000'001, INF); // 초기 비용 무한함
    DP[0][0] = 0;

    // M -> 메모리. 일종의 냅색의 W 역할
    // M 이상의 메모리를 확보해야하며, 그 동안 cost는 최소가 되어야 한다.
    for(int i = 1; i <= N; ++i) { // 냅색 루프 1. i 번째까지 쭉 본다.
        for(int m = MS; m >= M[i]; --m) {
            DP[i&1][m] = mmin(DP[1-(i&1)][m], DP[1-(i&1)][m - M[i]] + C[i]);
        }
    }
    int ans = INF;
    for(int i = TM; i <= MS; ++i) {
        ans = mmin(ans, DP[N&1][i]);
    }
    printf("%d\n", ans);

    return 0;
}