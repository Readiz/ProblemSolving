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

int H, W;
char buf[1010][1010];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int i, int j) {
    if (buf[i][j] != '#') return;
    buf[i][j] = 0;
    FOR(k,0,8) {
        dfs(i + dy[k], j + dx[k]);
    }
}

void solve() {
    scanf("%d %d", &H, &W);
    FOR(i,1,H+1) {
        scanf("%s", &buf[i][1]);
    }
    int ans = 0;
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            if (buf[i][j] == '#') {
                dfs(i, j);
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();

    return 0;
}