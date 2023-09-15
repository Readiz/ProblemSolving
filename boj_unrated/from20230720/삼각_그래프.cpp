#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, tc;
int A[100'000][3];
int DP[100'000][3];
int min3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}
void solve() {
    for(int i = 0; i < N; ++i) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        A[i][0] = a;
        A[i][1] = b;
        A[i][2] = c;
    }
    DP[1][0] = A[1][0] + A[0][1];
    DP[1][1] = A[1][1] + A[0][1] + (A[0][2] < 0 ? A[0][2] : 0);
    DP[1][2] = A[1][2] + A[0][1] + (A[0][2] < 0 ? A[0][2] : 0);

    DP[1][1] = min(DP[1][1], DP[1][0] + A[1][1]);
    DP[1][2] = min(DP[1][2], DP[1][1] + A[1][2]);
    for(int i = 2; i < N; ++i) {
        DP[i][0] = min(DP[i-1][0], DP[i-1][1]) + A[i][0];
        DP[i][1] = min3(DP[i-1][0], DP[i-1][1], DP[i-1][2]) + A[i][1];
        DP[i][2] = min(DP[i-1][1], DP[i-1][2]) + A[i][2];

        DP[i][1] = min(DP[i][1], DP[i][0] + A[i][1]);
        DP[i][2] = min(DP[i][2], DP[i][1] + A[i][2]);
    }
    printf("%d. %d\n", tc, DP[N-1][1]);
}
int main() {
    while(true) {
        scanf("%d", &N);
        if (N == 0) break;
        ++tc;
        solve();
    }
    return 0;
}