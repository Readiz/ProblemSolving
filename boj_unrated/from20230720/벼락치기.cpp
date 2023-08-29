#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T; scanf("%d %d", &N, &T);
    vector<int> stime(N+1);
    vector<int> score(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d %d", &stime[i], &score[i]);

    // DP[i][j]: i 단원까지 공부했을 때 + j시간을 투자했을 때의 최대 점수
    int DP[100'001] = {0,};
    for(int i = 1; i <= N; ++i) {
        for(int j = 100'000; j >= stime[i];--j) {
            DP[j] = max(DP[j], DP[j-stime[i]] + score[i]);
        }
    }

    int maxScore = 0;
    for(int i = 0; i <= T; ++i) {
        if (DP[i] > maxScore) maxScore = DP[i];
    }
    printf("%d\n", maxScore);

    return 0;
}