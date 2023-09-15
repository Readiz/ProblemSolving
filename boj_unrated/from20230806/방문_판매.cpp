#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int x, y;
};
int DP[5001][5001];
int main() {
    int N, X, Y; scanf("%d %d %d", &N, &X, &Y);
    vector<Customer> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d %d", &v[i].x, &v[i].y);

    memset(DP, 0x3A, 5001 * 5001 * sizeof(int));
    DP[0][0] = 0;
    int ans = 0x3A3A3A3A;
    int ansVal = -1;
    for(int i = 1; i <= N; ++i) {
        // i번째까지 방문헀을 때의 상태
        for(int tx = X+100; tx >= v[i].x; --tx) {
            for(int ty = Y+100; ty >= v[i].y; --ty) {
                DP[tx][ty] = min(DP[tx][ty], DP[tx - v[i].x][ty - v[i].y] + 1);
                if (tx >= X && ty >= Y && DP[tx][ty] < ans) {
                    ans = DP[tx][ty];
                    ansVal = i;
                }
            }
        }
    }

    if (ans == 0x3A3A3A3A) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
        printf("%d\n", ansVal);
    }

    return 0;
}