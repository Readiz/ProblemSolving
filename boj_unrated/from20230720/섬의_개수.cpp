#include <stdio.h>

int N, M;
int visited[52][52];
int map[52][52];

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

struct P {
    int x, y;
};
P q[100000];
int qf, qr;

void dfs(int x, int y) {
    if (visited[y][x]) return;
    visited[y][x] = 1;
    for(int i = 0; i < 8; ++i) {
        if (map[y + dy[i]][x + dx[i]] == 1)
            dfs(x + dx[i], y + dy[i]);
    }
}
void solve() {
    for(int i = 0; i <= M+1; ++i) {
        for(int j = 0; j <= N+1; ++j) {
            visited[i][j] = 1;
            map[i][j] = 0;
        }
    }
    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &map[i][j]); // 1: 땅
            visited[i][j] = 0;
        }
    }
    qf = qr = 0;
    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (map[i][j] == 1) q[qr++] = {j, i};
        }
    }
    int cnt = 0;
    while(qf != qr) {
        P& cp = q[qf++];
        if (visited[cp.y][cp.x]) continue;

        ++cnt;
        dfs(cp.x, cp.y);
    }
    printf("%d\n", cnt);
}
int main() {
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        solve();
    }

    return 0;
}