#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int min3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

char buf[1002][1002];
int DP[1002][1002];
int main() {
    int N, M; scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; ++i) {
        scanf("%s", &buf[i][1]);
    }
    int maxLen = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            int tmp = min3(DP[i-1][j-1], DP[i-1][j], DP[i][j-1]);
            if (buf[i][j] == '1') {
                DP[i][j] = tmp + 1;
                maxLen = max(maxLen, tmp + 1);
            }
        }
    }

    printf("%d\n", maxLen * maxLen);

    return 0;
}