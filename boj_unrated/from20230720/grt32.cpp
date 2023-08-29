#include <stdio.h>

int M[1010][1010];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct P {
    int y, x;
};
P q[2000000];
int qf, qr;
void clear(int y, int x) {
    qf = qr = 0;
    q[qr++] = {y, x};
    while(qf != qr) {
        auto& cur = q[qf++];
        if (M[cur.y][cur.x] == 0) continue;
        M[cur.y][cur.x] = 0;
        for(int i = 0; i < 4; ++i) {
            if (M[cur.y + dy[i]][cur.x + dx[i]] == 1)
                q[qr++] = {cur.y + dy[i], cur.x + dx[i]};
        }
    }
}
int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &M[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (M[i][j]) {
                clear(i, j);
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}