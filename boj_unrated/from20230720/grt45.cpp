#include <bits/stdc++.h>
using namespace std;

char buf[100][100];
int N, K, Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt;
int visited[100][100];
int visitedCnt;
void dfs(int y, int x, char t, int mode) {
    if (buf[y][x] != t) return;
    if (visited[y][x] == visitedCnt) return;
    visited[y][x] = visitedCnt;
    // printf("[d] %d, %d\n", y, x);
    ++cnt;
    if (mode) buf[y][x] = '.';
    for(int k = 0; k < 4; ++k) {
        dfs(y + dy[k], x + dx[k], t, mode);
    }
}

int main() {
    scanf("%d%d%d", &N, &K, &Q);
    for(int i = 1; i <= N; ++i) scanf("%s", &buf[i][1]);
    for(int i = 0; i < Q; ++i) {
        int a, b; char s[2];
        scanf("%d %d %s", &a, &b, s);
        buf[a][b] = s[0];
        cnt = 0;
        ++visitedCnt;
        dfs(a, b, s[0], 0);
        if (cnt >= K) {
            ++visitedCnt;
            dfs(a, b, s[0], 1);
        }
    }
    for(int i = 1; i <= N; ++i) {
        printf("%s\n", &buf[i][1]);
    }   
    return 0;
}