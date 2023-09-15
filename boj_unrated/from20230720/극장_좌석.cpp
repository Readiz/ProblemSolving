#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, M; scanf("%d%d", &N, &M);
    bool cannotSeat[42] = {0, };
    for(int i = 0; i < M; ++i) {
        int tmp; scanf("%d", &tmp);
        cannotSeat[tmp] = 1;
    }
    cannotSeat[N + 1] = 1;

    int DP[41][2] = {0, };
    DP[1][0] = 1;

    for(int i = 2; i <= N; ++i) {
        DP[i][0] = DP[i-1][0] + DP[i-1][1];
        DP[i][1] = DP[i-1][0];
    }

    int PRECAL[41];
    for(int i = 1; i <= N; ++i) {
        PRECAL[i] = DP[i][0] + DP[i][1];
    }

    int ans = 1;
    int len = 0;
    for(int i = 1; i <= N + 1; ++i) {
        if (cannotSeat[i] == 0) {
            ++len;
        } else {
            if (len >= 1) ans *= PRECAL[len];
            len = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}