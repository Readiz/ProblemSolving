#include <bits/stdc++.h>
using namespace std;

int b[25][25];

int sr, sc;
int ss = 2;
int se = 0; // 먹이 먹은 수. 2가 되면 최초 진화

struct Data {
    int dist;
    int r;
    int c;
    bool operator<(const Data& t) const {
        if (dist != t.dist) return dist > t.dist;
        if (r != t.r) return r > t.r;
        return c > t.c;
    }
};

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

Data check() {
    int visited[25][25] = {0, };
    priority_queue<Data> pq;
    pq.push({0, sr, sc});
    priority_queue<Data> ret;
    while (pq.size()) {
        auto cur = pq.top(); pq.pop();

        if (visited[cur.r][cur.c]) continue;
        visited[cur.r][cur.c] = 1;

        if (b[cur.r][cur.c] != 0 && b[cur.r][cur.c] < ss) {
            ret.push(cur);
        }

        for(int p = 0; p < 4; ++p) {
            int nr = cur.r + dr[p];
            int nc = cur.c + dc[p];
            if (b[nr][nc] > ss) continue;

            pq.push({cur.dist + 1, nr, nc});
        }
    }

    if (ret.size()) {
        return ret.top();
    }
    return {-1, -1, -1};
}



int main() {
    int N; scanf("%d", &N);

    for(int i = 0; i <= N+1; ++i) {
        b[0][i] = 100;
        b[i][0] = 100;
        b[i][N+1] = 100;
        b[N+1][i] = 100;
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            int t; scanf("%d", &t);
            if (t != 9) b[i][j] = t;
            else {
                sr = i, sc = j;
            }
        }
    }

    int ans = 0;
    while(true) {
        Data c = check();
        if (c.dist == -1) break;

        // printf("[d] eat %d, %d\n", c.r, c.c);

        ans += c.dist;
        b[c.r][c.c] = 0;
        se++;
        if (se == ss) {
            se = 0;
            ++ss;
        }
        sr = c.r;
        sc = c.c;

    }

    printf("%d\n", ans);

    return 0;
}