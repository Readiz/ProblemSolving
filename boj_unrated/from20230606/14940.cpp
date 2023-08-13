#include <bits/stdc++.h>
using namespace std;

int MAP[1000][1000];
int visited[1000][1000];
int res[1000][1000];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
struct Data {
    int y, x, d;
};
int main() {
    int N, M; scanf("%d %d", &N, &M);
    queue<Data> q;
    for(int i = 0; i < N; ++i) for(int j = 0; j < M; ++j) res[i][j] = -1;
    for(int i = 0; i < N; ++i) for(int j = 0; j < M; ++j) {
        scanf("%d", &MAP[i][j]);
        if (MAP[i][j] == 2) {
            q.push({i,j,0}); 
            visited[i][j] = 1;
        }
        else if (MAP[i][j] == 0) {
            visited[i][j] = 1;
            res[i][j] = 0;
        }
    }

    while(q.size()) {
        Data c = q.front(); q.pop();
        res[c.y][c.x] = c.d;

        for(int i = 0; i < 4; ++i) {
            int ny = dy[i] + c.y;
            int nx = dx[i] + c.x;
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.push({ny,nx,c.d+1});
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}