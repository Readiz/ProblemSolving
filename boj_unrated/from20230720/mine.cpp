#include <stdio.h>

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int map[1002][1002];
int main() {
    int N, K; scanf("%d %d", &N, &K);
    for(int y = 1; y <= N; ++y) {
        for(int x = 1; x <= N; ++x) {
            scanf("%d", &map[y][x]);
        }
    }
    int ans = 0;
    for(int y = 1; y <= N; ++y) {
        for(int x = 1; x <= N; ++x) {
            if (map[y][x] == 0) {
                int ck = 0;
                for(int k = 0; k < 8; ++k) {
                    if (map[y + dy[k]][x + dx[k]] == 1) ++ck;
                }
                if (ck == K) ++ans;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}