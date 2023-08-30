#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr int INF = 987654321;
void solve() {
    int N; scanf("%d", &N);
    vector<int> v(N+1);
    vector<int> S(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &v[i]);
    S[0] = 0;
    for(int i = 1; i <= N; ++i) S[i] = S[i-1] + v[i];
    // K^3 DP로 해결 가능
    // DP[i][j]: i~j 까지의 파일을 합치는데 드는 최소 비용 (초기값: INF)
    // 다음과 같이 일반적인 DP식을 세울 수 있다. (like 플로이드 워셜)
    // DP[i][j] = min{i<k<j}(DP[i][k]+DP[k][j]+S[i][j])
    int DP[101][101];
    fill((int*)DP, (int*)DP + 101*101, INF);
    for(int i = 0; i <= N; ++i) DP[i][i] = v[i];
    for(int i = 0; i < N; ++i) DP[i][i+1] = v[i] + v[i+1];

    // [s, e]
    for(int d = 2; d <= N-1; ++d) { // 거리가 작은 것부터 업데이트 해 나가야 한다.
        for(int s = 1; s <= N; ++s) {
            int e = s + d;
            if (e > N) break;
            printf("[d] checking %d ~ %d\n", s, e);
            for(int k = s; k < e; ++k) {
                DP[s][e] = min(DP[s][e], DP[s][k] + DP[k+1][e] + S[e] - S[s - 1]);
            }
            printf("[d] = %d\n", DP[s][e]);
        }
    }

    // 최종 비용은 DP[1][N] 에 당연히 존재한다.
    printf("%d\n", DP[1][N]);
}
int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}