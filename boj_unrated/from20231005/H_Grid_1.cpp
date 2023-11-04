#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif
#define X first
#define Y second

int H, W;
char M[1010][1010];
int DP[1010][1010];
void solve() {
    scanf("%d %d", &H, &W);
    for(int i = 1; i <= H; ++i) {
        scanf("%s", &M[i][1]);
    }
    DP[1][1] = 1;
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            if (i == 1 && j == 1) continue;
            if (M[i][j] == '#') {
                DP[i][j] = 0;
                continue;
            }
            DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
            DP[i][j] %= 1'000'000'007;
        }
    }
    printf("%d\n", DP[H][W]);
}

int main() {
    solve();
    return 0;
}