#include <bits/stdc++.h>
using namespace std;

int b[101][101];
int d;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct Point {
    int r, c;
};

deque<Point> snake;

int X[10010]; // 1, -1

int main() {
    int N, K; scanf("%d %d", &N, &K);

    for(int i = 0; i <= N + 1; ++i) {
        b[0][i] = 1;
        b[N+1][i] = 1;
        b[i][0] = 1;
        b[i][N+1] = 1;
    }

    for(int k = 0; k < K; ++k) {
        int r, c; scanf("%d %d", &r, &c);
        b[r][c] = 2;
    }
    int L; scanf("%d", &L);
    for(int l = 0; l < L; ++l) {
        char buf[2]; int time; scanf("%d %s", &time, buf);
        if (buf[0] == 'L') X[time] = 3;
        else X[time] = 1;
    }

    snake.push_back({1, 1});

    for(int t = 1; ; ++t) {
        auto cur = snake.back();
        cur.r += dr[d];
        cur.c += dc[d];


        for(auto& me: snake) {
            if (me.r == cur.r && me.c == cur.c) {
                printf("%d\n", t);
                return 0;
            }
        }
        if (b[cur.r][cur.c] == 2) {
            // nothing to do (길이 증가)
            b[cur.r][cur.c] = 0; // 사과먹었다.
        } else if (b[cur.r][cur.c] == 1) {
            printf("%d\n", t);
            return 0;
        } else {
            // 맨 뒤 하나 줄인다.
            snake.pop_front();
        }
        snake.push_back({cur.r, cur.c});

        if (X[t] != 0) {
            d += X[t];
            d %= 4;
        }
    }

    printf("ERR!\n");
    return 0;
}