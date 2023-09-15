#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ODP[2'000'001][4];
int E[4];
int main() {
    int A, B, C, K; scanf("%d%d%d%d", &A, &B, &C, &K);
    E[1] = B;
    E[2] = C;
    E[3] = A;
    memset(ODP, 0x3A, sizeof(int) * 8'000'004);
    int (*DP)[4];
    DP = &ODP[1'000'000];

    DP[0][0] = 0; // 에너지 K를 소비했을 때.. 최소 이동 횟수. 0: 정방향
    for(int j = 0; j <= K; ++j) {
        for(int i = 0; i < 4; ++i) {
            DP[j][i] = min(DP[j][i], DP[j-A][(i+3)%4] + 1); // 좌로 돌아 결과
            DP[j][i] = min(DP[j][i], DP[j-B][(i+1)%4] + 1); // 우로 돌아 결과
            DP[j][i] = min(DP[j][i], DP[j-C][(i+2)%4] + 1); // 뒤로 돌아 결과
        }
    }
    
    if (DP[K][0] != 0x3A3A3A3A) {
        printf("%d\n", DP[K][0]);
    } else {
        printf("-1\n");
    }

    return 0;
}