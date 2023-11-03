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

int N, M;
char buf[100][100];

void dfs1(int i, int j) {
    if (buf[i][j] != '-') return;
    buf[i][j] = 'X';
    dfs1(i, j + 1);
}
void dfs2(int i, int j) {
    if (buf[i][j] != '|') return;
    buf[i][j] = 'X';
    dfs2(i + 1, j);
}
void solve() {
    scanf("%d %d", &N, &M);
    FOR(i,1,N+1) {
        scanf("%s", &buf[i][1]);
    }
    int ans = 0;
    FOR(i,1,N+1) {
        FOR(j,1,M+1) {
            if (buf[i][j] == '-') dfs1(i, j), ++ans;
            if (buf[i][j] == '|') dfs2(i, j), ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();

    return 0;
}