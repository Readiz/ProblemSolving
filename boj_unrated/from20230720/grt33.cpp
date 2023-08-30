#include <bits/stdc++.h>
using namespace std;

int M[1010][1010];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct P {
    int y, x;
};
P q[2000000];
int qf, qr;
int clear(int y, int x, int t) {
    int cnt = 0;
    qf = qr = 0;
    q[qr++] = {y, x};
    while(qf != qr) {
        auto& cur = q[qf++];
        if (M[cur.y][cur.x] != t) continue;
        M[cur.y][cur.x] = 0;
        ++cnt;
        for(int i = 0; i < 4; ++i) {
            if (M[cur.y + dy[i]][cur.x + dx[i]] == t)
                q[qr++] = {cur.y + dy[i], cur.x + dx[i]};
        }
    }
    return cnt;
}
int main() {
    int N, K; scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &M[i][j]);
        }
    }

    map<int,int> data;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (M[i][j]) {
                int t = M[i][j];
                int cnt = clear(i, j, t);
                if (cnt >= K) {
                    if (data.find(t) == data.end()) data[t] = 1;
                    else data[t]++;
                }
            }
        }
    }
    priority_queue<pair<int,int>> PQ;
    for(auto& item:data) {
        PQ.push({item.second, item.first});
    }
    printf("%d\n", PQ.top().second);
    return 0;
}