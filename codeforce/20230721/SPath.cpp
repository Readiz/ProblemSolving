#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

int R, C;
int M[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[100][100];
int visitedCnt;
void solve() {
    scanf("%d %d", &R, &C);
    FOR(r,1,R+1) {
        FOR(c,1,C+1) {
            scanf("%d", &M[r][c]);
        }
    }
    ++visitedCnt;
    queue<pair<pair<int,int>,int>> Q;
    Q.push({{1,1}, 0});
    while(Q.size()) {
        auto c = Q.front(); Q.pop();
        if (M[c.first.first][c.first.second] == 0) continue;
        if (visited[c.first.first][c.first.second] == visitedCnt) continue;
        visited[c.first.first][c.first.second] = visitedCnt;
        if (c.first.first == R && c.first.second == C) {
            printf("%d\n", c.second);
            return;
        }
        for(int i = 0; i < 4; ++i) {
            Q.push({{c.first.first + dy[i], c.first.second + dx[i]}, c.second + 1});
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        printf("#%d ", TC + 1);
        solve();
    }
}